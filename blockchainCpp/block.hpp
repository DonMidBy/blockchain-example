#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <string>
#include <memory>
#include <functional>


using namespace std;

class Block
{
public:


  Block(string data = "");

  /*!
   * \brief Returns this block's hash
   * \return SHA-256 hash
   */
  string GetHash() const;

  /*!
   * \brief Sets the previous block
   *  @param block The block to be added
   */
  void SetPrevBlock(Block* block);

  /*!
   * \brief Tells if the current hash is correct according to format
   *        0000abcderfgt
   * \return
   */
  bool IsValid(uint16_t difficulty);

  /*!
   * \brief Mines the block
   */
  void Mine();

  string GetData();

private:
  int64_t _nonce; /// The counter for mining
  string _timestamp; /// The timestamp of creation
  string _data; /// The smart contract
  string _hash; /// The current hash
  Block* _prevBlock = nullptr; /// The previous block. The first block in a chain is null.

  /*!
   * \brief CreateHash
   * \return The sha-256 hash as a string
   */
  string CreateHash() const;

};

#endif // BLOCK_HPP
