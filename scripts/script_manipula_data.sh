#!/bin/bash 


data="20090810"

date   --date=' 20090810  1 day ago ' +%d%m%Y

date   --date=" $data 1 day ago " +%d%m%Y 

#data do dia seguinte

data=`date --date=" $data 3 day " +%Y%m%d `

echo $data

date   --date=" $data 1 day ago " +%d%m%Y 


