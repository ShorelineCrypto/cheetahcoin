# openSUSE Tumbleweed on x86_64

This folder describe a binary support from v1.8.0.1 CHTA core release on openSUSE Tumbleweed 20200724.


## Step 1: Install development tools through YaST
Open YaST / Software / Software Management - Select the View Button on the top left and pick Patterns. Now, you will see several Patterns listed and you want to select:
```
Development 

[X] Base Development
[X] Linux Kernel Development
[X] C/C++ Development

```
Then Press the Accept button on the bottom right and allow these applications to install.

## Step 2: Install repository needed for QT4

Open YaST / Software Repositories 
Click "Add", Check "Community Repositores", You will find a list, 
check and select "Packman Repository", OK and add this in 

## Step 3: Install library files
Please run below shell script in terminal for installing dependencies and library files:
```
  bash  prepare_neng.sh
```

## Step 4: download the binary wallet and enjoy:
```
  wget https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v1.8.0.0/cheetahcoin_v1.8.0.0_ubuntu16.04.tgz
  tar xvfz cheetahcoin_v1.8.0.0_ubuntu16.04.tgz
```
