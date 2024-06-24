#pragma once

#include <map>
#include <string>
#include <vector>

//りソースを管理するクラス　（画像とか）
class ResourceManager
{
private:
	//画像格納コンテナ
	std::map<std::string, std::vector<int>> image_container;

public:
	ResourceManager();     //コンストラクタ
	~ResourceManager();    //デストラクタ

	//パスの画像を読み込んで返す（単一画像）
	const std::vector<int>& GetImages(std::string file_path);

	//パスの画像を読み込んで返す（分割画像）
	const std::vector<int>& GetImages(std::string file_path, int all_num, int
		x_num, int y_num, int x_size, int y_size);

	//読み込んだ画像の全削除
	void DeleteImages();
};

ResourceManager* GetResourceManager();

