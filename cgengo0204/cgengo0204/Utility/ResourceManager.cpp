#include "ResourceManager.h"
#include "DxLib.h"

ResourceManager resource_manager;

//ResourceManagerのオブジェクトを取得するゲッター
ResourceManager* GetResourceManager()
{
	return &resource_manager;
}

//コンストラクタ
ResourceManager::ResourceManager() : image_container()
{
}

//デストラクタ
ResourceManager::~ResourceManager()
{

}

//パスの画像を読み込んで返す（単一画像）
const std::vector<int>& ResourceManager::GetImages(std::string file_path)
{
	//引数のパスが読み込まれているか確認
	if (image_container.count(file_path) == NULL)
	{
		//読み込まれていないので画像データを読み込みます
		int handle = LoadGraph(file_path.c_str());

		if (handle == -1)
		{
			//読み込み失敗
			throw(file_path + "の画像が読み込めませんでした");
		}

		//読み込めたら、ファイルパスのキーにデータを作成
		image_container[file_path].push_back(handle);
	}
	//読み込まれている画像を返す
	return image_container[file_path];
}

//パスの画像を読み込んで返す（分割画像）
const std::vector<int>& ResourceManager::GetImages(std::string file_path, int
	all_num, int x_num, int y_num, int x_size, int y_size)
{
	//引数のパスが読み込まれているか確認
	if (image_container.count(file_path) == NULL)
	{
		//読み込まれていないので画像データを読み込みます
		int* handle = new int[all_num];

		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num,
			x_size, y_size, handle);

		if (result == 1)
		{
			//2
			//読み込み失敗
			throw(file_path + "の画像が読み込めませんでした");
		}

		//読み込めたら、ファイルパスのキーにデータを作成
		for (int i = 0; i < all_num; i++)
		{
			image_container[file_path].push_back(handle[i]);
		}


		delete[] handle;
	}

	return image_container[file_path];
}
//読み込んだ画像の全削除
void ResourceManager::DeleteImages()
{
	//画像がなければ終了
	if (image_container.size() == NULL)
	{
		return;
	}

	//全ての画像を削除する
	for (std::pair<std::string, std::vector<int>>value : image_container)
	{
		DeleteSharingGraph(value.second[0]);
		value.second.clear();
	}

	//動的配列の初期化
	image_container.clear();
}