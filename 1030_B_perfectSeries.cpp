#include<cstdio>
#include<algorithm>
using namespace std;

long int series[100010] = { 0 };	//数据很大并且涉及乘法，仅用int类型会溢出

int main() {
	long num, p, count, max;
	scanf("%ld %ld", &num, &p);
	long i, j;
	for (i = 0; i < num; i++) {
		scanf("%ld", &series[i]);
	}
	sort(series, series + num);	//输入的数据从小到大排序，方便操作
	long temp;
	count = 0, max = 0;
	/*
	* 开始使用双重循环，
	* 外层从最小开始遍历，在内层从series[i]开始判断此后的数是否小于等于series[i]*p
	* 满足则长度加一
	* 但在数据较大时双重循环将测试超时，考虑在内层循环修改
	* 假设输入
	* 6  4
	* 2  3  7  8  11  12
	* 2*4=8
	* 在第一次循环得到长度count=4
	* 当从3开始计算长度时，因为数据经过了排序，2*p>x成立，则3*p也会大于它
	* 故内层循环可以从i+count开始判断，
	* 还可以更大胆一些，最终所求为长度最大，我们不妨在内层从i+max开始，若此时不满足，说明series[i]没有
	* 比前面的某个数构成的长度长，若满足完美数列，则将max=count;循环至结束
	*/
	for (i = 0; i < num; i++) {
		temp = series[i] * p;
		for (j = i + max; j < num; j++) {
			if (series[j] <= temp) count = j - i + 1;
			else break;	//及时结束也减少运行时间
		}
		if (count > max) max = count;	 
	}
	printf("%ld\n", max);
	return 0;
}