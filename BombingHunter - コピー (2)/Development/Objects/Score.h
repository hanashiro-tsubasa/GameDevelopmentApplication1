#pragma once
#include"GameObject.h"

class Score : public GameObject
{
private:
	int kazuimage[10];         //数字の画像
	int text1;           //テキストの画像
	int text2;           //テキストの画像
	int timer;
public:
	Score();
	~Score();

	//初期化処理
	virtual void Initialize() override;
	//更新処理
	virtual void Update() override;
	//描画処理
	virtual void Draw() const override;
	//終了時処理
	virtual void Finalize() override;

};


