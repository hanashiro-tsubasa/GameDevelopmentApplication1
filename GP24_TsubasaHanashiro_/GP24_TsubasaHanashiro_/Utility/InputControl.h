#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];

public:
	static void Update();                         //更新処理
	
	static bool GetKey(int key_code);             //キーが押されている間の処理
	static bool GetKeyDown(int key_code);         //キーを押した瞬間の処理
	static bool GetKeyUp(int key_code);           //キーを話したときの処理

private:
	static bool CheckKeyCodeRange(int key_code);  //
};

