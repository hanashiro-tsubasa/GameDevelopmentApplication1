#include "InputControl.h"
#include "DxLib.h"

char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};
//入力機能の更新処理
void InputControl::Update()
{
	memcpy(old_key, now_key,(sizeof(char) * D_KEYCODE_MAX));
	GetHitKeyStateAll(now_key);
}
//キーが押されてる間の処理
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE));
}
//キーが押された瞬間の処理
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}
//キーが離されたときの処理

bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE));
}
//キーコードの確認
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}
