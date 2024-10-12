# Change Log
All notable changes to this project will be documented in this file.
 

## [2.4.0] - 2024-10-12
 
Hard fork on and after block height 3548577. This is major release that all users are required to upgrade. 
 
### Added
- [Deep Reorg Protection](https://github.com/ShorelineCrypto/cheetahcoin/commit/72825cd4c8d8e97f25cf581573769f0d9532488f)
  Added the finalized block concept on rolling 48 blocks. Finalized blocks cannot be reorged, which protects the network against deep reorgs. This feature was ported from Bitcoin Cash v0.18.5 code base.
- [randomSpike 13x](https://github.com/ShorelineCrypto/cheetahcoin/commit/c72a75e8178f0349f218ffabfd426bc429b6e487)
  Added randomSpike v1.13x difficulty aglorithm.  Compared to prior version of randomSpike (v1.12x), cheetah difficulty value will drop by 400x to 0.0025 while spike difficulty will rise 2x to 20G.
  
### Changed
- [Hard Fork Height](https://github.com/ShorelineCrypto/cheetahcoin/commit/da3163dd1d09755e5c85bd55feeebe3c08dfa478)
  Added hard fork block height 3548577.  After this block height, this new release will form a new chain on the first cheetah block mined by the network. 

### Fixed
- [MinWork Upgrade](https://github.com/ShorelineCrypto/cheetahcoin/commit/3153b3ea472d4103f44329b7f442a4bc94cb9c88)
  Upgraded minimum work bug fix code base to allow minimum work 400x below 1. 
 
## [2.3.0] - 2022-08-04
  
Activate three soft forks - BIP68/BIP112/BIP113. Hard fork on and after block height 1408590. (Note, the actual Cheetahcoin chain hard forked on height 1411922 off the prior old version).
cheetah difficulty drop by 40x to 1, new future timestamp 30 seconds rule
 
### Added
- [randomSpike 12x](https://github.com/ShorelineCrypto/cheetahcoin/commit/baf066612985fc5a525ec3599d4974ea6d8b93df)
  Added randomSpike v1.12x difficulty aglorithm.  Compared to prior version of randomSpike (v1.10x), cheetah difficulty value dropped 40x to  1.
- [activate BIP68/BIP112/BIP113](https://github.com/ShorelineCrypto/cheetahcoin/commit/baf066612985fc5a525ec3599d4974ea6d8b93df)
  Activate BIP34 at 100 blocks after hard fork height.  Enable deployment_csv 3 soft forks: BIP68/BIP112/BIP113.
 
### Changed
  
- [Hard Fork Height](https://github.com/ShorelineCrypto/cheetahcoin/commit/f3d8f189da62b57340cbfa3d04666fb3ecd52cdf)
  Added hard fork block height 1408590.  After this block height, this new release will form a new chain on the first cheetah block mined by the network. 
 
- [Future timestamp 30 seconds rule](https://github.com/ShorelineCrypto/cheetahcoin/commit/2cf7059f1fbef9755069a3e85a8dfea6a35dbbde)
 Enforced future timestamp 30 seconds rule after v1.12.x hard fork. Any new block received by full node with timestamp by more than 30 seconds in the future will be rejected.
 
 
## [2.1.0] - 2022-03-08
Cheetahcoin core code base rebased off bitcoin core v0.13.2 on v1.10.x randomSpike. 
### Changed
- [Rebase Code Swap](https://github.com/ShorelineCrypto/cheetahcoin/commit/c7bb39863ba922022b84e85dafee1ac06584e6ee)
Old bitcoin v0.8.8.0 code was replaced with new code based off bitcoin v0.13.2 code.  The new core wallet can sync with v1.10.1 old wallet on randomSpike v1.10.x. 
- [MinWork Bug](https://github.com/ShorelineCrypto/cheetahcoin/commit/826ccb94f93f4e0c572b3dc8a73d39abd60b4844)
Fix the same minimum work bug on bitcoin core v0.13.2 new code base
- [Future timestamp rule](https://github.com/ShorelineCrypto/cheetahcoin/commit/8d0a92ee64c189dd461503541a4040d966a3f14d)
Shortened bitcoin 2 hour timestamping allowance rule to 4 minutes rule

## [1.10.1] - 2022-02-09
This is last old core wallet version on bitcoin v0.8.8.0 code base. Shortened original bitcoin 2 hour timestamping allowance rule to 4 minutes rule
Hard fork on block height 769818, spike difficulty dropped from 20G to 10G, cheetah difficulty rose from 36 to 40
### Added
- [randomSpike v1.10.x](https://github.com/ShorelineCrypto/cheetahcoin/commit/6a4ca752a2186208395bc8dba0b95725cfaa69e6)
### Changed
- [Future timestamp rule](https://github.com/ShorelineCrypto/cheetahcoin/commit/ca981e07bba799819c993609025f8322774d8ed5)
Shortened bitcoin 2 hour timestamping allowance rule to 4 minutes rule


 ## [1.9.1] - 2021-12-22
Fixed the minimum work bug that may cause multiple chains splitting. Hard fork on block height 666136, expanded random spike windows from +- 18 seconds to +- 80 seconds,
spike difficulty dropped from 100G to 20G, cheetah difficulty rose from 12 to 36
### Added
- [randomSpike v1.9.x](https://github.com/ShorelineCrypto/cheetahcoin/commit/24365a176c3ce1f817bf8df5967f331909060a7c)
### Fixed
- [MinWork Bug](https://github.com/ShorelineCrypto/cheetahcoin/commit/839b8b35acd899c672fc9414cef62430e7dccbb7)
Cheetah blocks have low difficulty, allowed to sync to fix MinWork Bug.
 
 ## [1.8.0] - 2021-07-04
Hard fork on block height 383570, cheetah difficulty rose 3x to 12
### Added
- [randomSpike v1.8.x](https://github.com/ShorelineCrypto/cheetahcoin/commit/e45770e72545fd5613b43c246ff757a4fddc7dff)
   
   
## [1.7.0] - 2021-04-18
Community approved winning bounty logo incorporated, hard fork on block height 216200, cheetah difficulty rose 4x, acquire CCheckQueue's lock to avoid race condition.
### Added
- [randomSpike v1.7.x](https://github.com/ShorelineCrypto/cheetahcoin/commit/95e498ce505a27442c98b9a1cadb4fe0f84fd793)
   
## [1.6.0] - 2021-01-12
Cheetahcoin launched at bitcointalk Ann as a nengcoin randomSpike v1.6.x fork on SHA256
### Added
- [randomSpike v1.6.x](https://github.com/ShorelineCrypto/cheetahcoin/commit/1de2d0f822ddaa80db5feebc116b432268ebe904)
   
## Cheetah Meme
Dec 28,2018 - Cheetah_Cpuminer software for Nengcoin cpu/mobile mining was released. The meme of Cheetah on randomSpike algo came alive