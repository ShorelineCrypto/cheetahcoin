#! /bin/bash

   cd /usr/local/opt
     rm openssl
     ln -s ../Cellar/openssl@1.0/1.0.2t openssl

  cd /usr/local/opt
   rm miniupnpc 
   ln -s ../Cellar/miniupnpc/1.9 miniupnpc 

   openssl version
