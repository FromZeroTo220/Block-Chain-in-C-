#include <cstdint>
#include <iostream>
#include "Block.h"
#include "sha256.h"
using namespace std;


class Block{
    public: 
    string PrevHash; 
    
    Block(uint32_t PrevIndex, const string &PrevData );
    
    string getHash();
    
    void minedBlock(int PrevDifficulty);

    private: 

    uint32_t Index; 
    int64_t Nonce; 
    string Data; 
    string Hash; 
    int tTime; 

    string CalculateHash();
}
