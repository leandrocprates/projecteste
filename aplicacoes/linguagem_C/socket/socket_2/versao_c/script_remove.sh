#!/bin/bash

ls -ltr  |  cut -c50-60  |  awk ' {  if (  $1  !~ /.c$/  && $1 !~ /Makefile/  &&  $1  !~ /script/  ) {  print   $1 }   }   ' | xargs  rm  $1




