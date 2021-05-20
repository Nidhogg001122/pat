#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	int num, i, j, right, sum, count = 0;
	char id[32];
	scanf("%d", &num);
	int weight[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char check[] = { '1','0','X','9','8','7','6','5','4','3','2' };
	for (i = 0; i < num; i++) {
		scanf("%s", &id);
		right = 1;
		sum = 0;
		for (j = 0; j < 17; j++) {
			if (id[j] < '0' || id[j]>'9') {
				right = 0;
				break;
			}
			sum += ((id[j] - '0') * weight[j]);
		}
		if (right == 0) {
			printf("%s\n", id);
			count++;
		}
		else {
			sum = sum % 11;
			if (check[sum] != id[17]) {
				printf("%s\n", id);
				count++;
			}
		}
	}
	if (count == 0) printf("All passed\n");
	return 0;
}