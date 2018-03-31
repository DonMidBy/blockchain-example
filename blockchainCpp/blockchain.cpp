#include "blockchain.hpp"

BlockChain::BlockChain()
{

}

void BlockChain::AddBlock(Block *block){

  // If the last block was null, it is the first in the chain.
  // Therefore add null to the last block's reference
  if(this->_lastBlock != nullptr){
    block->SetPrevBlock(this->_lastBlock);
  }
  this->_lastBlock = block;
}

Block* BlockChain::GetLastBlock(){
  return this->_lastBlock;
}
