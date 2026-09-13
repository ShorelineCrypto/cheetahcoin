# Chrome OS Linux Core Wallet

Follow below sub folder for arm or x64 hardware chromebook set up for running linux core wallet on command line or GUI QT wallet with optional cpu mining guide with "cheetah_cpuminer" software.

## Installation Guide of Cheetahcoin Core Wallet Full Node

* Step 1: For first time CHTA user only to create data folder
      If you have never ran CHTA wallet before, double click QT wallet file first, run for a 1 minute, then shut down the wallet. 

* Step 2: Copy 'cheetahcoin.conf' to your path '~/.cheetahcoin/'

```
  cp  cheetahcoin.conf ~/.cheetahcoin/
```

* Step 3: Restart GUI wallet or CLI wallet.  The conf file contains a lot of live nodes ip addresses that will help your wallet to sync. 
     Note for CPU/GPU/USB ASIC solo miners: your wallet needs to be fully synced to latest block before you can solo mine CHTA. 

## Light Wallet for Hodling or DEX Swapping
The current recommended method is to use light wallet such as Cheetahdex Wallet, GleecDEX Wallet or Electrum-CHTA wallet instead of below full node 2nd wallet method for hodling or dex swapping.

* Cheetahdex Wallet & DEX: https://cheetahdex.shorelinecrypto.com/
* GleecDEX Wallet on Android & iPhone: Google App Store, Apple App Store
* Electrum-CHTA wallet: https://github.com/ShorelineCrypto/electrum-chta/releases

## Trouble Shoot - Back up and Restore Old Core Wallet
Follow this guide in case you need to re-start the wallet syncing:
How to back up and restore old core wallet
  https://bitcointalk.org/index.php?topic=5309004.msg67130698#msg67130698

## Trouble Shooting on Linux QT Wallet Keyboard

Linux keyboard may not work in QT core linux wallet, follow below step to apply fix. 

Append this line at bottom of file "~/.bashrc" or  "~/.profile"  at user home directory `export QT_XKB_CONFIG_ROOT=/usr/share/X11/xkb` as below:

```commandline
  echo "export QT_XKB_CONFIG_ROOT=/usr/share/X11/xkb" >> ~/.bashrc
```

Log out and re-login into your account. 

Start QT core wallet only from linux terminal (not mouse click on desktop), this ensure to avoid linux XKB error.  Otherwise the QT core wallet debug console can not type words.


## Installation Guide of Cheetahcoin 2nd Wallet for Reserve Wallet

Mining wallet can go bad quickly. It is recommended to transfer your mined coin to reserve wallet for backup daily. 
The reserve wallet shall have no mining. Put password and backup the reserve wallet regularly. 
Every month or two when the mining wallet goes bad, empty it, then delete the wallet file to start a fresh wallet. 

To setup a reserve wallet, below are the steps

* Step 1:  copy the data folder from ~/.cheetahcoin/  to  ~/.cheetahcoin2/. 
Delete the "wallet.dat"  in the cheetahcoin2 folder so that you get a new wallet file. 

* Step 2:  Modify the batch script "reserve_chta.sh" with your proper username in conf file.

* Step 3:  Run "reserve_chta.sh". You should have second reserve QT wallet running in linux desktop
