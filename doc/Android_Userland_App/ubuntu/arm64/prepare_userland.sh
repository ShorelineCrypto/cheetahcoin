## Productivity tools
sudo apt-get update
sudo apt -y install ssh
sudo apt -y install wget
sudo apt -y install screen
sudo apt -y install vim
sudo apt -y install nano

## fix proc and permission errors causing top ps to fail, workaround
## toybox-aarch64 workaround provided at: 
## https://github.com/CypherpunkArmory/UserLAnd/issues/87

wget http://landley.net/toybox/bin/toybox-aarch64
chmod a+rx toybox-aarch64
sudo mv toybox-aarch64 /usr/local/bin/

cat >> ~/.bashrc  << EOF

alias top="toybox-aarch64 top"
alias ps="toybox-aarch64 ps"
alias uptime="toybox-aarch64 uptime"
alias reset="toybox-aarch64 reset"

EOF
