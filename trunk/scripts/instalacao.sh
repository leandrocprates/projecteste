#!/bin/bash
  
  #script para o corporativo (faz atualizacao ) telemig  para oi  (codigo da area) = 95 (carrier_id) = 2 

  #faz a copia para um arquivo dos ranges que serao atualizados
  mysql -hlocalhost -uroot -B numbering -e "SELECT * FROM phone_range where carrier_id=9 and area_code=95  " > teste.txt

  #pega a partir da segunda linha (tira o cabecalho): 
  tail --lines=+2 teste.txt > arquivo_corp_02_95.txt 

  #atribui operadora oi para telefones da telemig onde codigo da area e (95) ;
  string="update phone_range set carrier_id = 2  where carrier_id=9 and area_code=95 ;"
  echo "query a ser executada: [$string] " 

  mysql -hlocalhost -uroot -B numbering -e "$string"

  if [ "$?" = "0" ] ; then
	echo "Query de atualizacao executada com sucesso."
  else
	echo "Erro ao executar query."
  fi  




