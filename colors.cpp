#include "colors.h"

const Color darkGrey = { 26, 31, 40, 255 };
const Color green = { 47, 238, 23, 255 };
const Color red = { 232, 18, 18, 255 };
const Color orange = { 226, 116, 17, 255 };
const Color yellow = { 237, 234, 4, 255 };
const Color purple = { 166, 0, 247, 255 };
const Color cyan = { 21, 204, 209, 255 };
const Color blue = { 13, 64, 216, 255 };
const Color lightBlue = { 59, 85, 162, 255 };
const Color forestGreen = { 20, 50, 20, 255 };
const Color mustard = { 205, 155, 29, 255 };
const Color darkBlue = { 10, 10, 80, 255 };

std::vector<Color> GetCellColors()
{
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}