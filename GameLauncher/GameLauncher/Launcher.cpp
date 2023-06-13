#include "Launcher.h"
#include <Siv3D.hpp>

launcher::launcher(const FilePath& path) :apploader(path)
{
	applications = apploader.Load();

	//描画などに必要な変数や関数を書く
}

void launcher::Update()
{
	//ゲームが起動中(process != none)だとtrue、そうでない(process == none)場合falseとなる
	if (process)
	{
		if (process->isRunning())
		{
			//ゲーム起動中はランチャーを最小化
			Window::Minimize();
		}
		else
		{
			//ゲームが終了したらランチャーの最小化を解除
			Window::Restore();

			//ゲームが起動しない状態にセット
			process = none;
		}
	}
	else
	{
		//ゲームが起動していない間のランチャーの操作処理

		//ゲームを起動するタイミングで以下の関数を実行
		process = System::CreateProcess(applications[])
	}
}
