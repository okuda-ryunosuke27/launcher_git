#pragma once
#include <Siv3D.hpp>

//.exeのパスやスクショなど読み込んだものをまとめて保存
struct Application
{
	unsigned int id;
	String name;
	FilePath exepath;
	Texture titlescene;
	Texture gamemain;
	String readme;
};
