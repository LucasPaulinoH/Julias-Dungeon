#include "Engine.h"
#include "Resources.h"
#include "Home.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura a engine
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Jogo");
    engine->window->Icon(IDI_ICON);

    int status = engine->Start(new Home());

    delete engine;
    return status;
}