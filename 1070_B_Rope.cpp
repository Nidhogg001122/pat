#include<cstdio>
#include<algorithm>
using namespace std;

//����������ϵ��һ�𣬾���(a+b)/2;�ȼ�������Ӷ��۴���Խ�࣬�ʽ��������ӷ�����󼴿�

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