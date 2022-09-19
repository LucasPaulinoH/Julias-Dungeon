/**********************************************************************************
// Level1 (C�digo Fonte) 
// 
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Player.h"
#include "Pivot.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Area01(atualizada).png");
    //walls = new Sprite("Resources/Area01Walls.png");

    // cria jogador
    Player * player = new Player();
    scene->Add(player, MOVING);

    // cria pontos de mudan�a de dire��o
    Pivot * pivot;
    bool left, right, up, down;
    float posX, posY;

    // cria piv�s a partir do arquivo
    ifstream fin;
    fin.open("PivotsL1.txt");
    fin >> left;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // l� linha de informa��es do piv�
            fin >> right; fin >> up; fin >> down; fin >> posX; fin >> posY;
            pivot = new Pivot(left, right, up, down);
            pivot->MoveTo(posX, posY);
            scene->Add(pivot, STATIC);
        }
        else
        {
            // ignora coment�rios
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }
        fin >> left;
    }
    fin.close();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    //delete walls;
    delete scene;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    // habilita/desabilita bounding box
    if (ctrlKeyB && window->KeyDown('B'))
    {
        viewBBox = !viewBBox;
        ctrlKeyB = false;
    }
    else if (window->KeyUp('B'))
    {
        ctrlKeyB = true;
    }
    
    if (window->KeyDown(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha cena
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
    //walls->Draw(float(window->CenterX()), float(window->CenterY()), Layer::FRONT);
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------