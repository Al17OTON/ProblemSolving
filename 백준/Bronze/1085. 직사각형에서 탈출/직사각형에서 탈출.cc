#include <stdio.h>
int x, y, w, h;
int MIN(int a, int b) {return (a > b) ? b : a;}
int main() {
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d", MIN(w - x, MIN(h - y, MIN(x - 0, y - 0))));
}