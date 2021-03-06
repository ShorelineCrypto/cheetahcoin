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
