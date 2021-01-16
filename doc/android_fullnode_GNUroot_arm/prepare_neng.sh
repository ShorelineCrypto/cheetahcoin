apt-get update
apt-get --yes  --force-yes install build-essential 
apt-get --yes  --force-yes install g++ libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils 
apt-get --yes  --force-yes install libboost-all-dev

apt-get --yes  --force-yes install software-properties-common
apt-get --yes  --force-yes  install python-software-properties
apt-get update

 
apt-get --yes  --force-yes install libzmq3-dev libbz2-dev 
 
## sometimes zlib will generate error, reinstall this
apt-get --yes  --force-yes install --reinstall zlib1g
 
apt-get --yes  --force-yes install openssl
apt-get --yes  --force-yes install libminiupnpc-dev

apt-get --yes  --force-yes install python-pip
pip install --upgrade --index-url=https://pypi.python.org/simple/ pip==8.1.2
apt-get --yes  --force-yes remove python-pip
pip install python-bitcoinrpc

apt-get --yes  --force-yes install git
#git clone https://github.com/ShorelineCrypto/CheetahCoin.git
#git clone https://github.com/ShorelineCrypto/cheetah_cpuminer.git


# Berkeley DB: http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
# We'll use version 4.8 to preserve binary wallet compatibility.
# From a MinGW shell unpack the source archive, configure and make:
# Code:

cd /opt
wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
tar xvfz db-4.8.30.NC.tar.gz
cd db-4.8.30.NC/build_unix
../dist/configure --enable-cxx --disable-shared --disable-replication
make


cat >> ~/.bashrc  << EOF

export LDFLAGS="-L/opt/db-4.8.30.NC/build_unix"
export CPPFLAGS="-I/opt/db-4.8.30.NC/build_unix"

EOF
