#include"AppLoader.h"

Apploader::Apploader(const FilePath& path)
{

}

FilePath Apploader::SearchExePath(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	FilePath exepath;

	for (const auto& file : files)
	{
		if (file.includes(U".exe") == true)
		{
			exepath = file;
			break;
		}
	}

	return exepath;
}

Texture Apploader::SearchTitleScene(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	FilePath tspath;

	for (const auto& file : files)
	{
		if (file.includes(U"titlescene") == true)
		{
			tspath = file;
			break;
		}
	}

	Texture texture_title(tspath);

	return texture_title;
}

Texture Apploader::SearchGameMain(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	FilePath gmpath;

	for (const auto& file : files)
	{
		if (file.includes(U"gamemain") == true)
		{
			gmpath = file;
			break;
		}
	}

	Texture texture_gamemain(gmpath);

	return texture_gamemain;
}

String Apploader::SearchReadMe(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	String readme;
	TextReader reader;

	for (const auto& file : files)
	{
		if (file.includes(U"readme.txt") == true)
		{
			reader.open(file);
			readme = reader.readAll();
			break;
		}
	}

	return readme;
}

Array<Application> Apploader::Load()
{
	//Gameフォルダ内のフォルダの絶対パスが代入される
	Array<FilePath> folders = FileSystem::DirectoryContents(folderpath);
	Array<Application> applications;

	for (unsigned int i = 0; i < folders.size(); i++)
	{
		Application temp = {
			i,
			FileSystem::BaseName(folders[i]),
			SearchExePath(folders[i]),
			SearchTitleScene(folders[i]),
			SearchGameMain(folders[i]),
			SearchReadMe(folders[i]),
		};
		applications.push_back(temp);
	}

	return applications;
}
