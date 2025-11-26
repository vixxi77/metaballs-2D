#include <raylib.h>
#include <math.h>

#define WIDTH  1000
#define HEIGHT 800

typedef struct {
	int x, y;
	int radius;
} Metaball;

void 
draw_circle(Metaball *metaball, const Color *_color){
	int x, y, r2, height;	
	r2 = metaball->radius*metaball->radius;

	for(x = -metaball->radius; x <= metaball->radius; x++){
		height = (int)sqrt((double)(r2 - x * x) + 0.5);
		for(y = -height; y <= height; y++){
			DrawPixel(metaball->x + x, metaball->y + y, *_color);	
		}
	}
}

void 
draw_metaball(Metaball *metaball, const Color *_color, double _threshold, int _count){
	int x, y;	
	for(y = 0; y < HEIGHT; y++){
		for(x = 0; y < WIDTH; x++){
			double field = 0.0;
		
			for(int i = 0; i < _count; i++){
				double dx = x - metaball[i].x;
				double dy = y - metaball[i].y;
				double r2 = metaball[i].radius * metaball[i].radius;
				
				field += r2 / (dx*dx + dy*dy + 1e-6);
			}
			if(field > _threshold){
				DrawPixel(x, y, *_color);
			}
		}
	}
}

void 
circle_follow_cursor(Metaball *metaball){
	metaball->x = GetMousePosition().x;
	metaball->y = GetMousePosition().y;
}


int main(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WIDTH, HEIGHT, "Metaballz");
	SetTargetFPS(60);
	Metaball metaball = {400, 400, 100};
	Metaball metaball1 = {200, 200, 100};

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(WHITE);
		circle_follow_cursor(&metaball);
		draw_circle(&metaball, &BLUE);
		draw_circle(&metaball1, &RED);
		//draw_metaball(balls, &RED, 2, 1.0);
		DrawFPS(10, 10);
		EndDrawing();
	}	
	CloseWindow();
	return 0;
}
