#include"AppLoader.h"

AppLoader::AppLoader(const FilePath& path) :folderpath(path)
{

}

FilePath AppLoader::SearchExePath(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	FilePath exepath;

	for (const auto& file : files) {
		if (file.includes(U".exe") == true) {
			exepath = file;
			break;
		}
	}

	return exepath;
}

Texture AppLoader::SearchScreenShot(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	FilePath sspath;

	for (const auto& file : files) {
		if (file.includes(U"screenshot") == true) {
			sspath = file;
			break;
		}
	}

	Texture texture(sspath);

	return texture;
}

Info AppLoader::SearchInfo(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	Info info;
	TextReader reader;

	for (const auto& file : files) {
		if (file.includes(U"info.txt") == true) {
			reader.open(file);
			reader.readLine(info.kind);
			reader.readLine(info.usingtext);
			break;
		}
	}

	return info;
}

String AppLoader::SearchReadMe(const FilePath& path)
{
	Array<FilePath> files = FileSystem::DirectoryContents(path);
	String readme;
	TextReader reader;

	for (const auto& file : files) {
		if (file.includes(U"readme.txt") == true) {
			reader.open(file);
			readme = reader.readAll();
			break;
		}
	}

	return readme;
}

Array<Application> AppLoader::Load()
{
	Array<FilePath> folders = FileSystem::DirectoryContents(folderpath);//Gameフォルダ内のフォルダの絶対パスが代入される（「C:Users/(なんたらかんたら)/game/旅するナイト/」の形）
	Array<Application> applications;

	for (unsigned int i = 0; i < folders.size(); i++) {
		Application temp = { i,FileSystem::BaseName(folders[i]),SearchExePath(folders[i]),SearchScreenShot(folders[i]),SearchInfo(folders[i]),SearchReadMe(folders[i]) };//「なんちゃら/game/ぜんら」でも「なんちゃら/game/ぜんら/」でも挙動は同じ？
		applications.push_back(temp);
	}

	return applications;
}
