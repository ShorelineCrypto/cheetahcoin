# Chrome OS on arm64 or armhf

This folder describe how to run a full node of Cheetahcoin (CHTA) and to CPU mine CHTA in arm based Chromebook as Linux App.  Chrome OS on arm64 or armhf platform was tested. Any Chrome OS version v69 or later on 64 bits arm64 or 32 bits armhf  with linux either in linux beta (Crostini) or Android UserLand app should all work. 

Chrome OS v89 Linux (Beta) runs Debian 11 (bullseye) Debian 10 (Buster) in embedded linux in a container with close to full feature of linux for both CLI and GUI. 
Older version of Chrome OS run Debian 9 (Stretch). The below script and method was also tested on Debian 11 successfully and should all just work on Debian 10 or 9.
   

- Minimum hardware requirement: 2G memory chromebook with 3G additonal spare hard disk. 
- Software Required: Linux (Beta) turned on in Chrome OS or Android UserLand App

For CPU mining steps and optimization with cheetah_Cpuminer on "chta" branch web guide at
https://github.com/ShorelineCrypto/cheetah_cpuminer/tree/chta

To obtain software, please perform below command lines:
```
  git clone https://github.com/ShorelineCrypto/cheetah_cpuminer cheetah_cpuminer_chta
  cd cheetah_cpuminer_chta
  git pull
  git checkout chta
```

Or download directly on zip file of "chta1.5.0" release:
https://github.com/ShorelineCrypto/cheetah_cpuminer/releases/tag/chta1.5.0

For Android UserLand app setup on Debian/Ubuntu, please download and checkout Android Userland package. Below we mainly cover the method using Linux (beta) or Crostini method. 

## Turn on Linux Beta (Crostini)
Go to Chrome OS setting, turn on Linux (Beta).  If your chromebook does not have this option, it is not supported here for CHTA CPU mining. However, your arm CPU based chromebook may still work on Android UserLand app method as alternative. 

For disk size in Linux Beta, we recommend to add 3G on top of recommended 5G by Google. So pick custom disk 8G as minimum selection.

## Start linux Terminal

You can pin linux "Terminal" at menu bar. Download this tgz file to chromebook, drag the file from "Downloads" to "Linux files" folder in chromebook. 
Inside terminal, this file will be at your home directory.  

## Determine your Platform is 64 bits arm64 or 32 bits armhf

In newest arm chromebook, we expect 64 bits arm64 (aarch64)  should be the norm. In older chromebook such as chromebook or chromebit with only 2G memory, it may be armhf platform. 
In the rare cases, your chromebook may have 64 bits CPU, but the linux runs on 32 bits armhf.  You can first run below two commands to determine what is your linux architecture
```
  uname -a
  sudo apt-get update
```
Above information from terminal should give you clear idea whether you have arm64 (aarch64) or armhf platform in linux. 

By default, Linux (Beta) or Crostini runs a container for Debian 11. Below has been tested to be working in both Debian 11 and Debian 10. Because v2.4.0 wallet is static linked, it should work directly in linux beta with proper hardware versions. 


After successfully downloading CHTA wallet file at your current folder. You can move these files to whatever best location inside your "Linux files" folder by using either linux command line or Chromebook GUI drag and drop. 


## Linux Terminal CLI or Desktop GUI wallet for mining? 

For CHTA cpu mining purpose, either CLI wallet or GUI QT wallet was tested working in Chromebook.  You can run either of the software
to run a full node and for the purpose of CPU mining. 

## run GUI QT wallet in Chromebook

### arm64
```
 hlu@penguin:~$ cd cheetahcoin_2.4.0_arm64_linux-gnu
 hlu@penguin:~/cheetahcoin_2.4.0_arm64_linux-gnu$ ./cheetahcoin-qt &
```

### armhf
```
 hlu@penguin:~$ cd cheetahcoin_2.4.0_armhf_linux-gnu 
 hlu@penguin:~/cheetahcoin_2.4.0_armhf_linux-gnu$ ./cheetahcoin-qt &
```

Above in linux terminal will pop CHTA QT wallet in chromebook desktop.

## Copy the conf file and restart wallet
 QT wallet in penguin container may show no connections.  Copy the conf file with below command:

```
hlu@penguin:~$  cp cheetahcoin.conf ~/.cheetahcoin/
```

 Then restart the QT GUI wallet, CHTA should start to sync. Note fully synced wallet to latest block is required in order to CPU mine CHTA with Cheetah_Cpuminer



## FAQ - Linux Terminal Basic Keyboard

Typing command line in linux terminal inside Chromebook is reasonably easy if you are familiar with linux command line on server or desktop. 

#### TAB key on auto filling
TAB key is powerful in linux command line.  Typing full word of file or folder names are inconvenient. 

Here is easier way with tab:
```
   cd cheetahcoin_2.4.0_arm64_linux-gnu 

```
  Typing above long word in Chromebook is close to impossible. An easier way to do is:

```
   cd  cheet-finger push TAB key
```
After you push TAB afer word "cheec" , the chromebook linux terminal should behave like linux in server/desktop with the full file/folder name "cheetahcoin_2.4.0_arm64_linux-gnu" auto populated for you. 

#### Arrow up or down key for history

The arrow up or down key is useful key if you want to repeat a command in recent history.  This is same as desktop/server linux terminal. 


## optional - "screen" command to run cheetah_cpuminer

"screen" is useful linux command for background running in linux, you can start screen session job in the Chromebook and detach. 
When you re-login into Chromebook, you can re-attach the screen session with a command.  Useful keyboards commands to be remembered:
####  start a screen session: type "screen" command in linux terminal
####  detach screen: Ctrl-A-D
####  re-attach screen: type "screen -r" command
####  re-attach specfic screen session when multiple sessions are running (say 3145.pts-1.localhost session):  screen -r 31
#### force re-attach if the screen session is open at another computer: screen -r 31 -d

  Inside screen, run below in cheetah to mine CHTA, and detach screen session to leave it running in background:
```
   screen

   python main.py --interval 10 --cpu 6

   CTRL-A-D

```

You can let it run overnight until you pick up the Chromebook tomorrow for daily use. 

