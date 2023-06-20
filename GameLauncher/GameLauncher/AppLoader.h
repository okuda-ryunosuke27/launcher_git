#pragma once
#include <Siv3D.hpp>
#include"Define.h"

class AppLoader
{
	private:
		//読み込む対象のフォルダ名(今回は./Game)
		FilePath folderpath;

		//引数のパスが示すフォルダ内の.exeを見つけてそのパスを返す
		FilePath SearchExePath(const FilePath& path);

		//引数のパスが示すフォルダ内のscreenshotを見つけてTextureとして読み込み返す
		Texture SearchScreenShot(const FilePath& path);

		//引数のパスが示すフォルダ内のinfo.txtを見つけて1,2行目を読み込みInfo型(自作した構造体)として返す
		Info SearchInfo(const FilePath& path);

		//引数のパスが示すフォルダ内のreadme.txtを見つけて中身を全部読み込んで返す
		String SearchReadMe(const FilePath& paht);

	public:
		//読み込む対象のフォルダのパスを引数としたコンストラクタ
		AppLoader(const FilePath& path);

		//ゲームやスクショなどのデータを全部読み込んでApplication(自作の構造体)の可変長配列として返す
		Array<Application>Load();
};
