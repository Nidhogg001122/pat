#include<cstdio>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int N[2], M[2], num;
    scanf("%d/%d %d/%d %d", &N[0], &M[0], &N[1], &M[1], &num);
    double num1 = (double)N[0] / M[0], num2 = (double)N[1] / M[1];
    if (num1 > num2) {
        double temp = num1;
        num1 = num2;
        num2 = temp;
    }
    bool flag = false;
    for (int i = 1; i < num; i++) {
        double temp = (double)i / num;
        if (num1 < temp && temp < num2 && gcd(i, num) == 1) {
            if (flag == false) flag = true;
            else    printf(" ");
            printf("%d/%d", i, num);
        }
    }
}