#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	int num, i = 0, length = 0, j = 0;
	int result[11] = { 0 };
	char c, line[101];
	scanf("%d", &num);
	scanf("%c", &c);
	while (i < num) {
		j = 0;
		scanf("%c", &c);
		while (c != '\n')
		{
			line[j++] = c;
			scanf("%c", &c);
		}
		length = j;
		j = 0;
		while(j<length) {
			c = line[j++];
			if (c == 'P' || c == 'A' || c == 'T' || c == ' ') {
				continue;
			}
			else {
				result[i] = 1;
				break;
			}
		}
		if (!result[i]) {
			for (j = 0; j < length; j++) {
				c = line[j];
				if (c == 'P') {
					if (j + 1 < length && (j + 2) < length && line[j + 1] == 'A' && line[j + 2] == 'T') result[i] = 2;
					else if (j + 1 < length && (j + 2) < length && (j + 3) < length && (line[j + 1] == 'A' || line[j + 2] == 'A') && line[j + 3] == 'T')result[i] = 2;
					if (result[i] == 2) break;
				}
			}
		}
		i++;
	}
	for (i = 0; i < num; i++) {
		if (result[i] == 2) printf("YES\n");
		else printf("NO\n");
	}
}