#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	char sell[1010], buy[1010];
	scanf("%s", &sell);
	scanf("%s", &buy);
	int sellnum = strlen(sell), buynum = strlen(buy);
	int temp1 = strlen(sell), temp2 = buynum = strlen(buy);
	int i, j;
	for (i = 0; i < temp2; i++) {
		for (j = 0; j < temp1; j++) {
			if (buy[i] == sell[j]) {
				buynum--;
				sellnum--;
				sell[j] = '-';
				break;
			}
		}
	}
	if (buynum == 0) {
		printf("Yes %d\n", sellnum);
	}
	else printf("No %d\n", buynum);
	return 0;
}