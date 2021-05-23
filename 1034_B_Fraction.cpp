#include<cstdio>
#include<algorithm>
using namespace std;

//整型，并不仅仅指int类型
//整型，并不仅仅指int类型
//整型，并不仅仅指int类型

//最大公约数
long gcd(long a, long b) {
	return !b ? a : gcd(b, a % b);
}

//分数的表示可通过定义结构或者使用数组存储
struct fraction {
	long up;
	long down;
};

/*
* 对分数进行约束
* 1.使分母为非负数，当分母为负数时，转为正数，分子为负数
* 2.若分数为0，使分子为0，分母为1
* 3.分子分母最简，即没有1以外的公约数
*
* 根据三条约束条件，可以对分数进行化简
* 1.若分母为负数，使分子分母都取相反数
* 2.若分子为0，使分母为1
* 3.分子分母同时除以它们绝对值的最大公约数
*/

fraction reduction(fraction result) {
	if (result.down < 0) {
		result.down = -result.down;
		result.up = -result.up;
	}
	if (result.up == 0) result.down = 1;
	else {
		long d = gcd(abs(result.up), abs(result.down));
		result.down /= d;
		result.up /= d;
	}
	return result;
}


//分数F1和F2四则运算

//分数加法
fraction add(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.down;
	result.up = F1.up * F2.down + F2.up * F1.down;
	return reduction(result);
}

//分数减法
fraction minu(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.down;
	result.up = F1.up * F2.down - F2.up * F1.down;
	return reduction(result);
}

//分数乘法
fraction multi(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.down;
	result.up = F1.up * F2.up;
	return reduction(result);
}

//分数除法
fraction divide(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.up;
	result.up = F1.up * F2.down;
	return reduction(result);
}

/*
* 分数的展示：
* 化简
* 1.整数即分母为1，输出分子
* 2.分子绝对值大于分母，输出带分数，整数up/down,分子abs(up)%down
* 3.真分数，输出
*/

void show(fraction F) {
	F = reduction(F);
	if (F.up > 0) {
		if (F.up > F.down) {
			printf("%ld", F.up / F.down);
			if (F.up % F.down != 0) printf(" %ld/%ld", F.up % F.down, F.down);
		}
		else if (F.up == F.down) printf("1");
		else printf("%ld/%ld", F.up, F.down);
	}
	else if (F.up < 0) {
		if (abs(F.up) > F.down) {
			printf("(%ld", F.up / F.down);
			if (abs(F.up) % F.down != 0) printf(" %ld/%ld)", abs(F.up) % F.down, F.down);
			else printf(")");
		}
		else if (F.up == -F.down) printf("(-1)");
		else printf("(%ld/%ld)", F.up, F.down);
	}
	else printf("0");
	
}

int main() {
	fraction a, b;
	scanf("%ld/%ld %ld/%ld", &a.up, &a.down, &b.up, &b.down);
	show(a);
	printf(" + ");
	show(b);
	printf(" = ");
	show(add(a, b));
	printf("\n");
	show(a);
	printf(" - ");
	show(b);
	printf(" = ");
	show(minu(a, b));
	printf("\n");
	show(a);
	printf(" * ");
	show(b);
	printf(" = ");
	show(multi(a, b));
	printf("\n");
	show(a);
	printf(" / ");
	show(b);
	printf(" = ");
	if (b.up == 0) printf("Inf");
	else show(divide(a, b));
	printf("\n");
	return 0;
}