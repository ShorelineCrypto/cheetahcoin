sudo apt-get -y install build-essential g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils  libboost-all-dev

sudo apt-get -y install software-properties-common
 
sudo add-apt-repository -y ppa:bitcoin/bitcoin
sudo apt-get -y update
sudo apt-get -y install libdb4.8-dev libdb4.8++-dev
 
sudo apt-get -y install libzmq3-dev libbz2-dev zlib1g libminiupnpc-dev
sudo apt-get -y install libqt4-dev libprotobuf-dev protobuf-compiler

sudo apt -y install git
sudo apt -y install python-pip
sudo pip install python-bitcoinrpc

wget https://github.com/ShorelineCrypto/NewEnglandCoin/releases/download/v1.4.0/ubuntu16.04_boost1.58_arm64.tgz
tar xvfz ubuntu16.04_boost1.58_arm64.tgz
sudo rm -rf /opt/boost1.58
sudo mv boost1.58  /opt/
sudo mv boost1.58.conf  /etc/ld.so.conf.d/
sudo ldconfig

git clone https://github.com/ShorelineCrypto/cheetah_cpuminer.git
wget  https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v1.9.1.2/cheetahcoin_v1.9.1.2_u16_arm64.tgz
tar xvfz cheetahcoin_v1.9.1.2_u16_arm64.tgz 

