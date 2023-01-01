#include <iostream>
#include <cstring>
using namespace std;

char canvas[1025][2050];
char a = '/', b = '\\', c = ' ', d = '_';

void draw(int n, int x, int y){
	if (n == 1){
		canvas[x][y] = canvas[x][y+3] = c;
		canvas[x][y+1] = canvas[x+1][y] = a;
		canvas[x][y+2] = canvas[x+1][y+3] = b;
		canvas[x+1][y+1] = canvas[x+1][y+2] = d;
		return;
	}
	int k = 1<<(n-1);
	draw(n-1, x, y+k);
	draw(n-1, x+k, y);
	draw(n-1, x+k, y+(k<<1));
}

int main(){
	for (int n; scanf("%d", &n), n; puts("")){
		memset(canvas, c, sizeof canvas);
		draw(n, 1, 1);
		for (int i = 1; i <= (1<<n); ++i){
			canvas[i][(2<<n)+1] = '\0';
			puts(canvas[i]+1);	
		}
	}
}
