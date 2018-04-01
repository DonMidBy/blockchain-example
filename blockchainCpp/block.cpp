#include "block.hpp"
#include <chrono>
#include <iostream>
#include "sha256.hpp"

/// Constructor
Block::Block(string data):_data(data)
{
   this->_timestamp = to_string(std::chrono::system_clock::now().time_since_epoch().count());
   CreateHash();
}

/// Returns this block's hash
string Block::GetHash() const{
  return _hash;
}

/// Creates a hash from this and the previous block
string Block::CreateHash() const{
  string accumulated_string = to_string(_nonce) + _timestamp +
        _data + (_prevBlock != nullptr ? _prevBlock->GetHash(): "");

  // Create a non-const char*
  char* cstr = new char[accumulated_string.length() + 1];
  strcpy(cstr, accumulated_string.c_str());

  return SHA256(cstr);
}

/// Sets the previous block
void Block::SetPrevBlock(Block *block){
  _prevBlock = block;
}

/// Checks if the block is valid
bool Block::IsValid(uint16_t difficulty){

  string hashed = GetHash();

  if(hashed.length() == 0)return false;

  char require[difficulty + 1];
  for(int i = 0; i < difficulty; ++i){
    require[i] = '0';
  }
  require[difficulty+1] = '\0';
  string require_str = string(require);

  // Check if the first few digits are all zeros
  if(hashed.substr(0, difficulty) == require_str.substr(0, difficulty)){
    return true;
  }
  else return false;
}

void Block::Mine(){

  _nonce = 0;
  _hash = CreateHash();
  while(!IsValid(4)){
    _nonce ++;
    _hash = CreateHash();
  }
  std::cout << "Nonce = " << _nonce << std::endl;
}

string Block::GetData(){
  string data;
  if(_prevBlock != nullptr) data = _prevBlock->GetData();
  return data + " " + _data;
}
