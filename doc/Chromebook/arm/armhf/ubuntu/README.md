# Ubuntu 18.04 on armhf

This folder describe a binary support from v1.6.0.3 CHTA core release on Ubuntu 18.04.

## Step 1: Install library files
Please run below shell script in terminal for installing dependencies and library files:
```
  bash  prepare_neng.sh
```

## Step 2: download the binary wallet and enjoy:
```
  wget  https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v1.6.0.2/cheetahcoin_v1.6.0.2_u16_armhf.tgz
  tar xvfz cheetahcoin_v1.6.0.2_u16_armhf.tgz
```

## Optional Step 3: compile boost 1.58 from source

The above should work for most of armhf android phones/chromebook. However it may fail in armhf desktop/server or for rare phone/chromebook cases.

Below can fix the hardware incompatible issue by removing binary boost1.58 and compile boost 1.58 library in the machine from source 
as replacement:
 
```
  bash compile_boost1.58.sh
```

Then you can re-run the Step 2 binary wallet files and it should all work now. 

