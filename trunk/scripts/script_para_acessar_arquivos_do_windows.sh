#!/bin/bash


# a pasta windows deve ser criada para depois executar o script

# carrega os dados do windows na pasta "/media/windows/"

sudo mount /dev/sda1 /media/windows/ -t ntfs -o umask=0222


