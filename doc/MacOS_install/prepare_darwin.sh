#! /bin/bash

  brew install gcc@5
  brew install miniupnpc openssl berkeley-db4

  wget http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.9.20150206.tar.gz
  tar xvfz "download.php?file=miniupnpc-1.9.20150206.tar.gz"  
  rm -rf  /usr/local/Cellar/miniupnpc/1.9
  mv miniupnpc-1.9.20150206  /usr/local/Cellar/miniupnpc/1.9
  cd /usr/local/Cellar/miniupnpc/1.9
  make upnpc-static
  cd /usr/local/opt
  rm miniupnpc 
  ln -s ../Cellar/miniupnpc/1.9 miniupnpc 

  wget https://github.com/ShorelineCrypto/nengcoin/releases/download/v1.5.0.0/boost_1.55.0_osx10.11.tgz
   tar xvfz  boost_1.55.0_osx10.11.tgz
   mkdir -p /usr/local/Cellar/boost@1.55/1.55.0_1
   rm -rf  /usr/local/Cellar/boost@1.55/1.55.0_1
   mv 1.55.0_1 /usr/local/Cellar/boost@1.55/
   cd /usr/local/opt
   rm boost@1.55
   ln -s ../Cellar/boost@1.55/1.55.0_1 boost@1.55
    
  brew tap cartr/qt4
  brew install qt@4

## Step 4:  Switch openssl version 1.1 to 1.0
## https://stackoverflow.com/questions/59006602/dyld-library-not-loaded-usr-local-opt-openssl-lib-libssl-1-0-0-dylib

  brew install openssl@1.0
  cd /usr/local/opt
  rm openssl
  ln -s ../Cellar/openssl@1.0/1.0.2t openssl
   
## Download GUI/CLI wallet
cd ~/Downloads
wget https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v1.9.1.0/cheetahcoin_v1.9.1.0_macOS_GUI.dmg
wget https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v1.9.1.0/cheetahcoin_v1.9.1.0_macOS_CLI.zip
