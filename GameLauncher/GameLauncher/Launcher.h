#pragma once
#include"AppLoader.h"
#include <Siv3D.hpp>
class Launcher
{
	private:
		Array<Application> applications;
		AppLoader apploader;
		Optional<ChildProcess> procsse;

	public:
		Launcher(const FilePath& path);

		//入力などの処理
		void Update();

		//描画処理
		void Draw()const;

};
