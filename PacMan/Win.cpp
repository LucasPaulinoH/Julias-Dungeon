#include "Engine.h"
#include "Win.h"
#include "Level1.h"
#include "Home.h"

// ------------------------------------------------------------------------------

void Win::Init()
{
    backg = new Sprite("Resources/telafinal.png");
}

// ------------------------------------------------------------------------------

void Win::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Win::Update()
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

    if (window->KeyDown(VK_RETURN)) {
        Engine::Next<Home>();
    }
}

// ------------------------------------------------------------------------------

void Win::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------