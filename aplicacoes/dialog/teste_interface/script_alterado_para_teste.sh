#!/bin/bash

# $1 mandar warning 
# $2 mandar timestamp

echo $1
echo $2

for file in ${HOME}/binn/GK/{gkgoogled.properties,gkind.properties,gkoutd.properties} ; do
    [ -f ${file} ] && {
        echo ":: Salva Backup do arquivo";
        cp -v ${file} ${file}.${1};

        echo ":: modifica arquivo de propriedades ";
        cat ${file}.${1} | awk '
/logging.loggers.root.level/ {
    print "logging.loggers.root.level = '$1'";
}
/logging.channels.c1.archive/ {
    print "logging.channels.c1.archive = '$2'";
}
!/logging.loggers.root.level/ && !/logging.channels.c1.archive/
        '> ${file};

        echo ":: Compara arquivos modificados";
        sdiff -s ${file} ${file}.${1};
    }
done

[ -f .prl ] && rm -rf .prl;


