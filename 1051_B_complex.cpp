#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	double Ar, Ap, Br, Bp;
	scanf("%lf %lf %lf %lf", &Ar, &Ap, &Br, &Bp);
	double R = Ar * Br;
	double P = Ap + Bp;
	double A = R * cos(P);
	double B = R * sin(P);
	if (abs(A) < 0.01) A = 0;	//对于题目，当计算数字小于0.01当0处理
	if (abs(B) < 0.01) B = 0;	
	if (B >= 0) printf("%0.2lf+%0.2lfi\n", A, B);
	else printf("%0.2lf%0.2lfi\n", A, B);
	return 0;
}