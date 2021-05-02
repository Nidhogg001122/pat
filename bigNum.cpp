#include<cstdio>
#include<cstring>
using namespace std;

int r = 0;	//�����е�����

/*
* ����ĳЩ�������֣�����ʹ�û����������ͣ��޷���ȫ���棬�������������
* һЩ��������ݽ��д洢����������ÿһλ���������һ���ռ��У�����ʵ��
* �������㼴�ɶ��µĴ洢��ʽ�´洢�����ݽ�������
*/

/*
* 
*/

struct bignum
{
	int num[1000];	//����洢����;
	int len;		//Ϊ�������㣬���볤��;
	bignum() {		//�޲ι��캯�������ڳ�ʼ��;
		memset(num, 0, sizeof(num));//��ʼ��������numΪ��Ҫ��ֵ���飬0Ϊ������ֵ�����һ������Ϊ��ֵ����
		len = 0;
	}
};

/*
* ������ļ��������ַ�������ʽ���룬���ַ���str="ABC";
* str[0]=A, �ڽ�������ʱ������ϣ�������λ��ʼ���ʴ洢ʱ
* ����ֱ�Ӵ��룬������Ҫ�������ת����
*/

bignum change(char a[]) {
	bignum temp;
	temp.len = strlen(a);
	int j = 0;
	for (int i = temp.len - 1; i >= 0; i--) {
		temp.num[j++] = a[i]-'0';
	}
	return temp;
}

/*
* Ϊ�������㣬����Ҫ�Ƚ������������Ĵ�С��
* �����߳��Ȳ�ͬ���򳤵Ĵ���������ͬ�������λ��ʼ��һ�Ƚ�
*/

int compare(bignum a, bignum b) {	//a�󷵻�1��aС����-1����ȷ���0;
	if (a.len > b.len) return 1;
	else if (a.len < b.len) return -1;
	else {
		for (int i = a.len - 1; i >= 0; i--) {
			if (a.num[i] > b.num[i]) return 1;
			else if (a.num[i] < b.num[i]) return -1;
		}
	}
	return 0;
}

void myprintf(bignum temp) {
	for (int i = temp.len - 1; i >= 0; i--) {
		printf("%d", temp.num[i]);
	}
	printf("\n");
}

/*
* ����������ĸ߾��ȼӷ������������ĵ�ǰλ��ӣ��ټ��Ͻ�λ
* ������10����ȡģ������������10�õ���������Ϊ��λ������һλ����
* �����и����ļ��㣬���ݾ������ת��
*/

bignum add(bignum a, bignum b) {
	bignum c;
	int next = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int tempnum = a.num[i] + b.num[i] + next;
		c.num[c.len++] = tempnum % 10;
		next = tempnum / 10;
	}
	if (next != 0) {		//�ӷ���λ�����ܳ���9������������н�λ��ֱ�Ӹ�ֵ���ɣ�
		c.num[c.len++] = next;
	}
	return c;
}

/*
* ���ڼ���������ϣ�����Ǵ������ȥС�������ڵ��ô˺���ǰ���н�����
* ������ӷ��Ĳ�ͬ���ǽ���λ��Ϊ��λ
*/

bignum sub(bignum a, bignum b) {
	bignum c;
	for (int i = 0; i < a.len || i < b.len; i++) {
		if (a.num[i] < b.num[i]) {
			a.num[i + 1]--;
			a.num[i] += 10;
		}
		c.num[c.len++] = a.num[i] - b.num[i];
	}
	while (c.len - 1 >= 1 && c.num[c.len - 1] == 0) {	//��������ڽ�λ����λ����ܴ��ڸ�λΪ0
		c.len--;	//��ȥ��λΪ0��������������������һλ��
	}
	return c;
}

/*
* ���������ĳ˷��ڴ�ֻ����߾�����;���(��������������)�˷�,�߾���֮������
* �����ڸ߾��ȼӷ�����ÿһλ�ڵ;�����ˣ����Ͻ�λ����10����õ���λ������10�ý�λ��
*    1  2  3
* x	    1  5
* ----------
*	    4  5
*    3  0
* 1  5
* -----------
* 1  8  4  5
*/

bignum multi(bignum a, int b) {
	bignum c;
	int next = 0;
	for (int i = 0; i < a.len; i++) {
		int tempnum = a.num[i] * b + next;
		c.num[c.len++] = tempnum % 10;
		next = tempnum / 10;
	}
	while (next != 0) {	//���ڳ˷�����ӷ���ͬ�����Ľ�λ���ܲ�ֻһλ
		c.num[c.len++] = next % 10;
		next = next / 10;
	}
	return c;
}

/*
* �������������㲻ͬ��������Ҫ�����λ��ʼ��
* ��ǰλ�����Գ�ʱ��λ��Ϊ0��������Ϊ��λ����ȥ��
* ���ջ��豣��������
*/

bignum divide(bignum a, int b) {
	bignum c;
	c.len = a.len;
	for (int i = a.len - 1; i >= 0; i--) {
		r = r * 10 + a.num[i];
		if (r < b) c.num[i] = 0;
		else {
			c.num[i] = r / b;
			r = r % b;
		}
	}
	while (c.len - 1 >= 1 && c.num[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}

int main() {
	char num1[36], num2[36];
	scanf("%s%s", &num1,&num2);
	bignum a, b;
	int c = 2;
	a = change(num1);
	b = change(num2);
	printf("a=");
	myprintf(a);
	printf("b=");
	myprintf(b);
	printf("a+b=");
	myprintf(add(a, b));
	printf("a-b=");
	myprintf(sub(a, b));
	printf("a*2=");
	myprintf(multi(a, c));
	printf("a/2=");
	myprintf(divide(a, c));
	printf("����Ϊ��%d", r);
	return 0;
}