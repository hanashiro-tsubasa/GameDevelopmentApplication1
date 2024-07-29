#pragma once

enum class ePlayerState : unsigned char
{
	IDLE = 0,  //停止状態
	RUN,       //移動状態
	JUMP,      //ジャンプ状態
	NONE       //なにもない
};
