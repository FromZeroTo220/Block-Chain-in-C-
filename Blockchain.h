#include <cstdint>
#include <vector>
#include "Block.h"



class Blockchain{
    public: 
    Blockchain(); 
    
    void AddBlock(Block newBlock )  // Parameter = Instanz der Klasse von oben 
    
    private: 
    uint32_t Difficulty; 
    vector<Block> Chain;   // Vector jeder Eintrag = Objekt der Klasse Block
    Block getLastBlock(); 


}
