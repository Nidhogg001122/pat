﻿#include<cstdio>

int main() {
	//简单的两个数组n与m,查询在m中数字是否在n中出现；
	bool hashTab[1000] = { false };
	int n, m, i,x;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		hashTab[x] = true;
	}
	for (i = 0; i < m; i++) {
		scanf("%d", &x);
		if (hashTab[x]) printf("yes\n");
		else printf("no\n");
	}
}

/*
* 散列（hash)
* 将元素通过某一个函数转化为整数，使该整数可以尽可能唯一的代表这个元素
* 转化函数成为散列函数H，若有元素key，转化后整数H（key)
* 常见的直接定址，即如果key本身为整数，直接以其自身为转化后整数；
* 还有还有mod求余法，H（key)=key%mod;
* 在处理后，不同的key还是可能有一样的整数，可以线性探查，即利于a被占据，就找ａ＋１；
* 若超过数组范围，则从零开始
* 也可平方探查，ａ＋１²，a+2²．．．
* 还可以使用链表，若两个转化后整数冲突，则构建链表都存储于此
*/

/*
* 字符串散列
* 可将字符串中字母看成26进制数字，再将其转化为十进制即可
* 例如ｓ＝＂ＢＣＤ＂
* ｉｎｔ　ｎｕｍ＝０；
* ｆｏｒ（ｉｎｔ　ｉ＝０；ｉ＜ｓ．ｌｅｎｇｔｈ；ｉ＋＋）｛
*		ｎｕｍ＝ｎｕｍ＊２６＋ｓ［ｉ］－＇Ａ＇；
* ｝
* 将A～Z看成0～25，ａ～ｚ看成26～51就可将52进制转为十进制；
* 
*/