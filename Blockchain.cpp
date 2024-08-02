#include "Blockchain.h"

Blockchain::Blockchain(){
    Chain.emplace_back(Block(0,"Genesis Block")); // 0 = Index Genesis Block
    Difficulty = 4; // beginn mit 4 führendem Nullen 
}

void Blockchain:: AddBlock(Block newBlock){
    newBlock.PrevHash = getLastBlock().getHash(); 
    newBlock.minedBlock(Difficulty); 
    Chain.push_back(newBlock); 
}

Block Blockchain:: getLastBlock(){
    return Chain.back(); 
}