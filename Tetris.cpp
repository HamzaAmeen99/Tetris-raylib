#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}


int main()
{
	InitWindow(500, 620, "Tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/Noxis - Personal Use.ttf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		UpdateMusicStream(game.music);
		game.HandleInput();

		if (EventTriggered(0.2))
		{
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(darkBlue);
		DrawTextEx(font, "Score", {350, 15}, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 360, 200 }, 38, 2, WHITE);
		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER", { 320, 450 }, 25, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

		char scoreText[10];
		sprintf_s(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

		DrawTextEx(font, scoreText, { 320 + (178 - textSize.x) / 2,65 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 245, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}