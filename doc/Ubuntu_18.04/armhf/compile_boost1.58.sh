sudo rm -rf /opt/boost1.58

wget -O boost_1_58_0.tar.bz2 http://sourceforge.net/projects/boost/files/boost/1.58.0/boost_1_58_0.tar.bz2/download
tar xvfj boost_1_58_0.tar.bz2
cd boost_1_58_0
./bootstrap.sh --with-libraries=all --with-toolset=gcc 
./b2 toolset=gcc 
sudo ./b2 install --prefix=/opt/boost1.58

sudo ldconfig
