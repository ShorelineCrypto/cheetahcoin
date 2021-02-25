
Installation Guide of Cheetahcoin (CHTA) windows 10 Wallet for Mining

 Step 1: For first time CHTA user only to create data folder
      If you have never ran CHTA wallet before, double click QT wallet file first, run for a 1 minute, then shut down the wallet. 

 Step 2: Copy 'cheetahcoin.conf' to your path 'C:\Users\YourUser\AppData\Roaming\Cheetahcoin'


 Step 3: Restart GUI wallet or CLI wallet.  The conf file contains a lot of live nodes ip addresses that will help your wallet to sync. 
     Note for CPU/GPU/USB ASIC solo miners: your wallet needs to be fully synced to latest block before you can solo mine CHTA. 


Installation Guide of Cheetahcoin windows 10 Wallet for Reserve Wallet

Mining wallet can go bad quickly. It is recommended to transfer your mined coin to reserve wallet for backup daily. 
The reserve wallet shall have no mining. Put password and backup the reserve wallet regularly. 
Every month or two when the mining wallet goes bad, empty it, then delete the wallet file to start a fresh wallet. 

To setup a reserve wallet, below are the steps

Step 1:  copy the data folder from 'C:\Users\YourUser\AppData\Roaming\Cheetahcoin'  to  'C:\Users\YourUser\AppData\Roaming\Cheetahcoin2'. 
Delete the "wallet.dat"  in the Cheetahcoin2 folder so that you get a new wallet file. 
Step 2:  Modify the batch script "reserve_chta.bat" with your proper username in windows10
Step 3:  double click "reserve_chta.bat". You should have second reserve QT wallet running in windows10