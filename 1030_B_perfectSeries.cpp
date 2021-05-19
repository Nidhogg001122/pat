#include<cstdio>
#include<algorithm>
using namespace std;

long int series[100010] = { 0 };	//���ݺܴ����漰�˷�������int���ͻ����

int main() {
	long num, p, count, max;
	scanf("%ld %ld", &num, &p);
	long i, j;
	for (i = 0; i < num; i++) {
		scanf("%ld", &series[i]);
	}
	sort(series, series + num);	//��������ݴ�С�������򣬷������
	long temp;
	count = 0, max = 0;
	/*
	* ��ʼʹ��˫��ѭ����
	* ������С��ʼ���������ڲ��series[i]��ʼ�жϴ˺�����Ƿ�С�ڵ���series[i]*p
	* �����򳤶ȼ�һ
	* �������ݽϴ�ʱ˫��ѭ�������Գ�ʱ���������ڲ�ѭ���޸�
	* ��������
	* 6  4
	* 2  3  7  8  11  12
	* 2*4=8
	* �ڵ�һ��ѭ���õ�����count=4
	* ����3��ʼ���㳤��ʱ����Ϊ���ݾ���������2*p>x��������3*pҲ�������
	* ���ڲ�ѭ�����Դ�i+count��ʼ�жϣ�
	* �����Ը���һЩ����������Ϊ����������ǲ������ڲ��i+max��ʼ������ʱ�����㣬˵��series[i]û��
	* ��ǰ���ĳ�������ɵĳ��ȳ����������������У���max=count;ѭ��������
	*/
	for (i = 0; i < num; i++) {
		temp = series[i] * p;
		for (j = i + max; j < num; j++) {
			if (series[j] <= temp) count = j - i + 1;
			else break;	//��ʱ����Ҳ��������ʱ��
		}
		if (count > max) max = count;	 
	}
	printf("%ld\n", max);
	return 0;
}