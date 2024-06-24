#include "ResourceManager.h"
#include "DxLib.h"

ResourceManager resource_manager;

//ResourceManager�̃I�u�W�F�N�g���擾����Q�b�^�[
ResourceManager* GetResourceManager()
{
	return &resource_manager;
}

//�R���X�g���N�^
ResourceManager::ResourceManager() : image_container()
{
}

//�f�X�g���N�^
ResourceManager::~ResourceManager()
{

}

//�p�X�̉摜��ǂݍ���ŕԂ��i�P��摜�j
const std::vector<int>& ResourceManager::GetImages(std::string file_path)
{
	//�����̃p�X���ǂݍ��܂�Ă��邩�m�F
	if (image_container.count(file_path) == NULL)
	{
		//�ǂݍ��܂�Ă��Ȃ��̂ŉ摜�f�[�^��ǂݍ��݂܂�
		int handle = LoadGraph(file_path.c_str());

		if (handle == -1)
		{
			//�ǂݍ��ݎ��s
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���");
		}

		//�ǂݍ��߂���A�t�@�C���p�X�̃L�[�Ƀf�[�^���쐬
		image_container[file_path].push_back(handle);
	}
	//�ǂݍ��܂�Ă���摜��Ԃ�
	return image_container[file_path];
}

//�p�X�̉摜��ǂݍ���ŕԂ��i�����摜�j
const std::vector<int>& ResourceManager::GetImages(std::string file_path, int
	all_num, int x_num, int y_num, int x_size, int y_size)
{
	//�����̃p�X���ǂݍ��܂�Ă��邩�m�F
	if (image_container.count(file_path) == NULL)
	{
		//�ǂݍ��܂�Ă��Ȃ��̂ŉ摜�f�[�^��ǂݍ��݂܂�
		int* handle = new int[all_num];

		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num,
			x_size, y_size, handle);

		if (result == 1)
		{
			//2
			//�ǂݍ��ݎ��s
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���");
		}

		//�ǂݍ��߂���A�t�@�C���p�X�̃L�[�Ƀf�[�^���쐬
		for (int i = 0; i < all_num; i++)
		{
			image_container[file_path].push_back(handle[i]);
		}


		delete[] handle;
	}

	return image_container[file_path];
}
//�ǂݍ��񂾉摜�̑S�폜
void ResourceManager::DeleteImages()
{
	//�摜���Ȃ���ΏI��
	if (image_container.size() == NULL)
	{
		return;
	}

	//�S�Ẳ摜���폜����
	for (std::pair<std::string, std::vector<int>>value : image_container)
	{
		DeleteSharingGraph(value.second[0]);
		value.second.clear();
	}

	//���I�z��̏�����
	image_container.clear();
}