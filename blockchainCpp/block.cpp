#include "block.hpp"
#include <chrono>
#include <iostream>

Block::Block(string data):_data(data)
{
   this->_timestamp = to_string(std::chrono::system_clock::now().time_since_epoch().count());
}

size_t Block::CreateHash(){
  string accumulated_string = to_string(this->_nonce) + this->_timestamp +
      this->_data + (this->_prevBlock != nullptr ? to_string(this->_prevBlock->CreateHash()): "");

  return hash<string>{}(accumulated_string);
}

void Block::SetPrevBlock(Block *block){
  this->_prevBlock = block;
}

bool Block::IsValid(){
  string hashed = to_string(this->CreateHash());
  if(hashed.at(0) == '1' && hashed.at(1) == '1' && hashed.at(2) == '1' && hashed.at(3) == '1'
     && hashed.at(5) == '1' && hashed.at(6) == '1' && hashed.at(7) == '1' ){
    return true;
  }
  else return false;
}

void Block::Mine(){
  this->_nonce = 0;
  while(!IsValid()){
    this->_nonce ++;
  }
  std::cout << "Nonce = " << this->_nonce << std::endl;
}
