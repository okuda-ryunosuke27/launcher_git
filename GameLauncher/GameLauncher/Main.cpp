//# include <Siv3D.hpp> // OpenSiv3D v0.6.10
//
///**
//* UIオプションの設定
//* 各タイルのサイズだったり
//* 色だったりを設定しています。
//*/
//namespace UI
//{
//	//タイルの基本サイズ
//	constexpr double TileSize = 250;
//
//	//背景色
//	constexpr ColorF BackGroundColor{ 0.85, 0.9, 0.95 };
//
//	//タイル選択の色
//	constexpr ColorF TileFrmaeColor{ 1.0, 0.7, 0.3 };
//
//	constexpr Vec2 BaseTilePos{ 240, 200 };
//
//	constexpr RectF InfoArae{ 180, 340, 715, 185 };
//
//	constexpr RectF StaffAree{ 180, 530, 715, 70 };
//
//	constexpr RectF PlayButton{ 900, 340, 220, 85 };
//
//	constexpr ColorF PlayButtonColor{ 0.0, 0.67, 1.0 };
//
//	constexpr RectF ControlArea{ 900, 430, 220, 170 };
//
//	constexpr ColorF InfoAreaMouseOverColor{ 1.0, 0.95, 0.9 };
//
//	constexpr ColorF TextColor{ 0.2 };
//
//	constexpr double InfoAreaRound = 8.0;
//}
//
///**
//* 構造体の概要
//* ランチャーに格納するゲームの情報
//*/
//struct Game
//{
//	// ゲームのタイトル
//	String title;
//
//	// ゲーム実行ファイル または URL
//	FilePath path;
//
//	//ゲーム画面
//	Texture texture;
//
//	//ゲームの説明文
//	String desc;
//
//	//ランチャーの表示優先度
//	int32 priority = 0;
//};
//
///**
//* ゲーム情報をロードする関数
//*/
//Array<Game> LoadGames()
//{
//	//ゲームリスト
//	Array<Game> games;
//
//	//ホームディレクトリ
//	const FilePath homeDirectory = FileSystem::CurrentDirectory();
//
//	//ホームディレクトリにあるアイテムを検索
//	for (const FilePath& gameDirectory : FileSystem::DirectoryContents(homeDirectory, Recursive::No))
//	{
//		//フォルダでない時はスキップ
//		if (not FileSystem::IsDirectory(gameDirectory))
//		{
//			continue;
//		}
//
//		//launcher_infoを読み込む
//		const FilePath iniPath = (gameDirectory + U"launcher_info.txt");
//		const INI ini{ iniPath };
//
//		//読み込み失敗
//		if (not ini)
//		{
//			continue;
//		}
//
//		//ゲーム情報を読み込む
//		Game game;
//		game.title = ini[U"Game.title"];
//		game.texture = Texture{ Image{ gameDirectory + ini[U"game.image"] }.squareClipped(),TextureDesc::Mipped };
//		game.desc = ini[U"Game.desc"].replaced(U"\\n", U"\n");
//		game.priority = ini.get<int32>(U"Game.priority");
//
//		const String path = game.path = ini[U"Game.path"];
//
//		games << game;
//	}
//
//	//プライオリティに基づいてゲームをソート
//	return games.sort_by([](const Game& a, const Game& b) {return a.priority > b.priority; });
//}
//
//
//void Main()
//{
//	//フルスクリーン
//	Window::SetFullscreen(false);
//	Scene::SetBackground(UI::BackGroundColor);
//
//	//フォント
//	FontAsset::Register(U"Game.Title", 42, Typeface::Heavy);
//	FontAsset::Register(U"Game.Desc", 26);
//	FontAsset::Register(U"Game.Small", 16);
//	FontAsset::Register(U"Game.Play", 30,Typeface::Heavy);
//
//	//再生アイコン
//	TextureAsset::Register(U"Icon.Play", 0xf144_icon, 48);
//
//	//ゲーム情報
//	const Array<Game> games = LoadGames();
//	if (not games)
//	{
//		System::MessageBoxOK(U"ゲームがありません。");
//		return;
//	}
//
//	//実行中のゲームのプロセス
//	Optional<ChildProcess> process;
//
//	//選択しているタイルのインデックス[0, games.size() - 1]
//	size_t selectGameIndex = 0;
//
//	//タイルのスクロール用の変数
//	double tileOffsetX = 0.0, targetTileOffsetX = 0.0, tileOffsetXVelocity = 0.0;
//
//	while (System::Update())
//	{
//		//現在選択されているゲーム
//		const Game& game = games[selectGameIndex];
//
//		//ウィンドウの最小化と復帰
//		if (process)
//		{
//			//プロセスが実行中なら
//			if (process->isRunning())
//			{
//				//ウィンドウを最小化
//				Window::Minimize();
//				continue;
//			}
//			else//プロセスが終了したら
//			{
//				//ウィンドウを復帰
//				Window::Restore();
//				process.reset();
//			}
//		}
//
//		//ゲームの軌道
//		if (UI::PlayButton.leftClicked())
//		{
//			process = ChildProcess{ game.path };
//		}
//
//		//選択しているタイルの変更
//		for (auto i : step(games.size()))
//		{
//			const Vec2 center = UI::BaseTilePos.movedBy(tileOffsetX + i * UI::TileSize, 0);
//			const RectF tile{ Arg::center = center,(UI::TileSize - 20) };
//
//			//タイルがクリックされたら選択
//			if (tile.leftClicked())
//			{
//				selectGameIndex = i;
//			}
//		}
//
//		if (KeyLeft.down())
//		{
//			selectGameIndex = (selectGameIndex > 0) ? (selectGameIndex - 1) : 0;
//		}
//		else if (KeyRight.down())
//		{
//			selectGameIndex = Min(selectGameIndex + 1, games.size() - 1);
//		}
//
//		//タイル表示のスクロール更新
//		const Vec2 center = UI::BaseTilePos.movedBy(targetTileOffsetX + selectGameIndex * UI::TileSize, 0);
//		const RectF tile{ Arg::center = center,(UI::TileSize - 20) };
//
//		//左端、右端のタイルが画面外ならスクロール
//		if (tile.x <= 0)
//		{
//			targetTileOffsetX += UI::TileSize;
//		}
//		else if (Scene::Width() <= tile.tr().x)
//		{
//			targetTileOffsetX -= UI::TileSize;
//		}
//
//
//		//スムーズスクロール
//		tileOffsetX = Math::SmoothDamp(tileOffsetX, targetTileOffsetX, tileOffsetXVelocity, 0.1);
//
//
//		//描画
//		for (auto [i, g] : Indexed(games))
//		{
//			const Vec2 center = UI::BaseTilePos.movedBy(tileOffsetX + i * UI::TileSize, 0);
//			const RectF tile{ Arg::center = center,(UI::TileSize - 20) };
//
//			//選択されたいたら、タイルの枠を描画
//			if (selectGameIndex == i)
//			{
//				tile.stretched(6)
//					.drawShadow(Vec2{ 0,3 }, 8, 0)
//					.draw(UI::BackGroundColor)
//					.drawFrame(4, 0, ColorF(UI::TileFrmaeColor, 0.6 + Periodic::Sine0_1(1s) * 0.4));
//			}
//
//			//ゲーム画像を描画
//			tile(g.texture).drawAt(center);
//
//			if (tile.mouseOver())
//			{
//				Cursor::RequestStyle(CursorStyle::Hand);
//			}
//		}
//
//		//タイトルと説明
//		UI::StaffAree.rounded(UI::InfoAreaRound).draw(UI::InfoArae.mouseOver() ? UI::InfoAreaMouseOverColor : ColorF(1.0));
//		FontAsset(U"Game.Title")(game.title).draw(UI::InfoArae.pos.movedBy(30, 20), UI::TextColor);
//		FontAsset(U"Game.Desc")(game.desc).draw(UI::InfoArae.stretched(-80, -30, -20, -30), UI::TextColor);
//
//	}
//}
