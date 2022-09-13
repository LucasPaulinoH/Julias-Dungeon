#ifndef _ANIMAWALK_LADY_H_
#define _ANIMAWALK_LADY_H_

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum PlayerState { STILL, WALKUP, WALKDOWN, WALKLEFT, WALKRIGHT };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet* walking;                // folha de sprites do personagem
    Animation* anim;                   // anima��o do personagem
    float       speed;                  // velocidade do personagem

public:
    uint state;                         // estado atual do personagem

    Player();                             // construtor
    ~Player();                            // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Player::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
