#include<iostream>
#include<math.h>

using namespace std;

//��Ȼ�ױض�Ϊ��λ������������ȴ����Ϊ��������
//ͬʱ����Ϊ��λ�������Ա���ѭ�����Ӽ����ʼѭ����

int main() {
    double a, b, c, x, y, M, output[3];
    scanf("%lf %lf %lf", &M, &x, &y);
    bool flag = false;
    for (a = 9; a > 0; a--) {
        for (b = 9; b >= 0; b--) {
            double n = (b * 10 + a) / y;
            if (fabs(a * 10 + b - b * 10 - a) / x == n) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag == false)
        printf("No Solution");
    else {
        output[0] = (a * 10 + b);
        output[1] = (b * 10 + a);
        output[2] = (output[1] / y);
        printf("%.0lf", output[0]);
        for (int i = 0; i < 3; i++) {
            if (output[i] < M)
                printf(" Gai");
            else if (output[i] == M)
                printf(" Ping");
            if (output[i] > M)
                printf(" Cong");
        }
    }
    printf("\n");
    return 0;
}