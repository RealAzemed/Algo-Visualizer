#include <iostream>
#include "raylib.h"

using namespace std;

struct Bars{
	int height;
	Color color;
};


int main()
{
    InitWindow(1280, 720, "Algorithm Visualizer");

	Bars bars[100];
	SetTargetFPS(180);

	for(auto &bar : bars){
		bar.height = GetRandomValue(10,600);
	}

	for (auto bar : bars){
		cout << bar.height << endl;
	}


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("first commit", 190, 200, 20, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
