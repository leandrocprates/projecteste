#!/bin/sh

dir=$1

echo "diretorio dos arquivos convertidos: $dir"  >> /tmp/teste_portabilidade.txt

find $dir -name "BDT*" | xargs dos2unix

