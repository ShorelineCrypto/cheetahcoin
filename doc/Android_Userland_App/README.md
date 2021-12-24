# Mobile Mining on Android phone arm64 or armhf with UserLand App

This folder describe how to CPU mine Cheetahcoin (CHTA) in android phone on 64 bits (arm64) or 32 bits (armhf) through UserLand app inside a linux terminal.  UserLand app is an open-source app that can run linux inside your android phone. 

- Minimum hardware requirement: 2G memory phone with 3G spare hard disk. 
- Software Required: UserLand app from Google Play Store or F-Droid

Please read high level overview first from pdf report:
https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/NENG_2020_Q3_report/NENG_2020_Q3_report.pdf 

For CPU mining steps and optimization with cheetah_Cpuminer on "chta" branch web guide at
https://github.com/ShorelineCrypto/cheetah_cpuminer/tree/chta

To obtain software, please perform below command lines: 
```
  git clone https://github.com/ShorelineCrypto/cheetah_cpuminer
  git checkout chta
```
or download zip file:
https://github.com/ShorelineCrypto/cheetah_cpuminer/releases/tag/chta-beta2

## Confusion on android vs linux on CHTA v1.7.x release

There was some confusion created by android mining release v1.9.1.  Please watch this youtube video from android authority Gary Sims:

Is Android really just Linux? - Gary explains
https://www.youtube.com/watch?v=BkP6FTy0a4Y&t=307s

Not trying to create a flaming war.  Understanding the relationship between android vs linux, then you will clearly know what we did on CHTA android CPU mining through UserLand app inside a linux terminal at almost native OS speed.

## Determine your Platform is 64 bits arm64 or 32 bits armhf

In newest android phone or arm chromebook, we expect 64 bits arm64 (aarch64) should be the norm. In older android phone or chromebook such as Samsung Galaxy Tab S4 on Android 9, it may be armhf platform. In the rare cases, your phone or chromebook may have 64 bits CPU, but the linux runs on 32 bits armhf. You can first run below two commands to determine what is your linux architecture on linux terminal either in Debian or Ubuntu after SSH installation.

```
  uname -a
  sudo apt-get update
```

Above information from terminal should give you clear idea whether you have arm64 (aarch64) or armhf platform in linux.

## Debian or Ubuntu?

UserLand app offers 4 linux distros (Alpine, Arch, Debian, Ubuntu). Currently for Cheetahcoin android mining, two distros are supported and tested: Debian (version 10 ) and Ubuntu (version 18.04).  Due to issues that Userland app ubuntu install unsupported version 20.04, currently Debian is recommended for Userland app. 

UserLand Debian runs Debian 10 (buster) on arm64/armhf.  UserLand ubuntu runs Ubuntu 18.04 or 20.04 on arm64/armhf.  The UserLand LXDE or XFCE desktop installation session uses Debian. 

Either distro is fine with similar user experience. If you are interested in desktop offering, Debian is preferred. If you encounter hardware compatibility issues, 
Ubuntu 18.04 is preferred. 

## Ubuntu 18.04 Alternative to Fix Potential Hardware Issue

Arm hardware may have hardware compatibility issues. This situation is worse on 32 bits arm platform. You can suspect a hardware issue if you run into error like "error while loading shared libraries: libboost_system.so.1.58.0". Or CHTA wallet may run, but crash within 1 or 2 hours.

Here we provide a Ubuntu 18.04 CHTA wallet method where you can compile Boost library from source. With self-compiled boost library from source together with CHTA binary wallet file, the hardware compatibility issue should be fixed.


## Linux Terminal (SSH) or Desktop (VNC or XSDL)? 

For CHTA android mining purpose, we recommend using Linux terminal only through UserLand SSH login mode.  Our experience on debian or ubuntu has been fabulous and smooth with 
easy setup for remote login from windows/Mac/Linux desktop on big screen. 

In fact, we have tested XSDL/VNC in quad core android 8.0 on VNC or XSDL mode, and failed with crashes.  We do not know the reason of crash errors like "Connection Failed" after hours of LXDE or XFCE installation.  We also tested Arch SSH installation and failed to complete. 

Android is optimized for mobile GUI on top of linux kernel. GNU or regular linux LXDE or XFCE desktop is mainly for desktop/laptop environment. Therefore we see limited value using LXDE/XFCE in android phones any way. If you want to learn or have fun experience for linux, we would recommend to install a copy of Linux OS inside "VirtualBox" in windows 10. Oracle VirtualBox is free virtual machine software that can install and run a second operating system in windows 10 without need of dual boot.  With virutalBox setup for any one of 8 distros that we support for CHTA wallet, you can mine CHTA with cheetah_cpuminer easily in linux inside virtualbox of windows 10. 

## Putty or No Putty in windows 10?

Putty is windows 10 software to remote login into android UserLand linux at port 2022.  Below main guide mainly use putty to login into android with big screen to type in those linux command line for installation. Alternatively, those command line can also be done without using putty.

Some members reported that putty does not work either because new android versions have security feature to block UserLand app port or routers block those ports.  Member @Sefia at discord provided this word documents "CHTA_Android_arm64_Mining_Guide_without_Putty.txt" at current folder on how to do android mining without using putty. 


## FAQ - Linux Terminal Basic Keyboard

Typing command line in linux terminal inside UserLand is reasonably easy if you are familiar with linux command line on server or desktop. Here are android specific important points

#### TAB key on auto filling
See attached picture in this folder "tab.gif".  Tab key in android is the character below "ESC". It is left/right arrow in one symbol. TAB key is powerful in linux command line.  Typing full word of file or folder names are inconvenient. 

Here is easier way with tab:
```
   cd  cheetahcoin_v1.9.1.2_u16_arm64

```
  Typing above long word in android phone is close to impossible. An easier way to do is:

```
   cd  chee-finger push TAB key
```
After you push TAB afer word "chee" , the android UserLand linux terminal should behave like linux in server/desktop with the full file/folder name "cheetahcoin_v1.9.1.2_u16_arm64" auto populated for you. 

#### Arrow up or down key for history

The arrow up or down key is useful key if you want to repeat a command in recent history.  This is same as desktop/server linux terminal. 


## optional - "screen" command to run cheetah_cpuminer

"screen" is useful linux command for background running in linux, you can start screen session job in the phone and log out. 
When you re-login into phone, you can re-attach the screen session with a command.  Useful keyboards commands to be remembered:
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

Now you can let the cheetah cpuminer running with the phone cord connected to charger. You can let it run overnight until you pick up the phone tomorrow for daily use. 




## optional - Load GUI QT wallet into windows/mac/linux Desktop Remotely

 Running linux terminal-only does not mean that you can not load CHTA QT wallet with GUI remotely. If your home wifi speed is decent, you could try to load CHTA QT GUI wallet in windows 10, or MacOS or Linux Desktop PCs. 
 - Windows 10 with VcXsrv. Download, install and run free software "VcXsrv".  Check the screenshot2 of putty for enabling 
 "Enable X11 forwarding" for the userland login setting. Save the login session with X11 enabled, start VcXsrv in windows, 
 re-login into phone with putty and type below command lines:
 ```
 hlu@localhost:~$ cd cheetahcoin_v1.9.1.2_u16_arm64
 hlu@localhost:~/cheetahcoin_v1.9.1.2_u16_arm64$ ./cheetahcoin-qt &
```
 Above command inside putty will pop the QT GUI wallet in windows 10 with VcXsrv running. Wait for a while for the QT wallet to fully show up in windows, and then you can control the wallet inside phone from windows 10.
 - macOS with XQuartz. Download, install free software "XQuartz". Log out and re-login. Open up mac terminal:
 ```
 $ ssh -XY hlu@192.168.1.98 -p 2022
 -----login in phone----
 hlu@localhost:~$ cd cheetahcoin_v1.9.1.2_u16_arm64
 hlu@localhost:~/cheetahcoin_v1.9.1.2_u16_arm64$ ./cheetahcoin-qt &
```
Above in mac terminal will pop up android phone CHTA QT GUI wallet in macOS desktop. 

 - Linux Desktop, any distro in a terminal
```
 honglu@MX $ ssh -XY hlu@192.168.1.98 -p 2022
 -----login in phone----
 hlu@localhost:~$ cd cheetahcoin_v1.9.1.2_u16_arm64
 hlu@localhost:~/cheetahcoin_v1.9.1.2_u16_arm64$ ./cheetahcoin-qt &
```
Above in linux desktop terminal will pop android phone CHTA QT wallet in linux desktop remotely.

## optional - Fix the phone IP address at home LAN

If you have a router at home environment with wifi connection to the phone for android mining, you will realize that the phone IP address is constantly changing for each time to come home with wifi connection. You should be able to get a fixed IP address through your router setup so that you do not need to find out IP address each time to try the ssh login. 

Take NETGEAR router as example, after intranet admin login into web, say 192.168.1.1 as example, "ADVANCED" -> "WPS Wizard" -> "LAN Setup" -> "ADD", you can add a device mainly based on MAC address and assign that MAC address with an IP, say "192.168.1.98" in our case.  Apply and restart the router. Now reconnect phone wifi, you will get a fixed IP address on the phone no matter what. To avoid conflict with other electronic devices at home, try to pick large IP number, say 98 last digits. Other router vendors may have different lay out of admin web menu setup, but should have similar feature of allowing you to assign a fixed LAN internal IP address for the phone based on MAC address.

   
