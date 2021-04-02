#include<cstdio>

//��a��b�η���%m�������¿�ʹ��ѭ�����,ʹ�� long long��ֹ���
long long normalPow(long long a, long long b,long long m) {
	long long result = 1;
	for (int i = 1; i <= b; i++) {
		result = result * a % m;	//result�ȳ�a����ģ
	}
	return result;
}

/*����ѭ����������ʱ�临�Ӷ�ΪO(b)����b��С����¿��У�����b����һ��
* �����������ʮ��ʮ���η�ʱ������������ѣ�
* �����ݣ�
* 1.��bΪż����a^b=a^(b/2)*a^(b/2);
* 2.��bΪ������a^b=a*a^(b-1)��
* ���ϣ���bΪż����������֣���bΪ��������2ת������1��
* ����2^5
* 2^5=2*2^4��
* 2^4=2^2*2^2��
* 2^2=2^1*2^1;
* 2^1=2*2^0;
* 2^0=1,	return
*/

//�ɿ����ݵ���ʽ���Կ�������Ϊ�ʺϵݹ�ʵ��
long long quickPow(long long a, long long b, long long m) {
	if (b == 0) return 1;		//bΪ0��a��b=0,����
	if (b&1) return a * quickPow(a, b - 1, m)%m;		//�ж�����,b��������1���а�λ�룬���һλΪ1���������������1
	else {
		long long temp = quickPow(a, b / 2, m);		//�½��м����������quickPow(a, b / 2, m)*quickPow(a, b / 2, m)������һ��ݹ����
		return temp * temp % m;
	}
}

//�ݹ�ʵ�ֵĿ�����ʱ�临�Ӷ�O(logb),�����˼������ޣ�

/*
* ����ʵ�ֵĿ�����Ӧ����ݹ�ʵ�ֵ�Ч����ࣻ
* ����b,�ɽ���ת��Ϊ��������������b=9=1001;
* a^b,���Ա�ʾ��a^(2^k)����a^8,a^4,a^2,a^1��������˻���ÿһ��Ǻ�һ���ƽ������ѡȡ��Щ����b��������������
* ��ʼresultΪ1��
* 1.��b��1��λ�뼴��ֱ�����������һλ�Ƿ�Ϊ1��
* 2.��Ϊ1����result*a����������a^b��������˻����;
* 3.��aƽ������a^(2^k)����a^8,a^4,a^2,a^1�У�ÿһ��Ǻ�һ���ƽ����
* 4.b>0���ظ�1~4��
* 
* ����a^9=a^8*a^1
* 
* b		b&1		a		result
*				a		  1
* 1001	 1		a^2		  a
* 100	 0		a^4		  a
* 10	 0		a^8		  a
* 1		 1		a^16	  a*a^8
*/

long long quick_Pow(long long a, long long b, long long m) {
	long long result = 1;
	while (b > 0) {
		if (b & 1) {
			result = result * a % m;
		}
		a = a * a % m; 
		b >>= 1;
	}
	return result;
}

int main() {
	long long a , b , m ;
	scanf("%lld%lld%lld", &a, &b, &m);
	printf("\n%lld\n", quick_Pow(a, b, m));
}