/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Player do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_PLAYER_H_
#define _PACMAN_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"
#include "Scene.h"
#include "Key.h"
#include "Chest.h";
// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
enum PLAYERSTATE {STOPPED, UP, DOWN, LEFT, RIGHT};    

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:

    TileSet* tileset = nullptr;
    Animation* anim = nullptr;
    float velX = 0;                     // velocidade horizontal do player
    float velY = 0;                     // velocidade vertical do player

    static Scene* scene;

    int itemCount = 0;                  // Contador de coletaveis

public:
    uint currState = STOPPED;            // estado atual do jogador
    uint nextState = STOPPED;            // pr�ximo estado do jogador

    Player();                           // construtor
    Player(Scene* sc);
    ~Player();                          // destrutor

    void Stop();                        // p�ra jogador
    void Up();                          // muda dire��o para cima
    void Down();                        // muda dire��o para baixo
    void Left();                        // muda dire��o para esquerda
    void Right();                       // muda dire��o para direita


    void setScene(Scene* sc);
    void OnCollision(Object * obj);
    void TrapCollision(Object* obj);    // resolu��o da colis�o entre armadilhas
    void PivotCollision(Object * obj);  // revolve colis�o com piv�
    void ChestCollision(Object* obj);
    void KeyCollision(Object* obj);

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------


inline void Player::Draw()
{
    anim->Draw(x, y, z);
}
#endif