# Mac OS X cheetahcoind build instructions
====================================

Authors
-------

* Laszlo Hanyecz <solar@heliacal.net>
* Douglas Huff <dhuff@jrbobdobbs.org>
* Colin Dean <cad@cad.cx>
* Gavin Andresen <gavinandresen@gmail.com>
* Hong Lu <DISCORD/Bitcointalk/Reddit Forum ID: honglu69>

License
-------

Copyright (c) 2009-2012 Bitcoin Developers
Copyright (c) 2018-2021 Nengcoin Developers
Copyright (c) 2021 Cheetahcoin Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.

This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).

This product includes cryptographic software written by
Eric Young (eay@cryptsoft.com) and UPnP software written by Thomas Bernard.

Notes
-----

# macOS 10.15 (Catalina) - Supported on Binary only

macOS Catalina was also tested but failed to build from source.  However, Catalina is supported on binary wallet. Please 
check out CHTA v1.4.1.0 for MacOS Catalina wallet. 

# MacOS 10.11 (El Capitan) to MacOS 10.14 (Mojave) - Fully Supported


Tested on OS X 10.11 (El Capitan)/ macOS 10.14.4 (Mojave) on Intel processors only.  The binary wallet release was compiled on Mojave. However the compilation method below should work for any version between 10.11 to 10.14.

All of the commands should be executed in a Terminal application. The
built-in one is located in `/Applications/Utilities`.

## Preparation in OSX 10.11
-----------

Type below in terminal to install Xcode command line tools:
   ` xcode-select --install`

Open up browser such as firefox,  register for an apple developer
account and search web and download Xcode version 7.3.1.  Install dmg
file into Application of your Mac.

In below compiling steps in brew, there migh be warning that Xcode 7.3.1 is outdated, please upgrade to Xcode 8.x.x , ignore that. 

## Preparation in macOS 10.14

Type below in terminal to install Xcode command line tools:
   ` xcode-select --install`

## Required Package and Library for both OSX 10.11 and macOS 10.14

Perform below command line steps within terminal

#### Install HomeBrew

Follow brew:
https://brew.sh/

Homebrew version 2.7.0 was major change in that several features of CHTA core wallet installation on macOS no longer works. 
(1) boost@1.55 was deleted from repository
(2) brew switch is changed to brew link, which itself has limited feature by disabling many cases.
Below is workaround to fix Homebrew post v2.7.0 version installation for CHTA macOS wallet. 

----------------------

#### Install dependencies using Homebrew

```
        brew install wget
        brew install gcc@5
        brew install miniupnpc openssl berkeley-db4
        
```

####  Switch openssl to older version,

openssl default installation  is now version 1.1, incompatible with CHTA.

 A workaround solution from
 https://stackoverflow.com/questions/59006602/dyld-library-not-loaded-usr-local-opt-openssl-lib-libssl-1-0-0-dylib
 
 post homebrew v2.7.0 equivalent

```    
     brew install openssl@1.0
     cd /usr/local/opt
     rm openssl
     ln -s ../Cellar/openssl@1.0/1.0.2t openssl
    
```


Note: After you have installed the dependencies, you should check that the Brew installed version of OpenSSL is the one available for compilation. You can check this by typing
```
        openssl version
```
into Terminal. You should see  "OpenSSL 1.0.2t  10 Sep 2019".

If not, you can ensure that the Brew OpenSSL is correctly linked by running

```
       brew link openssl --force
```

Rerunning "openssl version" should now return the correct version.

Above step may not work for macOS El Capitan or Mojave, insert below into ~/.bash_profile  file
and reboot the machine.


```
export PATH="/usr/local/Cellar/gcc@5/5.5.0_6/bin:/Library/Developer/CommandLineTools/usr/bin:/usr/local/opt/openssl/bin:$PATH"
export LDFLAGS="-L/usr/local/opt/openssl/lib"
export CPPFLAGS="-I/usr/local/opt/openssl/include"
```


#### Install Qt4.8  with below commands

```
    brew tap cartr/qt4
    brew install qt@4
```


#### Install miniupnpc-1.9.20150206

miniupnpc 2.1 is default, which is incompatible with CHTA.

```
   wget http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.9.20150206.tar.gz
   tar xvfz "download.php?file=miniupnpc-1.9.20150206.tar.gz"  
   rm -rf  /usr/local/Cellar/miniupnpc/1.9
   mv miniupnpc-1.9.20150206  /usr/local/Cellar/miniupnpc/1.9
   cd /usr/local/Cellar/miniupnpc/1.9
   make upnpc-static
   cd /usr/local/opt
   rm miniupnpc 
   ln -s ../Cellar/miniupnpc/1.9 miniupnpc 
```

#### Install boost@1.55

```
   wget https://github.com/ShorelineCrypto/nengcoin/releases/download/v1.5.0.0/boost_1.55.0_osx10.11.tgz
   tar xvfz  boost_1.55.0_osx10.11.tgz
   mkdir -p /usr/local/Cellar/boost@1.55/1.55.0_1
   rm -rf  /usr/local/Cellar/boost@1.55/1.55.0_1
   mv 1.55.0_1 /usr/local/Cellar/boost@1.55/
   cd /usr/local/opt
   rm boost@1.55
   ln -s ../Cellar/boost@1.55/1.55.0_1 boost@1.55
```

##  for both MacOS Mojave or El Capitan
### Building command line  and QT wallet

1. Clone the github tree to get the source code and go into the
   directory.

```
   git clone  https://github.com/ShorelineCrypto/cheetahcoin.git
   cd cheetahcoin/src
   make -f makefile.osx USE_UPNP=1
   strip cheetahcoind
```

Special Note for macOS Mojave: a confusing error might pop up on first try, "fatal error: string.h: No such file or directory".
The string.h file might be there and look normal.  Follow below URL guide to fix the issue:
https://stackoverflow.com/questions/39736728/fatal-error-string-h-no-such-file-or-directory

```
   open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg
```

2. After successful compilcation, a file 'cheetahcoind' should show
up in the folder. This is command line wallet

3.  Run below to compile QT wallet under main folder

```
    cd ..
    cp bitcoin-qt.pro.osx bitcoin-qt.pro
    qmake USE_UPNP=1
    make
```




Running command line wallet
-------

It's now available at `./cheetahcoind`, provided that you are still in the `src`
directory. We have to first create the RPC configuration file, though.

Run `./cheetahcoind` to get the filename where it should be put, or just try these
commands:

```
  echo -e "rpcuser=cheetahcoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/Cheetahcoin/cheetahcoin.conf"
  chmod 600 "/Users/${USER}/Library/Application Support/Cheetahcoin/cheetahcoin.conf"
```

When next you run it, it will start downloading the blockchain, but it won't
output anything while it's doing this. This process may take several hours.

Other commands:

```
    ./cheetahcoind --help  # for a list of command-line options. 
    ./cheetahcoind -daemon # to start the cheetahcoin daemon.
    ./cheetahcoind help    # When the daemon is running, to get a list of RPC commands
```


Running Qt wallet
-------

Use mouse to find the folder "Cheetahcoin-Qt.app",  double click
and launch the GUI wallet "Cheetahcoin-Qt.app".   QT wallet and command line wallet share
the same folder for configuration file and synced blockchain files.  They can not be running
together within same account, only one at a time.
