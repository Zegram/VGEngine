#pragma once
#include "engine/assets/assetManager.h"
#include "engine\graphics\texture.h"
#include "engine/assets/fileManager.h"
#include <string>
namespace vg
{
	
	class Factory
	{
	public:
		Factory(AssetManager *assetManager,FileManager *fileManager);
		~Factory();
		template <typename T>
		T *createRenderComponent(std::string filename)
		{
			T *texComp = new T();
			mAssetManager->load<vg::graphics::Texture>(filename);
			vg::graphics::Texture *texture = mAssetManager->get<vg::graphics::Texture>(filename);
			texture->load(mFileManager);
			texComp->setTexture(texture);
			return texComp;
		}
	private:
		AssetManager *mAssetManager;
		FileManager *mFileManager;
	};

}