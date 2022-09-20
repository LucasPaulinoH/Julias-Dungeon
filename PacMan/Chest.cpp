
#include "Chest.h"

// ---------------------------------------------------------------------------------

Chest::Chest(){

	tileset = new TileSet("Resources/chest_01_teste.png", 32, 32, 4, 4);
	anim = new Animation(tileset, 0.200f, true);

	BBox( new Rect(-8, -8, 8, 8));
	//tipo para verificar na colisao
	type = CHEST;
}

// ---------------------------------------------------------------------------------

Chest::~Chest()
{
	delete tileset;
	delete anim;
}

void Chest::SetCollected(int value) {
	collected = value;
}

// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------