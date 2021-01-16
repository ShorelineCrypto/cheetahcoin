## set password for root
passwd
## copy sshd_config to /etc/ssh/sshd_config
## change port to 2222
apt-get install ssh openssh-server
apt-get install autossh

service ssh restart

## using ssh tunel to allow remote ssh login
## https://www.perpetual-beta.org/weblog/bulletproof-firewall-busting-ssh-back-to-your-computer.html 

## ssh -f -N -R  2222:localhost:2222  hlu@192.168.1.103
autossh -f -N -R  2222:localhost:2222  hlu@192.168.1.103

