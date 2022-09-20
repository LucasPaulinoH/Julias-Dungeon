#include "Trap.h"

Trap::Trap()
{
	//CRIA SPRITE E BB
	
	
		tileset = new TileSet("Resources/peaksTeste.png", 45, 45, 4, 4);
		anim = new Animation(tileset, 0.900f, true);
		BBox(new Rect(-8, -8, 8, 8));
		type = TRAP;
	
}

// ---------------------------------------------------------------------------------

Trap::~Trap()
{
	delete tileset;
	delete anim;
}