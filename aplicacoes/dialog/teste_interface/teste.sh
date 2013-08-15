#!/bin/bash

# $1 passar warning
# $2 passar timestamp

nivel=$( dialog --stdout  --title 'Configuracoes' --inputbox 'Nivel de debug:' 0 0 )
echo $nivel

arquivo=$( dialog --stdout  --title 'Configuracoes' --inputbox 'Gera arquivo:' 0 0 )
echo $arquivo

# chama script para teste
./script_alterado_para_teste.sh  "$nivel" "$arquivo"



