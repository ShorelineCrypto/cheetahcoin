Mac OS X Build Instructions and Notes
====================================

Standalone compiling method in MacOS machine is depreciated.  The staticaly linked binary Mac wallet core files were cross compiled in ubuntu 18.04 inside x86_64 docker container.
Below are the steps that you can follow to compile similar wallet binary files from source

Preparation
-----------

Prepare a Ubuntu 18.04 x84_64 machine,  either standalone PC, or in virtualbox, or in WSL2 of windows 10 machine. This is same linux machine where you can compile
or cross compile Linux x64/arm or windows 10 wallet.


Cross Compile
-------------


Follow the guide in [build-generic](build-generic.md)  and in [build-cross](build-cross.md) to compile statically linked macOS binary wallet
for CLI and QT wallet files.


Mac Deploy
----------

Below additional depency are required to build dmg file with macdeploy:

```
pip install ds_store mac_alias
sudo apt-get install librsvg2-bin
sudo apt-get install imagemagick
sudo apt-get install libtiff-tools
```

dmg file is popular mac installation method for mac QT wallet. You can build dmg file with macdeploy. After successfully compiled wallet files with "make -j3"   (3 is CPU number of Ubuntu 18.04 to be used for compiling), you can run one command extra to generate dmg file:

```
make deploy

```

