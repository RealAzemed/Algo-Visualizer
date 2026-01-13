#include <iostream>
#include "raylib.h"

using namespace std;

struct Bars{
    float height;
    Color color;
};

int i = 0;
int j = 0;

void ShuffleArray(Bars bars[], int length){
    for(int k = 0; k < length; k++){
        bars[k].height = GetRandomValue(10, 750);
        bars[k].color = RED;
    }
    i = 0;
    j = 0;
}

void BubbleSort(Bars array[], int length) {
    if (i >= length - 1){
		WaitTime(10);
        ShuffleArray(array, length);
        return;
    }

    if (array[j].height > array[j + 1].height) {
        Bars temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        
    }

    j++;
    if (j >= length - i - 1) {
        array[j].color = GREEN; 
        
        j = 0;
        i++;
    }
}

int main()
{
    const float screen_width = 1600;
    const float screen_height = 900;

    InitWindow(screen_width, screen_height, "Algorithm Visualizer");
    
    const int size = 100; 
    Bars bars[size];
    
    SetTargetFPS(180); 

    ShuffleArray(bars, size);

    while (!WindowShouldClose())
    {
        BubbleSort(bars, size);
        
        BeginDrawing();
            ClearBackground(BLACK);
            
            float x = 0;
            // Calculate width dynamically
            float barWidth = screen_width / size; 

            for(const auto &bar : bars)
            {
                Rectangle rec = {x, screen_height - bar.height, barWidth, bar.height};
                
                DrawRectangleRec(rec, bar.color);
                
                if (barWidth > 5) {
                    DrawRectangleLinesEx(rec, 1, RAYWHITE);
                }
                
                x += barWidth;
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
