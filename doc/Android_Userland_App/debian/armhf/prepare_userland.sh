## Productivity tools
sudo apt-get update
sudo apt -y install ssh
sudo apt -y install wget
sudo apt -y install screen
sudo apt -y install vim
sudo apt -y install nano

## fix proc and permission errors causing top ps to fail, workaround
## toybox-armv7l workaround provided at: 
## https://github.com/CypherpunkArmory/UserLAnd/issues/87

wget http://landley.net/toybox/bin/toybox-armv7l
chmod a+rx toybox-armv7l
sudo mv toybox-armv7l /usr/local/bin/

cat >> ~/.bashrc  << EOF

alias top="toybox-armv7l top"
alias ps="toybox-armv7l ps"
alias uptime="toybox-armv7l uptime"
alias reset="toybox-armv7l reset"

EOF
