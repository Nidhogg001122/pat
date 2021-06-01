#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char input[110][16];

int main() {
	int num;
	scanf("%d", &num);
	getchar(); //使用getchar读取回车，使得之后的getline从下一行开始；
	int i;
	for (i = 0; i < num; i++) cin.getline(input[i],16);
	int len, hight, low, temp, j;
	for (i = 0; i < num; i++) {
		len = strlen(input[i]);
		temp = 0;
		hight = 0;
		low = 0;
		if (input[i][0] >= '0' && input[i][0] <= '9') {
			for (j = 0; j < len; j++) {
				temp = temp * 10 + (input[i][j] - 48);
			}
			hight = temp / 13;
			low = temp % 13;
			if (hight == 1) printf("tam ");
			else if (hight == 2) printf("hel ");
			else if (hight == 3) printf("maa ");
			else if (hight == 4) printf("huh ");
			else if (hight == 5) printf("tou ");
			else if (hight == 6) printf("kes ");
			else if (hight == 7) printf("hei ");
			else if (hight == 8) printf("elo ");
			else if (hight == 9) printf("syy ");
			else if (hight == 10) printf("lok ");
			else if (hight == 11) printf("mer ");
			else if (hight == 12) printf("jou ");
			if (hight == 0 && low == 0) printf("tret\n");
			else if (low == 1) printf("jan\n");
			else if (low == 2) printf("feb\n");
			else if (low == 3) printf("mar\n");
			else if (low == 4) printf("apr\n");
			else if (low == 5) printf("may\n");
			else if (low == 6) printf("jun\n");
			else if (low == 7) printf("jly\n");
			else if (low == 8) printf("aug\n");
			else if (low == 9) printf("sep\n");
			else if (low == 10) printf("oct\n");
			else if (low == 11) printf("nov\n");
			else if (low == 12) printf("dec\n");
		}
		else {
			int j = 0;
			if (input[i][0] == 't' && input[i][1] == 'a' && input[i][2] == 'm') {
				hight = 1;
				j = 4;
			}
			else if (input[i][0] == 'h' && input[i][1] == 'e' && input[i][2] == 'l') {
				hight = 2;
				j = 4;
			}
			else if (input[i][0] == 'm' && input[i][1] == 'a' && input[i][2] == 'a') {
				hight = 3;
				j = 4;
			}
			else if (input[i][0] == 'h' && input[i][1] == 'u' && input[i][2] == 'h') {
				hight = 4;
				j = 4;
			}
			else if (input[i][0] == 't' && input[i][1] == 'o' && input[i][2] == 'u') {
				hight = 5;
				j = 4;
			}
			else if (input[i][0] == 'k' && input[i][1] == 'e' && input[i][2] == 's') {
				hight = 6;
				j = 4;
			}
			else if (input[i][0] == 'h' && input[i][1] == 'e' && input[i][2] == 'i') {
				hight = 7;
				j = 4;
			}
			else if (input[i][0] == 'e' && input[i][1] == 'l' && input[i][2] == 'o') {
				hight = 8;
				j = 4;
			}
			else if (input[i][0] == 's' && input[i][1] == 'y' && input[i][2] == 'y') {
				hight = 9;
				j = 4;
			}
			else if (input[i][0] == 'l' && input[i][1] == 'o' && input[i][2] == 'k') {
				hight = 10;
				j = 4;
			}
			else if (input[i][0] == 'm' && input[i][1] == 'e' && input[i][2] == 'r') {
				hight = 11;
				j = 4;
			}
			else if (input[i][0] == 'j' && input[i][1] == 'o' && input[i][2] == 'u') {
				hight = 12;
				j = 4;
			}
			//tret。地球人数字 1 到 12 的火星文分别为
			//jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec
			if (input[i][j] == 't' && input[i][j + 1] == 'r') low = 0;
			else if (input[i][j] == 'j' && input[i][j + 1] == 'a') low = 1;
			else if (input[i][j] == 'f' && input[i][j + 1] == 'e') low = 2;
			else if (input[i][j] == 'm' && input[i][j + 1] == 'a' && input[i][j + 1] == 'r') low = 3;
			else if (input[i][j] == 'a' && input[i][j + 1] == 'p') low = 4;
			else if (input[i][j] == 'm' && input[i][j + 1] == 'a' && input[i][j + 1] == 'y') low = 5;
			else if (input[i][j] == 'j' && input[i][j + 1] == 'u') low = 6;
			else if (input[i][j] == 'j' && input[i][j + 1] == 'l') low = 7;
			else if (input[i][j] == 'a' && input[i][j + 1] == 'u') low = 8;
			else if (input[i][j] == 's' && input[i][j + 1] == 'e') low = 9;
			else if (input[i][j] == 'o' && input[i][j + 1] == 'c') low = 10;
			else if (input[i][j] == 'n' && input[i][j + 1] == 'o') low = 11;
			else if (input[i][j] == 'd' && input[i][j + 1] == 'e') low = 12;
			temp = 13 * hight + low;
			printf("%d\n", temp);
		}
	}
	return 0;
}