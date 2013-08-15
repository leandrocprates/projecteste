#!/bin/sh


numero=$#
nome_bin=arquivo.txt
dir_bin=/home/Leandro/scripts/implantacao/teste/bin

string=($*) #armazena valores passados  em array

if [ $1 = "--compactar" ] ; then 

	if [ $numero -lt 2 ] ; then
	   echo "Nenhuma acao sera tomada numero de parametros invalidos."
	   exit
	fi

	echo "Acao de compactar."

    i=1
	while [ $i -lt $numero ]  
	do
		string2=${string2}" "${string[i]} 
		i=`expr $i + 1 `
	done 

	echo "string 2: " $string2

#	string3="tar -cvf backup_"$nome_bin"_"$( date +%Y%m%d_%H%M%S )".tar" 
#	exec $string3 "${string[1]}" "${string[2]}"
#	string3="tar -cvf backup_"$nome_bin"_"$( date +%Y%m%d_%H%M%S )".tar  "${string[1]}" "${string[2]}" "  

	string3="tar -cvf backup_"$nome_bin"_"$( date +%Y%m%d_%H%M%S )".tar "${string2}" "  
	exec $string3 
	
elif [ $1 = "--instalar" ] ; then
	echo "Acao de instalar."
	cp $nome_bin   $dir_bin
elif [ $1 = "--rollback" ] ; then
	echo "Acao de rolback."
else
	echo "Acao invalida."
	exit
fi

