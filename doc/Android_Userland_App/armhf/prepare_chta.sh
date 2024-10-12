
sudo apt-get -y install software-properties-common
 
sudo apt-get -y update
 

sudo apt -y install curl git

sudo apt -y install python
sudo apt -y install python2

curl https://bootstrap.pypa.io/pip/2.7/get-pip.py -o get-pip.py
sudo  python2 get-pip.py
sudo pip2 install python-bitcoinrpc

git clone https://github.com/ShorelineCrypto/cheetah_cpuminer.git cheetah_cpuminer_chta
cd cheetah_cpuminer_chta
git checkout chta

cd ..

wget  https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v2.4.0/cheetahcoin_2.4.0_armhf_linux-gnu.tgz
tar xvfz cheetahcoin_2.4.0_armhf_linux-gnu.tgz 

