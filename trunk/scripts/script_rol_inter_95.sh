#!/bin/bash
  
  #script para o interativo (faz rollback ) oi para telemig codigo da area 95 

  #IFS=: #determina o separador 

  #configurar o nome do arquivo com os ranges que foram atualizados  
  arquivo="arquivo_iter_04_95.txt "

  string="update phone_range set carrier_id = 8  where " 

  iLinhas=`wc -l $arquivo | cut -d " "  -f1`
  iAtual=1

  while read carrier_id area_code start_range end_range;do

        if [ $iAtual -lt $iLinhas ] ; then
           string=${string}" ( start_range='"$start_range"' and end_range='"$end_range"' ) or "
	else
	   string=${string}" ( start_range='"$start_range"' and end_range='"$end_range"' )  "
	fi
  
	iAtual=`expr $iAtual + 1 `

  done < $arquivo

  if [ $iLinhas -eq 0 ] ; then 
     echo "Imbecil nao a nada para atualizar."
     exit
  fi

  string=${string}" and ( carrier_id=4 and area_code=95 ) ; " 

  echo "query a ser executada: [$string] " 

  mysql -hlocalhost -uroot -B numbering -e "$string"


  if [ "$?" = "0" ] ; then
	echo "Query de rollback executada com sucesso."
  else
	echo "Erro ao executar query."
  fi  





