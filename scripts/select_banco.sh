#!/bin/bash

#pega ultimo registro de arquivo processado e soma 24 horas
set `mysql -hlocalhost -u***** -p***** -B ***** -e "SELECT DATE_FORMAT( DATE_ADD( substr( file_name , 4 , 14 ) , INTERVAL 1 DAY) , '%Y%m%d%H%i%S' )  FROM file order by file_name desc LIMIT 1 " | tail -n +2` ; IDENT=$1 ;

#compara com a data atual 
compar_date=`date +%Y%m%d%H%M%S`

echo "data obtida do banco $IDENT" 
echo "se data obtida for menor que esta data : $compar_date"

#se for maior que a data atual ja faz 24 horas que nao se processa nenhum arquivo 
#alarme 

if [ $IDENT -lt $compar_date ] ; then 
    echo "Ja faz mais de 24 horas que nao se processa nada, alarme." 
else
    echo "Ainda na faz dez horas para alarmar nada." 
fi




