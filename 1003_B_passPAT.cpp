#include<cstdio>
#include<cstring>
using namespace std;

/*
* 对于题目条件
*1 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
*2 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
*3 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，
*  或者是仅由字母 A 组成的字符串。
* 条件一指明字符串仅有PAT三者，条件二和条件三应该合并理解
* 在P前A的数目乘以P和T中A的数目等于T后A的数目
* xPATx是正确的，x*1=x
* aPbTc是正确的，a*b=c
* aPbATca,蕴含着a*(b+1)=(c+a)
*/

int main() {
	int num, i = 0, length = 0, j = 0;
	int result[11] = { 0 };
	char c, line[101];
	scanf("%d", &num);
	scanf("%c", &c);	//吃掉回车符号
	while (i < num) {
		int beforeP = 0, betweenPT = 0, afterT = 0, status = 0;	//记录各个位置A的数目
		int p = 0, a = 0, t = 0;	//记录各个字符的总数
		scanf("%c", &c);
		while (c != '\n') {
			if (c == 'P') {
				status = 1;		//开始进入P~T
				p++;
			}
			else if (c == 'A') a++;
			else if (c == 'T') {
				status = 2;		//开始进入T之后
				t++;
			}
			else result[i] = 1;	//存在其他字符，不符合
			switch (status) {
			case 0:beforeP++; break;
			case 1:if (c == 'A') betweenPT++; break;	//减去P
			case 2:if (c == 'A') afterT++; break;	//减去T
			}
			scanf("%c", &c);
		}
		if (!result[i] && p == 1 && t == 1 && a != 0 && (beforeP * betweenPT == afterT)) result[i] = 2;
		i++;
	}
	for (i = 0; i < num; i++) {
		if (result[i] == 2) printf("YES\n");
		else printf("NO\n");
	}
}