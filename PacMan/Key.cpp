
#include "Key.h"

// ---------------------------------------------------------------------------------

Key::Key() {

	key = new Sprite("Resources/key.png");

	BBox(new Rect(-8, -8, 8, 8));
	//tipo para verificar na colisao
	type = KEY;
}

// ---------------------------------------------------------------------------------

Key::~Key()
{
	delete key;
}

void Key::SetCollected(int value) {
	collected = value;
}

int Key::getCollected() {
	return collected;
}

// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------