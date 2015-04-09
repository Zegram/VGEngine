
#pragma once

#include <string>

/// @todo Fix comments in this file

namespace vg
{
    class FileManager;

	/**
		Class for any assets
	*/
	class Asset
	{
		friend class AssetManager;
	public:
		/**
			Constructor for asset
			@param path Filepath for the file
		*/
		Asset(const std::string& path);

		virtual ~Asset() = default;

		/**
			For loading the filemanager
			@param fileManager The manager that manages the files
		*/
        virtual bool load(FileManager& fileManager) = 0;
		
		/**
			Unloads the asset
		*/
		virtual bool unload() = 0;
		
		/**
			@return Returns if the asset is loaded or not
		*/
		bool isLoaded() const;
	protected:
		const std::string mPath; ///< Assets filepath
		bool mIsLoaded = false;  ///< Used for determining whether the asset is loaded or not
	private:
		size_t mUseCount = 1;    ///< The number of how many assets are being used/loaded
	};
}
