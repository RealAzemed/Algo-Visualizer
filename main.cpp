#include <iostream>
#include "raylib.h"

using namespace std;

struct Bars{
	float height;
	Color color;
};

void BubbleSort(Bars array[], int length) {

	//used static variables so it can remember em
    static int i = 0;
    static int j = 0;

    if (i >= length - 1) return;

    if (array[j].height > array[j + 1].height) {
        Bars temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
    }

    j++;
    if (j >= length - i - 1) {
        j = 0;
        i++;
    }
}
int main()
{
	float screen_width = 1600;
	float screen_height = 900;

    InitWindow(screen_width, screen_height, "Algorithm Visualizer");
	int size = 400;
	Bars bars[size];
	SetTargetFPS(180);

	for(auto &bar : bars){
		bar.height = GetRandomValue(10,750);
		bar.color = RED;
	}

	for (auto bar : bars){
		cout << bar.height << endl;
	}


    while (!WindowShouldClose())
    {
		BubbleSort(bars, size);
        BeginDrawing();
            ClearBackground(BLACK);
			float i = 0;
			for(const auto &bar : bars)
			{

				Rectangle rec = {i, screen_height - bar.height, screen_width/size, bar.height};
				DrawRectangleRec(rec, RED);
				DrawRectangleLinesEx(rec, 3 , RAYWHITE);
				i += screen_width/size;
			}

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
