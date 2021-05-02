#include<cstdio>
#include<cstring>
using namespace std;

int r = 0;	//除法中的余数

/*
* 对于某些天文数字，仅仅使用基本数据类型，无法完全储存，可以利用数组对
* 一些极大的数据进行存储，即将数的每一位存入数组的一处空间中，重新实现
* 四则运算即可对新的存储方式下存储的数据进行运算
*/

/*
* 
*/

struct bignum
{
	int num[1000];	//数组存储数据;
	int len;		//为方便运算，引入长度;
	bignum() {		//无参构造函数，用于初始化;
		memset(num, 0, sizeof(num));//初始化函数，num为需要赋值数组，0为所赋的值，最后一个参数为赋值长度
		len = 0;
	}
};

/*
* 将输入的极大数以字符串的形式读入，但字符串str="ABC";
* str[0]=A, 在进行运算时，我们希望从最地位开始，故存储时
* 不能直接存入，而是需要将其进行转化；
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
* 为方便运算，还需要比较两个极大数的大小；
* 若两者长度不同，则长的大，若长度相同，从最高位开始逐一比较
*/

int compare(bignum a, bignum b) {	//a大返回1，a小返回-1，相等返回0;
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
* 对于最基本的高精度加法，从两个数的当前位相加，再加上进位
* 若大于10，则取模求余数，除于10得到的整数作为进位加入下一位运算
* 对于有负数的计算，根据具体情况转化
*/

bignum add(bignum a, bignum b) {
	bignum c;
	int next = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int tempnum = a.num[i] + b.num[i] + next;
		c.num[c.len++] = tempnum % 10;
		next = tempnum / 10;
	}
	if (next != 0) {		//加法进位不可能超过9，所以若最后有进位，直接赋值即可；
		c.num[c.len++] = next;
	}
	return c;
}

/*
* 对于减法，我们希望总是大的数减去小的数，在调用此函数前进行交换；
* 减法与加法的不同便是将进位改为借位
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
	while (c.len - 1 >= 1 && c.num[c.len - 1] == 0) {	//因减法存在借位，借位后可能存在高位为0
		c.len--;	//减去高位为0，但至少整个数至少有一位；
	}
	return c;
}

/*
* 极大整数的乘法在此只解决高精度与低精度(正常的数据类型)乘法,高精度之间相差不大
* 类似于高精度加法，将每一位于低精度相乘，加上进位，与10求余得到本位，除于10得进位；
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
	while (next != 0) {	//对于乘法，与加法不同，最后的进位可能不只一位
		c.num[c.len++] = next % 10;
		next = next / 10;
	}
	return c;
}

/*
* 除法与其他运算不同的是它需要从最高位开始；
* 当前位不足以除时此位商为0，将其作为借位传下去；
* 最终还需保留余数；
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
	printf("余数为：%d", r);
	return 0;
}