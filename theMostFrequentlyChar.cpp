#include<cstdio>
#include<cstring>
using namespace std;

char line[1010];

int main() {
	char c;
	int i = 0;
	c = getchar();
	while (c != '\n') {
		line[i++] = c;
		c = getchar();
	}
	int length = i;
	int letters[26] = { 0 };
	for (i = 0; i < length; i++) {
		if (line[i] >= 'a' && line[i] <= 'z') letters[line[i] - 97]++;
		else if (line[i] >= 'A' && line[i] <= 'Z') letters[line[i] - 65]++;
	}
	int max = 0;
	for (i = 0; i < 26; i++) {
		if (letters[max] < letters[i]) max = i;
	}
	printf("%c %d\n", max + 97, letters[max]);
	return 0;
}