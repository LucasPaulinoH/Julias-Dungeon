#ifndef _ANIMAWALK_H_
#define _ANIMAWALK_H_

#include "Game.h"
#include "Sprite.h"
#include "Player.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite* backg = nullptr;       // sprite de fundo
    Player* player = nullptr;          // objeto com animação    

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif
