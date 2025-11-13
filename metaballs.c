#include <raylib.h>

#define WIDTH  1000
#define HEIGHT 800

int main(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WIDTH, HEIGHT, "Metaballz");
	SetTargetFPS(60);
		
	
	while(IsWindowFocused()){

	}	
	return 0;
}
