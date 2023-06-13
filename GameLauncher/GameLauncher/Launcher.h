#pragma once
#include <Siv3D.hpp>
#include "Define.h"
#include "AppLoader.h"

#undef CreateProcess

class launcher
{
	private:
		Array<Application> applications;
		Apploader apploader;
		Optional<ChildProcess> process;

	public:
		launcher(const FilePath& path);

		void Update();
		void Draw() const;
};
