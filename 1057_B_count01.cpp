#include<cstdio>
using namespace std;

int main() {
	long long sum = 0, zero = 0, one = 0;
	char c;
	c = getchar();
	while (c != '\n') {
		if (c >= 'A' && c <= 'Z') sum += (c - 64);
		else if (c >= 'a' && c <= 'z') sum += (c - 96);
		c = getchar();
	}
	int rem;
	while (sum) {
		rem = sum % 2;
		if (rem == 0) zero++;
		else one++;
		sum /= 2;
	}
	printf("%lld %lld\n", zero, one);
	return 0;
}