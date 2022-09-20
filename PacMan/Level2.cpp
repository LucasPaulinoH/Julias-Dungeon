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
#include "Home.h"
#include "Level2.h"
#include "Level1.h"
#include "Player.h"
#include "Pivot.h"
#include <string>
#include <fstream>
#include "GameOver.h"
#include "Key.h"
#include "Chest.h"
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();
    scene->keys = 0;
    scene->gameover = false;
    // cria background
    backg = new Sprite("Resources/level2.png");

    // cria jogador
    Player* player = new Player();
    scene->Add(player, MOVING);
    player->setScene(scene);

    // cria pontos de mudança de direção
    Pivot* pivot;
    bool left, right, up, down;
    float posX, posY;

    Key* key = new Key();
    key->MoveTo(785, 600);
    scene->Add(key, STATIC);

    Key* key1 = new Key();
    key1->MoveTo(384, 666);
    scene->Add(key1, STATIC);

    // cria pivôs a partir do arquivo
    ifstream fin;
    fin.open("PivotsL2.txt");
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

    Chest* chest;

    float chestPosX, chestPosY;
    fin.open("ChestL2.txt");
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
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------

void Level2::Update()
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

    if (scene->keys == 2) {
         //Engine::Next<Level2>();
    }
    if (scene->gameover == true) {
        Engine::Next<GameOver>();
    }
}

// ------------------------------------------------------------------------------

void Level2::Draw()
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