/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Trap.h"
#include "Home.h"
#include "Level2.h"
#include "Level1.h"
#include "Player.h"
#include "Pivot.h"
#include <string>
#include <fstream>
#include "GameOver.h"
#include "Chest.h"
#include "Key.h"
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/level1.png");

    // cria jogador
    Player * player = new Player();
    scene->Add(player, MOVING);
    player->setScene(scene);
    // cria armadilhas

    Trap* trap = new Trap();
    trap->MoveTo(150, 388);
    scene->Add(trap, STATIC);

    Key* key = new Key();
    key->MoveTo(150, 138);
    scene->Add(key, STATIC);

    Key * key1 = new Key();
    key1->MoveTo(940, 320);
    scene->Add(key1, STATIC);

    // cria pontos de mudança de direção
    Pivot * pivot;
    bool left, right, up, down;
    float posX, posY;

    // cria pivôs a partir do arquivo
    ifstream fin;
    fin.open("PivotsL1.txt");
    fin >> left;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // lê linha de informações do pivô
            fin >> right; fin >> up; fin >> down; fin >> posX; fin >> posY;
            pivot = new Pivot(left, right, up, down);
            pivot->MoveTo(posX, posY);
            scene->Add(pivot, STATIC);
        }
        else
        {
            // ignora comentários
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }
        fin >> left;
    }
    fin.close();

    // cria baus a partir do arquivo
    //ifstream fin;

    Chest* chest;

    float chestPosX, chestPosY;
    fin.open("ChestL1.txt");
    fin >> chestPosX;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // lê linha de informações do pivô
            fin >> chestPosY;
            chest = new Chest();
            
            
            chest->MoveTo(chestPosX, chestPosY);
            scene->Add(chest, STATIC);
        }
        else
        {
            // ignora comentários
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }
        fin >> chestPosX;
    }
    fin.close();

   // Trap* trap1 = new Trap(560.0f, 560.0f, PEAKS);
   // scene->Add(trap1, STATIC);
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
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
    if (window->KeyDown(VK_SHIFT))
    {
        Engine::Next<Level2>();
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