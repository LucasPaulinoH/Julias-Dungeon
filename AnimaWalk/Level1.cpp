#include "Engine.h"
#include "Level1.h"
#include "Resources.h"

// -----------------------------------------------------------------------------

void Level1::Init()
{
    backg = new Sprite("Resources/Background.jpg");
    player = new Player();
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza objeto
    player->Update();
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    player->Draw();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete player;
    delete backg;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

