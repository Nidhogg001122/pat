#include<cstdio>
using namespace std;

int main() {
	int n, i;
	scanf("%d", &n);
	int a_say, b_say, a_finger, b_finger, a_loss = 0, b_loss = 0;
	int sum;
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a_say, &a_finger, &b_say, &b_finger);
		sum = a_say + b_say;
		if ((a_finger == sum && b_finger == sum) || (a_finger != sum && b_finger != sum)) continue;
		else if (a_finger == sum && b_finger != sum) b_loss++;
		else a_loss++;
	}
	printf("%d %d\n", a_loss, b_loss);
	return 0;
}