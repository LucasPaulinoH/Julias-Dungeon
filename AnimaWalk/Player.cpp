#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    walking = new TileSet("Resources/character.png", 45, 48, 3, 12);
    anim = new Animation(walking, 0.110f, true);

    uint SeqUp[3] = { 9,10,11 };
    uint SeqDown[3] = { 0,1,2 };
    uint SeqLeft[3] = { 3,4,5 };
    uint SeqRight[3] = { 6,7,8 };
    uint SeqStill[1] = { 1 };

    anim->Add(WALKUP, SeqUp, 3);
    anim->Add(WALKDOWN, SeqDown, 3);
    anim->Add(WALKLEFT, SeqLeft, 3);
    anim->Add(WALKRIGHT, SeqRight, 3);
    anim->Add(STILL, SeqStill, 1);

    state = STILL;
    speed = 200.0f;
    MoveTo(window->CenterX(), window->CenterY());
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete walking;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // anda para cima
    if (window->KeyDown(VK_UP))
    {
        Translate(0, -speed * gameTime);
        state = WALKUP;
    }

    // anda para baixo
    if (window->KeyDown(VK_DOWN))
    {
        state = WALKDOWN;
        Translate(0, speed * gameTime);
    }

    // anda para esquerda
    if (window->KeyDown(VK_LEFT))
    {
        state = WALKLEFT;
        Translate(-speed * gameTime, 0);
    }

    // anda para direita
    if (window->KeyDown(VK_RIGHT))
    {
        state = WALKRIGHT;
        Translate(speed * gameTime, 0);
    }

    // se todas as teclas estão liberadas, mude para o estado parado
    if (window->KeyUp(VK_UP) && window->KeyUp(VK_DOWN) && window->KeyUp(VK_LEFT) && window->KeyUp(VK_RIGHT))
    {
        state = STILL;
    }

    // atualiza animação
    anim->Select(state);
    anim->NextFrame();

    // mantém personagem dentro da tela
    if (x + walking->TileWidth() / 2.0f > window->Width())
        MoveTo(window->Width() - walking->TileWidth() / 2.0f, y);

    if (x - walking->TileWidth() / 2.0f < 0)
        MoveTo(walking->TileWidth() / 2.0f, y);

    if (y + walking->TileHeight() / 2.0f > window->Height())
        MoveTo(x, window->Height() - walking->TileHeight() / 2.0f);

    if (y - walking->TileHeight() / 2.0f < 0)
        MoveTo(x, walking->TileHeight() / 2.0f);
}

// ---------------------------------------------------------------------------------
