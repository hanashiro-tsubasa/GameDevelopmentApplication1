#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];  //入力された今のキー
	static char old_key[D_KEYCODE_MAX];  //入力された古いキー

public:
	static void Update();//更新処理

	static bool GetKey(int key_code);      //押してる時の処理
	static bool GetKeyDown(int key_code);  //押した瞬間の処理
	static bool GetKeyUp(int key_code);    //離したときの処理

private:
	static bool CheckKeyCodeRange(int key_code);//キーコードの有効範囲チェック
};
