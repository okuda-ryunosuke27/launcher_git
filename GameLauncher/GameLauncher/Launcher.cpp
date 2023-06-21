#include"Launcher.h"

Launcher::Launcher(const FilePath& path) :apploader(path)
{
	applications = apploader.Load();


	//描画などに必要な変数や関数
}

void Launcher::Update()
{
	//ゲームが起動中だとtrue、そうでない場合falseとなる
	if (procsse)
	{
		if (procsse->isRunning())
		{
			Window::Minimize();//ゲーム起動中はランチャーを最小化
		}
		else
		{
			Window::Restore();//ゲームが終了したらランチャーの最小化を解除
			procsse = none;//ゲームが起動していない状態をセット
		}
	}
	else
	{

	}
}
