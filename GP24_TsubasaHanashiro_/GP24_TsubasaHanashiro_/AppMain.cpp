#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	Player* player = new Player();

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() != -1)
	{
		InputControl::Update();

		player->Update();

		Vector2D tmp = player->GetLocation();
		if
	}
}