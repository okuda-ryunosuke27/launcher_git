#pragma once
#include <Siv3D.hpp>

//info.txtを読み込んで保存する用
struct Info
{
	String kind;
	String usingtext;
};

//.exeのパスやスクショなど読み込んだものをまとめて保存する用
struct Application
{
	unsigned int id;
	String name;
	FilePath exepath;
	Texture screenshot;
	Info info;
	String readme;
};
