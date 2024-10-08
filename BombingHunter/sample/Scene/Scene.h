#pragma once

#include "../Objects/GameObject.h"
#include<vector>
//#include<string>

class Scene
{
private:
	std::vector<GameObject*> objects;  //オブジェクトリスト

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	//当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);

	//オブジェクト生成処理
	template<class T>
	T* CreateObject(const Vector2D& location,const Vector2D& vector)
	{
		//指定したクラスをのオブジェクトを生成する
		T* new_instance = new T();
		//GameObjectが継承されているか確認する
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw /*std::string*/("GameObjectが生成できませんでした\n");
		}

		//初期化処理
		new_object->Initialize();

		//位置情報の設定
		new_object->SetLocation(location);

		new_object->SetBulletVector(vector);

		//シーン内に存在するオブジェクトリストに追加
		objects.push_back(new_object);

		//生成したオブジェクトのポインタを返却
		return new_instance;
	}


};

