sudo pacman -Syu
sudo pacman --noconfirm  -S wget curl openssh 
sudo pacman --noconfirm  -S  base-devel python2
sudo pacman --noconfirm  -S qt4
wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/ubuntu20.04_x86_64_db-4.8.30.NC.tgz
tar xvfz ubuntu20.04_x86_64_db-4.8.30.NC.tgz 
sudo rm -rf /opt/db-4.8.30.NC
sudo mv db-4.8.30.NC  /opt/
sudo mv bitcoin.conf /etc/ld.so.conf.d/

wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/ubuntu20.04_x86_64_miniupnpc.tgz
tar xvfz ubuntu20.04_x86_64_miniupnpc.tgz
sudo rm -rf /opt/miniupnpc
sudo mv miniupnpc /opt/
sudo mv miniupnpc.conf /etc/ld.so.conf.d/ 

wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/ubuntu20.04_x86_64_openssl-1.0.0.tgz
tar xvfz ubuntu20.04_x86_64_openssl-1.0.0.tgz 
sudo rm -rf /opt/openssl
sudo mv openssl  /opt/
sudo mv openssl.conf /etc/ld.so.conf.d/ 

## reuse prior compiled boost libary for Ubuntu 18.04
wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.2.1.1/ubuntu18.04_boost1.58.tgz
tar xvfz ubuntu18.04_boost1.58.tgz
sudo rm -rf /opt/boost1.58
sudo mv boost1.58  /opt/
sudo mv boost1.58.conf  /etc/ld.so.conf.d/
## link all libary files
sudo ldconfig

