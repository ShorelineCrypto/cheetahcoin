#! /bin/bash

if (test $# != 1) 
then
 echo "trunc_log.sh  <yes|Y>" 
 exit
fi


# truncate useless full node log file hourly

for dir in  cheetahcoin  
do
     truncate -s 0 ~/.${dir}/debug.log
done


