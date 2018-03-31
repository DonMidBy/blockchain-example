#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP
#include "block.hpp"

class BlockChain
{
public:
  BlockChain();
  void AddBlock(Block* block);
  Block* GetLastBlock();
private:
  Block* _lastBlock;
};

#endif // BLOCKCHAIN_HPP
