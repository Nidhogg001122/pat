
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10][5] = { 0 }, b[10][5] = { 0 }, c[10][5] = { 0 };
	int i = 0, j = 0;
	int flag = 0;
	char temp;
	int K;
	//输入萌表情模块
	temp = getchar();
	while (temp != '\n')
	{
		if (temp == '[')
		{
			flag = 1;
			j = 0;
			temp = getchar();
			continue;
		}
		else if (temp == ']')
		{
			flag = 0;
			a[i][j] = '\0';
			i++;
		}
		if (flag == 1)
		{
			a[i][j] = temp;
			j++;
		}
		temp = getchar();
	}
	i = 0;
	temp = getchar();
	while (temp != '\n')
	{
		if (temp == '[')
		{
			flag = 1;
			j = 0;
			temp = getchar();
			continue;
		}
		else if (temp == ']')
		{
			flag = 0;
			b[i][j] = '\0';
			i++;
		}
		if (flag == 1)
		{
			b[i][j] = temp;
			j++;
		}
		temp = getchar();
	}
	i = 0;
	temp = getchar();
	while (temp != '\n')
	{
		if (temp == '[')
		{
			flag = 1;
			j = 0;
			temp = getchar();
			continue;
		}
		else if (temp == ']')
		{
			flag = 0;
			c[i][j] = '\0';
			i++;
		}
		if (flag == 1)
		{
			c[i][j] = temp;
			j++;
		}
		temp = getchar();
	}

	//输入数字模块
	scanf("%d", &K);
	int** M = new int* [K];
	for (i = 0; i < K; i++)
	{
		M[i] = new int[5];
	}
	for (i = 0; i < K; i++)
	{
		scanf("%d %d %d %d %d", &M[i][0], &M[i][1], &M[i][2], &M[i][3], &M[i][4]);
	}
	//输出
	for (i = 0; i < K; i++)
	{
		if ((M[i][0] > 10 || M[i][4] > 10 || M[i][1] > 10 || M[i][3] > 10 || M[i][2] > 10) || strcmp(a[M[i][0] - 1], "") == 0 || strcmp(a[M[i][4] - 1], "") == 0 || strcmp(b[M[i][1] - 1], "") == 0 || strcmp(b[M[i][3] - 1], "") == 0 || strcmp(c[M[i][2] - 1], "") == 0)
		{
			printf("Are you kidding me? @\\/@\n");
		}
		else
		{
			printf("%s(%s%s%s)%s\n", a[M[i][0] - 1], b[M[i][1] - 1], c[M[i][2] - 1], b[M[i][3] - 1], a[M[i][4] - 1]);
		}
	}


	//释放空间
	for (i = 0; i < K; i++)
	{
		delete[]M[i];
	}
	delete[]M;
	return 0;
}