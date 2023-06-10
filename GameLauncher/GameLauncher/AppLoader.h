#pragma once
#include <Siv3D.hpp>
#include"Define.h"

class Apploader
{
	private:
		//読み込む対象のフォルダ名(今回は./Game)
		FilePath folderpath;

		//引数のパスが示すフォルダ内の.exeを見つけてそのパスを返す
		FilePath SearchExePath(const FilePath& path);

		//引数のパスが示すフォルダ内のtitlesceneを見つけてTextureとして読み込みを返す
		Texture SearchTitleScene(const FilePath& path);

		//引数のパスが示すフォルダ内のgamemainを見つけてTextureとして読み込みを返す
		Texture SearchGameMain(const FilePath& path);

		//引数のパスが示すフォルダ内のreadme.txtを見つけて中身を全部読み込みを返す
		String SearchReadMe(const FilePath& path);

	public:
		//読み込む対象のフォルダのパスを引数としたコンストラクタ
		Apploader(const FilePath& path);

		//ゲームやスクショなどのデータを全部読み込んでApplication(自作の構造体)の可変長配列として返す
		Array<Application> Load();
};
