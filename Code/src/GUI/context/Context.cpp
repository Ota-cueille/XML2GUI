#include "GUI/Context/Context.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

namespace GUI
{
	static struct WindowData
	{
		GLFWwindow* handle;
		int width, height;
		const char* name;
	} s_WindowData;

	static std::unique_ptr<GLFWwindow> s_Window = nullptr;

	void Init(const char* name, int width, int height) {
		glfwInit();

		s_Window = std::make_unique<GLFWwindow>(glfwCreateWindow(width, height, name, nullptr, nullptr));
		glfwMakeContextCurrent(s_Window.get());

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		s_WindowData.handle = s_Window.get();
		s_WindowData.width = width;
		s_WindowData.height = height;
		s_WindowData.name = name;
	}

	void Loop() {
		while(not glfwWindowShouldClose(s_WindowData.handle)) {
			// call active window
			glfwPollEvents();
		}
	}

	void Terminate() {
		s_Window.release();
		glfwTerminate();
	}

} // namespace GUI
