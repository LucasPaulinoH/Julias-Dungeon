/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#include "Jdungeon.h"
#include "Player.h"
#include "Pivot.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    uint seq[3] = { 0,1,2 };
    //uint seqStopped[1] = { 1 };

    tilesetU = new TileSet("Resources/playerUp.png", 45, 48, 3, 3);
    animU = new Animation(tilesetU, 0.150f, true);
    animU->Add(UP, seq, 3);

    tilesetD = new TileSet("Resources/playerDown.png", 45, 48, 3, 3);
    animD = new Animation(tilesetD, 0.150f, true);
    animD->Add(DOWN, seq, 3);
    //animD->Add(STOPPED, seqStopped, 1);

    tilesetL = new TileSet("Resources/playerLeft.png", 45, 48, 3, 3);
    animL = new Animation(tilesetL, 0.150f, true);
    animL->Add(LEFT, seq, 3);

    tilesetR = new TileSet("Resources/playerRight.png", 45, 48, 3, 3);
    animR = new Animation(tilesetR, 0.150f, true);
    animR->Add(RIGHT, seq, 3);

    // imagem do pacman é 48x48 (com borda transparente de 4 pixels)
    currState = STOPPED;
    BBox(new Rect(-20, -20, 20, 20));
    MoveTo(480.0f, 450.0f);
    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tilesetU;
    delete animU;

    delete tilesetD;
    delete animD;

    delete tilesetL;
    delete animL;

    delete tilesetR;
    delete animR;
}

// ---------------------------------------------------------------------------------

void Player::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Up()
{
    velX = 0;
    velY = -200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
    velX = 0;
    velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
    velX = -200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
    velX = 200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);
}

// ---------------------------------------------------------------------------------

void Player::PivotCollision(Object * obj)
{
    Pivot * p = (Pivot*)obj;

    switch (currState)
    {
    case STOPPED:
        // -----------------------
        // CurrentState == STOPPED
        // -----------------------

        switch (nextState)
        {
        case LEFT:
            if (p->left)
            {
                currState = LEFT;
                Left();
            }
            break;
        case RIGHT:
            if (p->right)
            {
                currState = RIGHT;
                Right();
            }

            break;
        case UP:
            if (p->up)
            {
                currState = UP;
                Up();
            }
            break;
        case DOWN:
            if (p->down)
            {
                currState = DOWN;
                Down();
            }
            break;
        }
        break;

    case LEFT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPPED;
                    Stop();
                }
            }
            break;
        case RIGHT:
            currState = RIGHT;
            Right();

            break;
        case UP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UP;
                    Up();
                }
            }
            break;
        case DOWN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGHT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            currState = LEFT;
            Left();
            break;
        case RIGHT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPPED;
                    Stop();
                }
            }

            break;
        case UP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UP;
                    Up();
                }
            }
            break;
        case DOWN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWN;
                    Down();
                }
            }
            break;
        }
        break;

    case UP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFT;
                    Left();
                }
            }
            break;
        case RIGHT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHT;
                    Right();
                }
            }
            break;
        case UP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPPED;
                    Stop();
                }
            }
            break;
        case DOWN:
            currState = DOWN;
            Down();
            break;
        }
        break;

    case DOWN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFT;
                    Left();
                }
            }
            break;
        case RIGHT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHT;
                    Right();
                }
            }
            break;
        case UP:
            currState = UP;
            Up();
            break;
        case DOWN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPPED;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    if (window->KeyDown(VK_LEFT))
    {
        nextState = LEFT;

        if (currState == RIGHT || currState == STOPPED)
        {
            currState = LEFT;
            Left();
        }            
    }
    
    if (window->KeyDown(VK_RIGHT))
    {
        nextState = RIGHT;

        if (currState == LEFT || currState == STOPPED)
        {
            currState = RIGHT;
            Right();
        }
    }
    
    if (window->KeyDown(VK_UP))
    {
        nextState = UP;

        if (currState == DOWN || currState == STOPPED)
        {
            currState = UP;
            Up();
        }
    }
    
    if (window->KeyDown(VK_DOWN))
    {
        nextState = DOWN;

        if (currState == UP || currState == STOPPED)
        {
            currState = DOWN;
            Down();
        }
    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

    // mantém player dentro da tela
    if (x+20 < 0)
        MoveTo(window->Width()+20.f, Y());

    if (x-20 > window->Width())
        MoveTo(-20.0f, Y());

    if (Y()+20 < 0)
        MoveTo(x, window->Height()+20.0f);

    if (Y()-20 > window->Height())
        MoveTo(x, -20.0f);
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{ 
    switch(currState)
    {
    case LEFT:  animL->Draw(x, y, Layer::UPPER); break;
    case RIGHT: animR->Draw(x, y, Layer::UPPER); break;
    case UP:    animU->Draw(x, y, Layer::UPPER); break;
    case DOWN:  animD->Draw(x, y, Layer::UPPER); break;
    default: 
        switch(nextState)
        {
        case LEFT: animL->Draw(x, y, Layer::UPPER); break;
        case RIGHT: animR->Draw(x, y, Layer::UPPER); break;
        case UP:    animU->Draw(x, y, Layer::UPPER); break;
        case DOWN:  animD->Draw(x, y, Layer::UPPER); break;
        default:    animL->Draw(x, y, Layer::UPPER);
        }
    }
}

// ---------------------------------------------------------------------------------