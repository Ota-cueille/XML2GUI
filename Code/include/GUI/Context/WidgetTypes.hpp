#pragma once

#include <functional>

struct Position {
	int x, y;
};

struct Dimension {
	int width, height;
};

struct WindowData {
	std::function<void()> Procedure = [this]() {};
	struct {
		Dimension rendering_size;
	} fields;
};

struct ButtonData {
	std::function<void()> Callback = [this]() {};
	struct {
		Position pos;
		Dimension size;
	} fields;
};

struct ImageData {
	std::function<void()> Callback = [this]() {};
	struct {
		Position pos;
		Dimension size;
	} fields;
};
