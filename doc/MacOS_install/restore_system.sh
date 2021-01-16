#! /bin/bash

   brew link openssl@1.1

   cd /usr/local/opt
   rm miniupnpc 
   ln -s ../Cellar/miniupnpc/2.1 miniupnpc 

   openssl version 
