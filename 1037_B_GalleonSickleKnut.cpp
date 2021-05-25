#include<cstdio>
using namespace std;

struct price {
	long Galleon;
	long Sickle;
	long Knut;
};

int main() {
	struct price shouldpay, realpay, change;
	scanf("%ld.%ld.%ld", &shouldpay.Galleon, &shouldpay.Sickle, &shouldpay.Knut);
	scanf("%ld.%ld.%ld", &realpay.Galleon, &realpay.Sickle, &realpay.Knut);
	long should = shouldpay.Galleon * 17 * 29 + shouldpay.Sickle * 29 + shouldpay.Knut;
	long pay= realpay.Galleon * 17 * 29 + realpay.Sickle * 29 + realpay.Knut;
	long temp = pay - should;
	if (temp < 0) {
		printf("-");
		temp = -temp;
	}
	change.Galleon = temp / (17 * 29);
	temp %= (17 * 29);
	change.Sickle = temp / 29;
	change.Knut = temp % 29;
	printf("%ld.%ld.%ld\n", change.Galleon, change.Sickle, change.Knut);
	return 0;
}