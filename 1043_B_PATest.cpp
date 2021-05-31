#include<cstdio>
using namespace std;

int main() {
	int Pnum = 0, Anum = 0, Tnum = 0, nume = 0, snum = 0, tnum = 0;//enum无法作为变量使用
	char c;
	c = getchar();
	while (c != '\n') {
		if (c == 'P') Pnum++;
		else if (c == 'A') Anum++;
		else if (c == 'T') Tnum++;
		else if (c == 'e') nume++;
		else if (c == 's') snum++;
		else if (c == 't') tnum++;
		c = getchar();
	}
	while (Pnum || Anum || Tnum || nume || snum || tnum) {
		if (Pnum) {
			printf("P");
			Pnum--;
		}
		if (Anum) {
			printf("A");
			Anum--;
		}
		if (Tnum) {
			printf("T");
			Tnum--;
		}
		if (nume) {
			printf("e");
			nume--;
		}
		if (snum) {
			printf("s");
			snum--;
		}
		if (tnum) {
			printf("t");
			tnum--;
		}
	}
	printf("\n");
	return 0;
}