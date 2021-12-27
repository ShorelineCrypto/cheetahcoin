# Ubuntu 18.04 on arm64

This folder describe a binary support from v1.9.1.3 CHTA core release on Ubuntu 18.04.

## Step 1: Install library files
Please run below shell script in terminal for installing dependencies and library files:
```
  bash  prepare_neng.sh
```

## Step 2: download the binary wallet and enjoy:
```
  wget  https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v1.9.1.2/cheetahcoin_v1.9.1.2_u16_arm64.tgz
  tar xvfz cheetahcoin_v1.9.1.2_u16_arm64.tgz
```

## Optional Step 3: compile boost 1.58 from source

The above should work for most of arm64 android phones. However it may fail in arm64 desktop/server or for rare phone cases.

Below can fix the hardware incompatible issue by removing binary boost1.58 and compile boost 1.58 library in the machine from source 
as replacement:
 
```
  bash compile_boost1.58.sh
```

Then you can re-run the Step 2 binary wallet files and it should all work now. 

