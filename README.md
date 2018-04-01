# Blockchain in C++
A basic C++ blockchain.

## Blockchain

 ||=========||	        ||=========||           ||=========||           ||=========||
 || Block 1 ||          || Block 2 ||           || Block 3 ||           || Block 4 ||
 ||=========|| =====>   ||=========||   =====>  ||=========||   =====>  ||=========||
 || 1102324 ||          || 1123454 ||           || 1184686 ||           || 1185483 ||  <=== HASH

A blockchain is basically a linked list with a hash.
The hash is generated from the current and the previous block. 
Each Block can store transaction data which will be incorporated in the calculation of the hash. A counter, a so called NONCE is introduced in each block and incorporated as well to produce (or MINE) a hash with a predetermined start (p.e. 11). If anyone alters the data in a previous block, all the following blocks alter their hashes as well, s.t. the beginning is not 11 anymore and thus not valid. To cheat the system, one would then need to mine again all the following blocks to get again a 11. Nevertheless, as the blockchain network consists of active miners, one would need to have more than all of the miners computer power combined. In reality, cheating should therefore not be possible.

## Proof of Work

## Proof of Stake
