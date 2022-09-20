#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite * backg = nullptr;       // background
    Scene  * scene = nullptr;       // gerenciador de cena

    bool viewBBox = false;          // habilita visualiza��o da bounding box
    bool ctrlKeyB = false;          // controle da tecla B

public:
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------
