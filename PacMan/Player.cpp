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
#include "Trap.h"
#include "Engine.h"
#include "GameOver.h"
#include "Chest.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/spriteAnimation.png", 45, 48, 3, 12);
    anim = new Animation(tileset, 0.120f, true);

    uint seqLeft[3] = {6,7,8};
    uint seqRight[3] = {9,10,11};
    uint seqUp[3] = {0,1,2};
    uint seqDown[3] = {3,4,5};
    uint stopped[1] = { 4 };

    anim->Add(LEFT, seqLeft, 3);
    anim->Add(RIGHT, seqRight, 3);
    anim->Add(UP, seqUp, 3);
    anim->Add(DOWN, seqDown, 3);
    anim->Add(STOPPED, stopped, 1);
    

    BBox(new Rect(-20, -25, 20, 20));
    MoveTo(550.0f, 660.0f);
    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete anim;
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
    anim->Select(UP);
    velX = 0;
    velY = -200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
    anim->Select(DOWN);
    velX = 0;
    velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
    anim->Select(LEFT);
    velX = -200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
    anim->Select(RIGHT);
    velX = 200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);
    if (obj->Type() == TRAP)
        TrapCollision(obj);
    if (obj->Type() == CHEST)
        ChestCollision(obj);
    if (obj->Type() == KEY)
        KeyCollision(obj);
        
}

// ---------------------------------------------------------------------------------

void Player::TrapCollision(Object* obj) {
    
    
}

void Player::KeyCollision(Object* obj) {


}

void Player::ChestCollision(Object* obj) {
    Chest* chest = (Chest*)obj;
    chest->SetCollected(1); // Inicia a animacao ao ser coletado

    // Fingir que foi destruido? kkkk
    //obj->MoveTo(1300, 0);
}

void Player::PivotCollision(Object * obj)
{
    Pivot * p = (Pivot*)obj;

    switch (currState)
    {
    case STOPPED:
        // -----------------------
        // CurrentState == STOPPED
        // -----------------------
        anim->Select(currState);
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
    anim->NextFrame();

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
