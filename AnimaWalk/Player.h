#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

enum PLAYERSTATE { STOPPED, UP, DOWN, LEFT, RIGHT };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet* tilesetU = nullptr;             
    Animation* animU = nullptr;

    TileSet* tilesetD = nullptr;             
    Animation* animD = nullptr;

    TileSet* tilesetL = nullptr;             
    Animation* animL = nullptr;

    TileSet* tilesetR = nullptr;             
    Animation* animR = nullptr;

    float velX = 0;
    float velY = 0;

public:
    uint currState = STOPPED;
    uint nextState = STOPPED;

    Player();
    ~Player();

    void Stop();
    void Up();
    void Down();
    void Left();
    void Right();

    void OnCollision(Object* obj);
    void PivotCollision(Object* obj);

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------