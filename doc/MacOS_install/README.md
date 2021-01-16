

# Supported - macOS 10.11 El Capitan to 10.15 Catalina

For full guide of building own wallet from source, please follow steps at:
 https://github.com/ShorelineCrypto/CheetahCoin/blob/master/doc/build-osx.md

Here below we describe an easier way to install macOS binary wallet on CHTA v1.6.0.0, which was built from source in Mojave. The below 
method was tested to be working on 10.11 , 10.14 and 10.15. 


### Step 1:  Install xcode
In all mac versions, type below in terminal to install Xcode command line tools:
```
    xcode-select --install
```

In older version of OSX such as 10.11, above one command may not be enough. Open up browser such as firefox, register for an apple developer account and search web and download Xcode version 7.3.1. Install dmg file into Application of your Mac.  In below compiling steps in brew, there might be warning that Xcode 7.3.1 is outdated, please upgrade to Xcode 8.x.x , ignore that.


### Step 2: Install HomeBrew

Follow brew Installation Guide:
https://brew.sh/


### Step 3:  Install Required Library Dependencies using Homebrew, download wallet files

Open up terminal, type
```
     brew update
     brew install wget     
     bash prepare_darwin.sh
```

Sometimes Mojave will have header errors because of updates,  like below:
```
upnpc.c:8:10: fatal error: 'stdio.h' file not found
#include <stdio.h>
         ^~~~~~~~~
1 error generated.
make: *** [upnpc.o] Error 1
``` 

Fix the errors by running: 
```
    open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg
```

rerun "prepare_darwin.sh" should fix the issue. 


CLI and GUI wallet files are downloaded in "Downloads" folder


### Step 4:  Switch openssl/miniupnpc to older version

Brew now installed newer and imcompatible versions.  Older version of libraries are enabled as default in order to run CHTA.

```
     bash enable_neng.sh    
```

In Catalina, the openssl library linking method changed dramatically on system level so that enable or not may not have any effect on system. 
Enable or not, CHTA GUI and CLI wallet was tested to be working in MacOS Catalina. 

### Step 5: Install macOs QT wallet and cli wallet
With typical mac method, drag and drop to install GUI dmg software to application or any other folder. Unzip the CLI software and install it at your preferred location. 

For first time CHTA user only to create data folder. If you have never ran CHTA wallet before,  click QT wallet file first, run for a 1 minute, then shut down the wallet.

Copy the conf file to your Cheetahcoin data directory by running below at terminal:

```
    cp  cheetahcoin.conf  ~/Library/'Application Support'/Cheetahcoin/
```
 

### Step 6 optional:  Restore system on openssl/miniupnpc

When you are running CHTA already or after running, you may need to restore system (newer) versions on openssl/miniupnpc to allow 
softwares such as wget etc to work. 
 
```
    bash restore_system.sh

```

