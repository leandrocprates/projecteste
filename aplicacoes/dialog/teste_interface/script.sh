#!/bin/bash

for file in ${HOME}/binn/GK/{gkgoogled.properties,gkind.properties,gkoutd.properties} ; do
    [ -f ${file} ] && {
        echo ":: Salva Backup do arquivo";
        cp -v ${file} ${file}.${1};

        echo ":: modifica arquivo de propriedades";
        cat ${file}.${1} | awk '
/logging.loggers.root.level/ {
    print "logging.loggers.root.level = warning";
}
/logging.channels.c1.archive/ {
    print "logging.channels.c1.archive = timestamp";
}
!/logging.loggers.root.level/ && !/logging.channels.c1.archive/
        '> ${file};

        echo ":: Compara arquivos modificados";
        sdiff -s ${file} ${file}.${1};
    }
done

[ -f .prl ] && rm -rf .prl;
