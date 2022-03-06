
sudo apt-get -y install software-properties-common
 
sudo apt-get -y update
 

sudo apt -y install curl git

sudo apt -y install python
sudo apt -y install python2

curl https://bootstrap.pypa.io/pip/2.7/get-pip.py -o get-pip.py
sudo  python2 get-pip.py

git clone https://github.com/ShorelineCrypto/cheetah_cpuminer.git

wget  https://github.com/ShorelineCrypto/cheetahcoin/releases/download/v2.1.0/cheetahcoin_2.1.0_armhf_linux-gnu.tgz
tar xvfz cheetahcoin_2.1.0_armhf_linux-gnu.tgz 

