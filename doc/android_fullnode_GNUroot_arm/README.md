# Mobile Full Node on Android 32 bits phone (armel or armhf) with GNUroot App
Warning: depreciated, Cheetahcoin v1.5.x no longer support GNUroot App
Warning: alpha release, suitable for expert linux developers only

This folder describes how to set up full node of Cheetahcoin (CHTA) on 32 bits android phone on arm CPUs. 

Minimum Hardware requirement: 1G memory in 32 bits arm phone with 3G spare hard disk 

This full node on old android phone can be used for android CPU mining or as solo server for 
futurebit moonlander2 ASIC USB stick for two nodes rotation setup on base difficulty reset day.

Please read high level overview first from pdf report:
https://github.com/ShorelineCrypto/CheetahCoin/releases/download/CHTA_2020_Q3_report/CHTA_2020_Q3_report.pdf 

## From Desktop Linux in Virtualbox
### Step 1: Intall a Linux desktop server with bridged IPs to allow ssh remote login

As described in the pdf report, a desktop linux server (or equivalent mac or windows ssh server) is required 
for ssh remote login into the phone. The phone terminal is small and difficult to type in linux command. 
Virtualbox installation of Ubuntu 20.04 or 18.04 with bridged networking setup will work.  In this desktop 
linux terminal, run below commands:
```
  sudo apt-get update
  sudo apt-get install ssh openssh-server
  hostname -I
```
 Remember your above IPs. In home environment, 192.168.* or 10.* are common IPs to be used by router. In our 
example below 192.168.1.103 is the router assigned IPs for this linux server. 

## From Android phone
### Step 2: Install and setup GNUroot app from Google Play Store

First install free "GNUroot" and "GNUroot Wheezy" app from google play store into phone.  After both are working in phone, Create New Rootfs on Wheezy, Launch Rootfs on Wheezy . You will enter 
a linux terminal inside GNUroot app, which runs either armel or armhf version of Debian 7 (wheezy). Note what version 
of arm you are running when you apt-get software below.  We will upgrade this version to Debian 8 (jessie) below.


### Step 3: Upgrade Debian to Jessie
Download the shell scripts and copy them to the linux server to be easily copied over to phone below. 
Run below inside linux terminal of GNUroot app in phone:

```
  cd /etc/apt  
  sed -i 's/ftp/archive/g' sources.list
  apt-get update
  apt-get autoremove
  apt-get upgrade
  
  apt-get install ssh
  scp  hlu@192.168.1.103:~/sources.list /etc/apt/
  apt-get update

```
  you may encounter error above, re-type in the commands in phone to make sure the upgrade 
  to debian jessie is completed. 

### step 4, correct permission for tmp log
 assign proper permisison including Sticky bit on tmp
```
  chmod 1777 /tmp
  chmod a+trwx /var/tmp
  chmod -R a+rx /var
  chmod -R a+rwx /var/log
  chmod -R 777 /var/run
```


### step 5,  setup proper ssh networking

  Prepare to use another port 2222 for ssh.  The GNUroot does not allow 
 any port below 1024 for external ssh login

```
 apt-get install ssh wget curl

 ssh-keygen
 cp -r /root/.ssh /home/
 passwd
 ssh-copy-id hlu@192.168.1.103
 scp hlu@192.168.1.103:~/sshd_config .
 mv sshd_config /etc/ssh/
```

## Step 6: set up ssh tunnel to the desktop linux server 

Type below commands in linux terminal of phone:

```
  scp hlu@192.168.1.103:~/prepare_ssh.sh .
  bash prepare_ssh.sh
```

## From Linux Desktop in Virtualbox
### Step 7: remote login from desktop linux through ssh tunnel

 You have changed the root password to a new password above, and fix any error above steps. 
 Now move to the linux server (IP=192.168.1.103 as example) terminal:
```
   ssh root@localhost -p 2222
```

 You should now be able to login into android phone with above command. 


### Step 8: Install locales 

 locales is missing in GNUroot debian which cause unstable OS. Please run below to install locales for regular US 
english keyboard:

```
  apt-get install locales
  export LANGUAGE=en_US.UTF-8
  export LANG=en_US.UTF-8
  export LC_ALL=en_US.UTF-8
  locale-gen en_US.UTF-8
  dpkg-reconfigure locales
```

### Step 9: install some tools, prepare CHTA required library

 screen is useful tools to run in background.  busybox top or uptime is better tool for 
than the default ones.  "busybox top" can see CHTA mining command and android processes.  

 Check out UserLand guide which provide simple commands for screen.

```
  apt-get update
  apt-get install screen
  apt-get install fakeroot
  apt-get install busybox
  nohup bash prepare_neng.sh
```
  
  nohup.out file will record all the errors in the compiling installing process. Run below to find and fix all errors:
  "grep -i error nohup.out"  "grep -i fail nohup.out".

## From Desktop Linux in Virtualbox
### Step 10: Compile CHTA wallet in QEMU
  The armel/armhf CHTA binary from our download is unlikely to work well if your phone hardware is different. 
  Explained in pdf report, you should compile Berkley DB libary above successfully, but likely to fail on CHTA core compilation.  Extract and copy DB library files into QEMU and compile CHTA core wallet following cloud boot from below guide:
  
  debian armel, upgrade wheezy to jessie in QEMU:
  https://people.debian.org/~aurel32/qemu/armel/

  debian armhf, upgrade wheezy to jessie in QEMU:
  https://people.debian.org/~aurel32/qemu/armhf/

 After successfully compiling the CHTA wallet files, copy the files into the android phone for use. 


## From Android Phone
### Step 11: Install Cheetah_Cpuminer:

```
  git clone https://github.com/ShorelineCrypto/cheetah_cpuminer.git
  sudo pip install python-bitcoinrpc
  more /proc/cpuinfo
```

   "lowmemory_neng.sh" script file is used to reduce memory usage when the phone is on cheetah cpu mining. 
   This script also print log file into screen so that you can watch what is going on. 
   CHTA full node can run in one screen session, the cheetah runs in another screen session. 

### optional - solo server for futurebit moonlander2 ASIC USB

   It appears that the full node running in old android can serve better as solo server for USB ASIC that needs 
 two full nodes to rotate around.  Example config file and solo server script are provided for this usage. 

   
