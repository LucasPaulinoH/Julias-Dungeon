#include "Engine.h"
#include "GameOver.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void GameOver::Init()
{
    backg = new Sprite("Resources/GameOver.jpg");
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    // sai do jogo com a tecla ESC
    if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
    {
        ctrlKeyESC = false;
        window->Close();
    }
    else if (window->KeyUp(VK_ESCAPE))
    {
        ctrlKeyESC = true;
    }
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------