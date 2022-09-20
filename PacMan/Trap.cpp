#include "Trap.h"

Trap::Trap(float posX, float posY, uint trap_type)
{
	//CRIA SPRITE E BB
	switch (trap_type) {
	case PEAKS:
		tileset = new TileSet("Resources/peaks.png", 16, 16, 4, 4);
		anim = new Animation(tileset, 0.900f, true);
		BBox(new Rect(-8, -8, 8, 8));
		MoveTo(posX, posY);
		type = TRAP;
		break;
	case HOLE:
		break;
	default:
		//
		break;
	}
}

// ---------------------------------------------------------------------------------

Trap::~Trap()
{
	delete tileset;
	delete anim;
}