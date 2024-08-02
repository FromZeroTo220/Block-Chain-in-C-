#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t PrevIndex, const string &PrevData) : Index(PrevIndex), Data(PrevData) {
    Nonce = 0; // Nonce wird für das Mining verwendet, 0 heißt Mining hat noch nicht begonnen
    tTime = time(nullptr); // Zeitpunkt der Blockerstellung
    Hash = CalculateHash();
}

void Block::minedBlock(uint32_t Difficulty) {
    char cr[Difficulty + 1];
    for (uint32_t i = 0; i < Difficulty; i++) {
        cr[i] = '0'; 
    }
    cr[Difficulty] = '\0';
    string str(cr);

    do {
        Nonce++;
        Hash = CalculateHash();
    } while (Hash.substr(0, Difficulty) != str);
    
    cout << "Mined Block: " << Hash << endl;
}

string Block::CalculateHash() const {
    stringstream ss;
    ss << Index << PrevHash << tTime << Data << Nonce;
    return sha256(ss.str());
}
