rem reserve wallet only, not for mining
rem mining wallet can go bad quickly, recommend to transfer your mined coin to this reserve wallet daily
rem change below username to your proper username
nengcoin-qt.exe  -port=8377  -rpcport=8376 -datadir=%HOMEPATH%\AppData\Roaming\Nengcoin2
pause
