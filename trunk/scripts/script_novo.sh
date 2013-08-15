#!/bin/bash
  
  #script para o corporativo (faz rollback ) oi para telemig codigo da area 95 

  #IFS=: #determina o separador 

  string="update phone_range set carrier_id = 9  where " 
  echo $string
 
  iLinhas=`wc -l arquivo.txt | cut -d " "  -f1`
  iAtual=1
  #echo "numero de linhas $iLinhas" 


  while read carrier_id area_code start_range end_range;do

  	#echo "carrier_id:      $carrier_id"
  	#echo "area_code:       $area_code"
  	#echo "start_range:     $start_range"
  	#echo "end_range:       $end_range"

	#echo "numero de linhas $iLinhas" 
	#echo "linha atual $iAtual" 

        if [ $iAtual -lt $iLinhas ] ; then
           string=${string}" ( start_range='"$start_range"' and end_range='"$end_range"' ) or "
	else
	   string=${string}" ( start_range='"$start_range"' and end_range='"$end_range"' )  "
	fi
  
  	#[ "$?" = "0" ] && echo "Operacao OK" || echo "Operação: ERRO"

	iAtual=`expr $iAtual + 1 `

  done < arquivo.txt
  
  string=${string}" and ( carrier_id=2 and area_code=95 ) ; " 

  echo "query a ser executada: [$string] " 

  mysql -hlocalhost -uroot -B numbering -e "$string"


  if [ "$?" = "0" ] ; then
	echo "Query de rollback executada com sucesso."
  else
	echo "Erro ao executar query."
  fi  







