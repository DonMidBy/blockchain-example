#include <iostream>
#include <memory>
#include "blockchain.hpp"
using namespace std;

int main(int argc, char *argv[])
{
  // Create the blockchain
  unique_ptr<BlockChain> bc = unique_ptr<BlockChain>(new BlockChain());

  // Create a block
  unique_ptr<Block> block = unique_ptr<Block>(new Block("Block 1"));
  block->Mine();

  // Print out the hash
  cout <<  block->GetHash() << endl;

  // Create a second block
  unique_ptr<Block> block2 = unique_ptr<Block>(new Block("Block 2"));

  // Add the blocks to the blockchain
  bc->AddBlock(block.get());
  bc->AddBlock(block2.get());

  cout <<  bc->GetLastBlock()->GetHash() << endl;

  bc->GetLastBlock()->Mine();

  // Show combined output
  cout << bc->GetLastBlock()->GetHash() << endl;
  cout << bc->GetLastBlock()->GetData() << endl;


  return 0;
}
