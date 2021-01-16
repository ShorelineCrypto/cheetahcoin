sudo apt-get update
sudo apt-get -y install ssh wget curl unzip
#install libbost, gcc and g++ compilers
sudo apt-get -y install build-essential
sudo apt-get -y install g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils
sudo apt-get -y install libboost-all-dev
sudo apt-get -y install software-properties-common
sudo add-apt-repository -y ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get -y install libdb4.8-dev libdb4.8++-dev
sudo apt-get -y install libzmq3-dev libbz2-dev zlib1g libminiupnpc-dev
sudo apt-get -y install libqt4-dev libprotobuf-dev protobuf-compiler

sudo apt -y install git
sudo apt -y install python-pip
sudo pip install python-bitcoinrpc

## reuse prior compiled boost libary for Ubuntu 18.04
wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/ubuntu16.04_boost1.58_arm64.tgz
tar xvfz ubuntu16.04_boost1.58_arm64.tgz
sudo rm -rf /opt/boost1.58
sudo mv boost1.58  /opt/
sudo mv boost1.58.conf  /etc/ld.so.conf.d/
## link all libary files
sudo ldconfig
