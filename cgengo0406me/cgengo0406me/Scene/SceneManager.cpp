#include "SceneManager.h"
#include "DxLib.h"

InputManager* InputManager::Get()
{
	static InputManager instance;
	return &instance;
}

void InputManager::Update()
{
	//前回入力値の更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//現在入力値の更新
	GetHitKeyStateAll(now_key);
}

eInputState InputManager::GetKeyState(int keycode)const
{
	if (CheckKeycodeRange(keycode))
	{
		if (old_key[keycode] == TRUE)
		{
			if (now_key[keycode] == TRUE)
			{
				return eInputState::Held;
			}
			else
			{
				return eInputState::Released;
			}
		}

	}
	return eInputState::None;
}
bool InputManager::CheckKeycodeRange(int keycode) const
{
	return (0 <= keycode && keycode < D_KEYCODE_MAX);
}
