## 

## using ssh tunel to allow remote ssh login
## https://www.perpetual-beta.org/weblog/bulletproof-firewall-busting-ssh-back-to-your-computer.html 

## ssh -f -N -R  2222:localhost:2222  hlu@192.168.1.103
autossh -f -N -R  2222:localhost:2222  hlu@192.168.1.103

