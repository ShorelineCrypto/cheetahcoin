// Copyright (c) 2015 The Cheetahcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CHEETAHCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H
#define CHEETAHCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H

#include "validationinterface.h"
#include <string>
#include <map>

class CBlockIndex;
class CZMQAbstractNotifier;

class CZMQNotificationInterface : public CValidationInterface
{
public:
    virtual ~CZMQNotificationInterface();

    static CZMQNotificationInterface* CreateWithArguments(const std::map<std::string, std::string> &args);

protected:
    bool Initialize();
    void Shutdown();

    // CValidationInterface
    void SyncTransaction(const CTransaction& tx, const CBlockIndex *pindex, const CBlock* pblock);
    void UpdatedBlockTip(const CBlockIndex *pindex);

private:
    CZMQNotificationInterface();

    void *pcontext;
    std::list<CZMQAbstractNotifier*> notifiers;
};

#endif // CHEETAHCOIN_ZMQ_ZMQNOTIFICATIONINTERFACE_H
