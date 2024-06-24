#pragma once

#include <map>
#include <string>
#include <vector>

//��\�[�X���Ǘ�����N���X�@�i�摜�Ƃ��j
class ResourceManager
{
private:
	//�摜�i�[�R���e�i
	std::map<std::string, std::vector<int>> image_container;

public:
	ResourceManager();     //�R���X�g���N�^
	~ResourceManager();    //�f�X�g���N�^

	//�p�X�̉摜��ǂݍ���ŕԂ��i�P��摜�j
	const std::vector<int>& GetImages(std::string file_path);

	//�p�X�̉摜��ǂݍ���ŕԂ��i�����摜�j
	const std::vector<int>& GetImages(std::string file_path, int all_num, int
		x_num, int y_num, int x_size, int y_size);

	//�ǂݍ��񂾉摜�̑S�폜
	void DeleteImages();
};

ResourceManager* GetResourceManager();

