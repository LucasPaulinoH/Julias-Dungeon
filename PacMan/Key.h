

#ifndef DUNGEON_KEY_H_
#define DUNGEON_KEY_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Jdungeon.h"
#include "Animation.h"


// ---------------------------------------------------------------------------------

class Key : public Object
{
private:
	Sprite* key = nullptr;

public:
	Key();                   // construtor
	~Key();                            // destrutor

	int collected = 0;

	void Update();                      // atualiza��o do objeto
	void Draw();                        // desenho do objeto

	void SetCollected(int value);
	int getCollected();
};

// ---------------------------------------------------------------------------------

inline void Key::Draw()
{
	key->Draw(x, y);
}

inline void Key::Update() {

}



// ---------------------------------------------------------------------------------


#endif