Copyright (c) 2009-2013 Bitcoin Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.


# Docker Image

A docker file "Dockerfile-ubuntu" for compiling Cheetahcoin (CHTA) in ubuntu 16.04 is provided here. You can pull down a docker image built on this docker file by 
below docker command. 

For x86_64:
```
 docker pull shorelinecrypto/neng_ubuntu16_x86_64:v1.3.0.1
```
For armhf:
```
 docker pull shorelinecrypto/neng_ubuntu16_armhf:v1.4.0.5
```

# Linux Distros supported on binary wallet only

Currently, only Ubuntu 16.04 or Debian 7 (Wheezy) / 8 (Jessie) are described below for compiling wallet from source. 

Newer versions of various linux distros are supported on binary wallet download only. Please check out v1.4.0.3 release ( https://github.com/ShorelineCrypto/CheetahCoin/releases/tag/v1.4.0.3 ) or follow web README page at each subfolder under:
https://github.com/ShorelineCrypto/CheetahCoin/tree/master/doc

The list of Linux distros currently supported on binary download on x86_64 platform:

-  Arch Linux
-  Debian 9 (stretch) / 10 (buster)
-  Fedora 32
-  Manjaro 20.0.3
-  MX Linux 19.2
-  Linux Mint 20
-  openSUSE Tumbleweed
-  Ubuntu 20.04/18.04/16.04

The list of Linux distros currently supported on binary download on arm64 platform:
-  Ubuntu 16.04
-  Ubuntu 18.04
-  Debian 9
-  Debian 10

The list of Linux distros currently supported on binary download on armhf platform:
-  Ubuntu 16.04
-  Ubuntu 18.04
-  Debian 9
-  Debian 10


# Ubuntu 16.04 on x86_64 or arm64/armhf

Ubuntu 16.04 CHTA wallet can be compiled from source on x86_64 or arm64/armhf hardware.

## Dependencies for Ubuntu 16.04


 Library     Purpose           Description
 -------     -------           -----------
 libssl      SSL Support       Secure communications
 libdb4.8    Berkeley DB       Blockchain & wallet storage
 libboost    Boost             C++ Library
 miniupnpc   UPnP Support      Optional firewall-jumping support

[miniupnpc](http://miniupnp.free.fr/) may be used for UPnP port mapping.  It can be downloaded from [here](
http://miniupnp.tuxfamily.org/files/).  UPnP support is compiled in and
turned off by default.  Set USE_UPNP to a different value to control this:

	USE_UPNP=     No UPnP support miniupnp not required
	USE_UPNP=0    (the default) UPnP support turned off by default at runtime
	USE_UPNP=1    UPnP support turned on by default at runtime

IPv6 support may be disabled by setting:

	USE_IPV6=0    Disable IPv6 support


Linux Compilcation Guide

Licenses of statically linked libraries:
 Berkeley DB   New BSD license with additional requirement that linked
               software must be free open source
 Boost         MIT-like license
 miniupnpc     New (3-clause) BSD license


### Versions used in this release in Ubuntu 16.04

-  GCC           5.4
-  OpenSSL       1.0.2g
-  Berkeley DB   4.8.30.NC
-  Boost         1.58.0
-  miniupnpc     1.9
-  Qt 4.8

## Dependency Build Instructions: Ubuntu 16.04 / Ubuntu 18.04


Build requirements:

```
sudo apt-get install build-essential g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils  libboost-all-dev

sudo apt-get install software-properties-common

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libzmq3-dev libbz2-dev 

sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler
```

## sometimes zlib will generate error, reinstall this

sudo apt-get install --reinstall zlib1g

Optional, but recommended:

	sudo apt-get install libminiupnpc-dev (see USE_UPNP compile flag)

	sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler 

Notes
-----
The release is built with GCC and then "strip bitcoind" to strip the debug
symbols, which reduces the executable size by about 90%.



## Cheetahcoin Linux BUILD NOTES on Ubuntu 16.04

Headless cheetahcoin CLI

```
cd src
make -f makefile.unix USE_UPNP=1
strip cheetahcoind

```

 Qt GUI Wallet
```
   cd ..
   qmake USE_UPNP=1 
   make
``` 

# Ubuntu 18.04

There are two ways to obtain Ubuntu 18.04 compatible binary. The first approach is to follow similar steps above to compile everything
in Ubuntu 18.04.  This could be complicated. Without custome method, a simple apt-get and same steps like Ubuntu 16.04 will fail on boost.

An easier way is simply using Ubuntu 16.04 compiled binary files, then compile a boost library version 1.58.0 in Ubuntu 18.04

* (1) Download Ubuntu 16.04 binary files from release from https://github.com/ShorelineCrypto/CheetahCoin/releases

* (2) Compile boost v1.58.0 library in Ubuntu 18.04 with below steps:

```
    wget -O boost_1_58_0.tar.bz2 http://sourceforge.net/projects/boost/files/boost/1.58.0/boost_1_58_0.tar.bz2/download
    tar xvfj boost_1_58_0.tar.bz2
    cd boost_1_58_0
    ./bootstrap.sh --with-libraries=all --with-toolset=gcc 
    ./b2 toolset=gcc 
    sudo ./b2 install --prefix=/usr
    sudo ldconfig 
```

* (3) Re-run either QT or command line Ubuntu 16.04 files, all should work in Ubuntu 18.04, tested to be good on arm64 cloud vps

# Debian Wheezy or Jessie

CHTA core wallet can be compiled in Debian 7 (wheezy) or Debian 8 (jessie).  The dependencies are actually mostly same as Ubuntu 16.04 except for berkley DB shown below.  Please check out the android arm subfolder for more information on debian platform on library dependencies compiling and installation.

```
sudo apt-get -y install qt4-default

cd /opt
wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
tar xvfz db-4.8.30.NC.tar.gz
cd db-4.8.30.NC/build_unix
../dist/configure --enable-cxx --disable-shared --disable-replication
make

cat >> ~/.bashrc  << EOF

export LDFLAGS="-L/opt/db-4.8.30.NC/build_unix"
export CPPFLAGS="-I/opt/db-4.8.30.NC/build_unix"

EOF
```



For actual CHTA core wallet compiling, run below in Debian wheezy or jessie:
```
   cd CheetahCoin/src
   make -f makefile.debian USE_UPNP=1
   strip cheetahcoind
   
   cd ..
   cp bitcoin-qt.pro.debian  bitcoin-qt.pro
   qmake USE_UPNP=1 
   make
   
```


