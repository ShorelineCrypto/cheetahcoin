// Copyright (c) 2011-2014 The Cheetahcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CHEETAHCOIN_QT_CHEETAHCOINADDRESSVALIDATOR_H
#define CHEETAHCOIN_QT_CHEETAHCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class CheetahcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CheetahcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Cheetahcoin address widget validator, checks for a valid cheetahcoin address.
 */
class CheetahcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CheetahcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // CHEETAHCOIN_QT_CHEETAHCOINADDRESSVALIDATOR_H
