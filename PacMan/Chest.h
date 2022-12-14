

#ifndef DUNGEON_CHEST_H_
#define DUNGEON_CHEST_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Jdungeon.h"
#include "Animation.h"


// ---------------------------------------------------------------------------------

class Chest : public Object
{
private:
	Sprite* coin = nullptr;

public:
	Chest();                   // construtor
	~Chest();                            // destrutor

	int collected = 0;

	void Update();                      // atualização do objeto
	void Draw();                        // desenho do objeto

	void SetCollected(int value);
};

// ---------------------------------------------------------------------------------

inline void Chest::Draw()
{
	coin->Draw(x, y);
}

inline void Chest::Update() {
	
}



// ---------------------------------------------------------------------------------


#endif