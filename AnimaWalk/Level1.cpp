#include "Engine.h"
#include "Level1.h"
#include "Resources.h"

// -----------------------------------------------------------------------------

void Level1::Init()
{

    scene = new Scene();

    backg = new Sprite("Resources/Area01.png");
   
    Player * player = new Player();
    scene->Add(player, MOVING);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza objeto
    scene->Update();
    scene->CollisionDetection();
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete scene;
    delete backg;
}
