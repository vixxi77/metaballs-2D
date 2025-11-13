#include <raylib.h>
#include <math.h>

#define WIDTH  1000
#define HEIGHT 800

typedef struct {
	int r;
	int g;
	int b;
} Pixel;

typedef struct {
	int x;
	int y;
	int radius;
} Metaball;

Pixel pixels[WIDTH*HEIGHT];

int main(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WIDTH, HEIGHT, "Metaballz");
	SetTargetFPS(60);
	Metaball metaball = {250, 250, 50};
	int x, y, r2;	
	r2 = metaball.radius*metaball.radius;
		
	
	while(!WindowShouldClose()){
		BeginDrawing();
		for(x = -metaball.radius; x <= metaball.radius; x++){
			y = (int) sqrt(r2 - x*x) + 0.5;
			DrawPixel(metaball.x + x, metaball.y + y, BLUE);
			DrawPixel(metaball.x + x, metaball.y - y, BLUE);
		}
		ClearBackground(WHITE);
		EndDrawing();
	}	
	CloseWindow();
	return 0;
}
