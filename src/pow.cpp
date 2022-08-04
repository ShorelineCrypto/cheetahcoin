// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Cheetahcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "pow.h"

#include "arith_uint256.h"
#include "chain.h"
#include "primitives/block.h"
#include "uint256.h"

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params)
{
    unsigned int nProofOfWorkLimit = UintToArith256(params.powLimit).GetCompact();
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);

    // Genesis block
    if (pindexLast == NULL)
        return nProofOfWorkLimit;

    // Only change once per difficulty adjustment interval, both mainnet and testnet allow min diff
    if (((pindexLast->nHeight+1) % params.DifficultyAdjustmentInterval() != 0) && params.fPowAllowMinDifficultyBlocks )
    {
        // Special difficulty rule for testnet/mainnet on Nengcoin:
        // If the new block's timestamp is more than 2* 10 minutes
        // then allow mining of a cheetah block for CPU/mobile miners on PC or android phones
        
        // dynamically adjust network difficulty when miners suddenly left
        const CBlockIndex* pindex = pindexLast;
        const int64_t nInterval = params.DifficultyAdjustmentInterval();
        const int64_t nTargetSpacing = params.nPowTargetSpacing;

        // v1.12.x randomSpike fork after block height 1308560
        if (pindex->nHeight > 1308560) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 10000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 80) || (pblock->nTime < pindexLast->nTime - 80))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 60) || (pblock->nTime < pindexLast->nTime - 60))
            {
                // 12.5% random chance on Spike difficulty between  +- 60 to 80 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 == 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 20) || (pblock->nTime < pindexLast->nTime - 20))
            {
                // 25% random chance on Spike difficulty between  +- 20 to 60 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 == 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 50% random chance on Spike difficulty between  +- 2 to 20 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 75% random chance on Spike difficulty between +- 1 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }
        // v1.10.x randomSpike fork after block height 769818
        else if (pindex->nHeight > 769818) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 40;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 10000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 80) || (pblock->nTime < pindexLast->nTime - 80))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 60) || (pblock->nTime < pindexLast->nTime - 60))
            {
                // 12.5% random chance on Spike difficulty between  +- 60 to 80 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 == 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 20) || (pblock->nTime < pindexLast->nTime - 20))
            {
                // 25% random chance on Spike difficulty between  +- 20 to 60 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 == 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 50% random chance on Spike difficulty between  +- 2 to 20 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 75% random chance on Spike difficulty between +- 1 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }
        // v1.9.x randomSpike fork after block height 666136
        else if (pindex->nHeight > 666136) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 36;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 20000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 80) || (pblock->nTime < pindexLast->nTime - 80))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else if ((pblock->nTime > pindexLast->nTime + 60) || (pblock->nTime < pindexLast->nTime - 60))
            {
                // 12.5% random chance on Spike difficulty between  +- 60 to 80 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 8 == 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 20) || (pblock->nTime < pindexLast->nTime - 20))
            {
                // 25% random chance on Spike difficulty between  +- 20 to 60 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 == 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else if ((pblock->nTime > pindexLast->nTime + 1) || (pblock->nTime < pindexLast->nTime - 1))
            {
                // 50% random chance on Spike difficulty between  +- 2 to 20 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
            else
            {
                // 75% random chance on Spike difficulty between +- 1 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 4 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }
            }
        }
        // v1.8.0 randomSpike fork after block height 383570
        else if (pindex->nHeight > 383570) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 12;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 100000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 18) || (pblock->nTime < pindexLast->nTime - 18))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else
            {
                // randomSpike difficulty between +- 18 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }


            }
        }
       // v1.7.0 randomSpike fork after block height 216200
        else if (pindex->nHeight > 216200) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;
            bnCheetah /= 4;
            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 100000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 18) || (pblock->nTime < pindexLast->nTime - 18))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else
            {
                // randomSpike difficulty between +- 18 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }


            }
        }
       // v1.6.0 randomSpike fork after blocks 20
       // fixed big CPU miner timestamp attack on NENG v1.5.x
        else if (pindex->nHeight > 20) {
            arith_uint256 bnCheetah;
            bnCheetah = bnPowLimit;

            unsigned int nCheetah = bnCheetah.GetCompact();
            
            arith_uint256 bnSpike;
            bnSpike = bnPowLimit;
            bnSpike /= 100000000000;
            unsigned int nSpike = bnSpike.GetCompact();
            
            if (pblock->nTime > pindexLast->nTime + nTargetSpacing*2)
                return nCheetah;
            else if  ((pblock->nTime > pindexLast->nTime + 18) || (pblock->nTime < pindexLast->nTime - 18))
            {
                // Return the last non-special-min-difficulty-rules-block
                
                while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
            else
            {
                // randomSpike difficulty between +- 18 seconds
                                
                const CBlockIndex* tmpindex = pindexLast;
                tmpindex = tmpindex->pprev;
                tmpindex = tmpindex->pprev;
                if ((tmpindex->nTime + pblock->nTime + pindex->nHeight) % 2 != 0)
                    return nSpike;
                else
                {
                    while (pindex->pprev && pindex->nHeight % nInterval != 0 && pindex->nBits == nCheetah)
                        pindex = pindex->pprev;
                    return pindex->nBits;
                }


            }
        }

        return pindexLast->nBits;
    }

    // Litecoin: This fixes an issue where a 51% attack can change difficulty at will.
    // Go back the full period unless it's the first retarget after genesis. Code courtesy of Art Forz
    int blockstogoback = params.DifficultyAdjustmentInterval()-1;
    if ((pindexLast->nHeight+1) != params.DifficultyAdjustmentInterval())
        blockstogoback = params.DifficultyAdjustmentInterval();
    
    // Go back by what we want to be 14 days worth of blocks
    const CBlockIndex* pindexFirst = pindexLast;
    for (int i = 0; pindexFirst && i < blockstogoback; i++)
        pindexFirst = pindexFirst->pprev;

    assert(pindexFirst);

    return CalculateNextWorkRequired(pindexLast, pindexFirst->GetBlockTime(), params);
}

unsigned int CalculateNextWorkRequired(const CBlockIndex* pindexLast, int64_t nFirstBlockTime, const Consensus::Params& params)
{
    if (params.fPowNoRetargeting)
        return pindexLast->nBits;

    // Limit adjustment step
    int64_t nActualTimespan = pindexLast->GetBlockTime() - nFirstBlockTime;
    if (nActualTimespan < params.nPowTargetTimespan/4)
        nActualTimespan = params.nPowTargetTimespan/4;
    if (nActualTimespan > params.nPowTargetTimespan*4)
        nActualTimespan = params.nPowTargetTimespan*4;

    // Retarget
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);
    arith_uint256 bnNew;
    bnNew.SetCompact(pindexLast->nBits);
    bnNew *= nActualTimespan;
    bnNew /= params.nPowTargetTimespan;

    if (bnNew > bnPowLimit)
        bnNew = bnPowLimit;

    return bnNew.GetCompact();
}

bool CheckProofOfWork(uint256 hash, unsigned int nBits, const Consensus::Params& params)
{
    bool fNegative;
    bool fOverflow;
    arith_uint256 bnTarget;

    bnTarget.SetCompact(nBits, &fNegative, &fOverflow);

    // Check range
    if (fNegative || bnTarget == 0 || fOverflow || bnTarget > UintToArith256(params.powLimit))
        return false;

    // Check proof of work matches claimed amount
    if (UintToArith256(hash) > bnTarget)
        return false;

    return true;
}
