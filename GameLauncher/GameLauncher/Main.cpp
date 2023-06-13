# include <Siv3D.hpp> // OpenSiv3D v0.6.10

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

}


void Main()
{
	//フルスクリーン
	Window::SetFullscreen(true);
}
