#include<cstdio>
#include<iostream>
using namespace std;

const int clk = 100;

int main() {
	int begin, end, time;
	cin >> begin >> end;
	time = (int)((end - begin) * 1.0 / 100 + 0.5);//Î´Âú1Ãë°´Ò»Ãë¼ÆËã
	int h, m, s;
	h = time / 3600;
	time = time % 3600;
	m = time / 60;
	s = time % 60;
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}