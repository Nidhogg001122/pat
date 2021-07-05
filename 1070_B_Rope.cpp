#include<cstdio>
#include<algorithm>
using namespace std;

//将两根绳子系在一起，就是(a+b)/2;先加入的绳子对折次数越多，故将长的绳子放在最后即可

int rope[10010];

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &rope[i]);
	sort(rope, rope + n);
	int length = rope[0];
	for (i = 1; i < n; i++) length = (length + rope[i]) / 2;
	printf("%d\n", length);
	return 0;
}