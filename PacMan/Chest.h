

#ifndef DUNGEON_CHEST_H_
#define DUNGEON_CHEST_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Jdungeon.h"
#include "TileSet.h"
#include "Animation.h"


// ---------------------------------------------------------------------------------

class Chest : public Object
{
private:
	TileSet* tileset = nullptr;
	Animation* anim = nullptr;

public:
	Chest();                   // construtor
	~Chest();                            // destrutor

	int collected = 0;

	void Update();                      // atualiza��o do objeto
	void Draw();                        // desenho do objeto

	void SetCollected(int value);
};

// ---------------------------------------------------------------------------------

inline void Chest::Draw()
{
	anim->Draw(x, y);
}

inline void Chest::Update() {
	if (collected == 1) {
		anim->NextFrame();
	}
	
}



// ---------------------------------------------------------------------------------


#endif