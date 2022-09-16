#ifndef _ANIMAWALK_H_
#define _ANIMAWALK_H_

#include "Game.h"
#include "Sprite.h"
#include "Player.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite* backg = nullptr;       // sprite de fundo
    Scene* scene = nullptr;

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif
