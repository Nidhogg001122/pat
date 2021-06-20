#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int a, b;
    double max = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &a, &b);
        double r = sqrt(a * a + b * b);
        if (max < r)
            max = r;
    }
    printf("%.2lf", max);
    return 0;
}