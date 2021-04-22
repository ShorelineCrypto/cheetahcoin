#!/bin/bash

###
#In order to run this script make sure you have given it permission to run e.g. chmod +x send2reseve.sh
# then type ./send2wallet.sh and it will run.
# Hope this is of some use to someone, good luck! Stormbringer_Derv 2021-03-31
# Revision 0
###


##Declare where the *coind wallets are, needs to be the absolute path, in home directory type ~ and press enter
# this will tell you the home path, then chnage the VAR1 and VAR2 below to the path to where you installed the *coind binaries
VAR1="/home/pi/Debian_10/arm64/nengcoin_v1.7.0.2_u16_arm64/nengcoind"
VAR2="/home/pi/Debian_10/arm64/cheetahcoin_v1.7.0.2_u16_arm64/cheetahcoind"
##For ease of use I have included a typical Android path below uncomment (remove #)  and put # on the above two to use.
#VAR1="/home/note9s/Android_Userland_App/ubuntu/arm64/nengcoin_v1.7.0.2_u16_arm64/nengcoind"
#VAR2="/home/note9s/Android_Userland_App/ubuntu/arm64/cheetahcoin_v1.7.0.2_u16_arm64/cheetahcoind"

##Set the Minimum balance for local wallet  - by default it sends everything from the miner wallet = 0.00000000
# If you wish to change this, enter the minimum you wish to retain using the same format
# as ../../../cheetahcoind getbalance or ../../../nengcoind getbalance
Min_Bal="0.00000000"

##Set Reserve Wallet Addresses - e.g. get this from the receive tab from your reseve wallet system e.g.  QT reserve wallet on Win10
# this is where the balance will go - make sure you set it correctly, there is no conformation.
NENG_Reserve="NM6F3w2Dmbccx44xUQ3e3d63MWtk1eMWDk"
CHTA_Reserve="CQXLU76Z6XqY4Ha8749pR25hUocBfMBchU"

###Nothing more to set below, feel free to edit as needed.

##Functions
function get_neng_balance(){
         $VAR1 getbalance
}

function get_chta_balance(){
        $VAR2 getbalance
}

NENG_Var_Bal=$(get_neng_balance)
CHTA_Var_Bal=$(get_chta_balance)

function Tx_2_NENG_Reserve(){
        $VAR1 sendtoaddress $NENG_Reserve $NENG_Var_Bal
}

function Tx_2_CHTA_Reserve(){
        $VAR2 sendtoaddress $CHTA_Reserve $CHTA_Var_Bal
}


## Send to reserve
if [ $NENG_Var_Bal == $Min_Bal ]
then
        echo "Local NENG Balance = " $NENG_Var_Bal
        echo "Value is Zero, therefore nothing to do."
else
        echo "NENG Balance is not Zero = " $NENG_Var_Bal
        echo "Sending balance to reserve wallet."
        Tx_2_NENG_Reserve
        echo "Done"
        echo "Local NENG Wallet New Balance: "
        get_neng_balance
fi

if [ $CHTA_Var_Bal == $Min_Bal ]
then
        echo "Local CHTA Balance = " $CHTA_Var_Bal
        echo "Value is Zero, therefore nothing to do."
else
        echo "CHTA Balance is not Zero = " $CHTA_Var_Bal
        echo "Sending balance to reserve wallet."
        Tx_2_CHTA_Reserve
        echo "Done"
        echo "Local CHTA Wallet New Balance: "
        get_chta_balance
fi
