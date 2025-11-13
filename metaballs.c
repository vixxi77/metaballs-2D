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
	int x, y;
	int radius;
} Metaball;

void draw_circle(Metaball *metaball){
	int x, y, r2, height;	
	r2 = metaball->radius*metaball->radius;

	for(x = -metaball->radius; x <= metaball->radius; x++){
		height = (int)sqrt((double)(r2 - x * x));
		for(y = -height; y <= height; y++){
			DrawPixel(metaball->x + x, metaball->y + y, BLUE);	
		}
	}

}

void circle_follow_cursor(Metaball *metaball){
	metaball->x = GetMousePosition().x;
	metaball->y = GetMousePosition().y;
}


int main(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WIDTH, HEIGHT, "Metaballz");
	SetTargetFPS(60);
	Metaball metaball = {400, 400, 100};
	
	while(!WindowShouldClose()){
		BeginDrawing();
		circle_follow_cursor(&metaball);
		draw_circle(&metaball);
		ClearBackground(WHITE);
		EndDrawing();
	}	
	CloseWindow();
	return 0;
}
