#include "Types.h"                          // tipos espec�ficos da engine
#include "Object.h"                         // interface de Object

// ---------------------------------------------------------------------------------

class Pivot : public Object
{
public:
    bool left = false;                     // passagem livre a esquerda
    bool right = false;                     // passagem livre a direita
    bool up = false;                     // passagem livre para cima
    bool down = false;                     // passagem livre para baixo

    Pivot(bool l, bool r, bool u, bool d);  // construtor
    ~Pivot();                               // destrutor

    void Update() {};                       // atualiza��o
    void Draw() {};                         // desenho
};

// ---------------------------------------------------------------------------------
