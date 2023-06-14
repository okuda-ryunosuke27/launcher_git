# include <Siv3D.hpp> // OpenSiv3D v0.6.10

/**
* UIオプションの設定
* 各タイルのサイズだったり
* 色だったりを設定しています。
*/
namespace UI
{
	//タイルの基本サイズ
	constexpr double TileSize = 250;

	//背景色
	constexpr ColorF BackGroundColor{ 0.85, 0.9, 0.95 };

	//タイル選択の色
	constexpr ColorF TileFrmaeColor{ 1.0, 0.7, 0.3 };

	constexpr Vec2 BaseTilePos{ 240, 200 };

	constexpr RectF InfoArae{ 180, 340, 715, 185 };

	constexpr RectF StaffAree{ 180, 530, 715, 70 };

	constexpr RectF PlayButton{ 900, 340, 220, 85 };

	constexpr ColorF PlayButtonColor{ 0.0, 0.67, 1.0 };

	constexpr RectF ControlArea{ 900, 430, 220, 170 };

	constexpr ColorF InfoAreaMouseOverColor{ 1.0, 0.95, 0.9 };

	constexpr ColorF TextColor{ 0.2 };

	constexpr double InfoAreaRound = 8.0;
}

/**
* 構造体の概要
* ランチャーに格納するゲームの情報
*/
struct Game
{
	// ゲームのタイトル
	String title;

	// ゲーム実行ファイル または URL
	FilePath path;

	//ゲームの説明文
	String desc;

	//ランチャーの表示優先度
	int32 priority = 0;
};

/**
* ゲーム情報をロードする関数
*/
Array<Game> LoadGames()
{
	//ゲームリスト
	Array<Game> games;

	//ホームディレクトリ
	const FilePath homeDirectory = FileSystem::CurrentDirectory();

	//ホームディレクトリにあるitemを検索
	for (const FilePath& gameDirectory : FileSystem::DirectoryContents(homeDirectory, Recursive::No))
	{
		//フォルダでない時はスキップ
		if (not FileSystem::IsDirectory(gameDirectory))
		{
			continue;
		}
	}
}


void Main()
{
	//フルスクリーン
	Window::SetFullscreen(true);
}
