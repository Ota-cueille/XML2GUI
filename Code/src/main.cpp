#include "GUI/Gui.hpp"
#include "GUI/Cache/converted_files.hpp"

int main(int argc, char* argv[]) {
	GUI::Init("Application", 500, 500);

	Window1::window.Procedure = [&self=Window1::window]()
	{
		self.fields.rendering_size.height = 100;
	};

	Window1::Button::open_file.Callback = []() { };

	GUI::Loop();
	GUI::Terminate();

	return 0;
}
