#include <bits/stdc++.h>

using namespace std;

struct grade
{
    double full;
    int na;
    int nr;//正确选项个数
    int zhengque[5] = { 0 }; //记录下每一题的正确选项
} gg[110];

int b[110][5];//记录下做题的情况

int d[110][5];//记录下错题的情况,需要用一个Int型矩阵表示

int max = 0;//max用于记录最大错题的数目

double judge(int j)
{
    double fenshu = 0;
    int flag = 0;//进行判断
    int count0 = 0;//代表在1题中做对的选项
    for (int i = 0; i < 5; i++)
    {
        if (gg[j].zhengque[i] != b[j][i])
        {
            if (gg[j].zhengque[i] == 1 && b[j][i] == 0)
            {
                d[j][i]++;
            }
            else if (gg[j].zhengque[i] == 0 && b[j][i] == 1)
            {
                flag = 1;
                d[j][i]++;
                //相当于出现了错选
            }
        }
        else if (gg[j].zhengque[i] == 1 && b[j][i] == 1)
        {
            count0++;
        }
    }
    if (flag == 1)
    {
        fenshu = 0;
    }
    else if (flag == 0)
    {
        if (count0 < gg[j].nr)
        {
            fenshu = 0.5 * gg[j].full;
        }
        else if (count0 == gg[j].nr)
        {
            fenshu = gg[j].full;
        }
    }
    return fenshu;
}//这个函数是对不同学生的每一道题进行判断，需要的最大值是错误最多的题目的选项，先记录下错误的情况

int main()
{
    int N, M;
    cin >> N >> M;//输入学生人数与题目的数目，学生人数为N，题目数目为M
    char c;//输入字符，主要是应对选项的输入
    for (int i = 0; i < M; i++)
    {
        cin >> gg[i].full >> gg[i].na >> gg[i].nr;
        for (int j = 0; j < gg[i].nr; j++)
        {
            cin >> c;
            gg[i].zhengque[(int)c - (int)'a'] = 1;
        }
    }//可以每做一步便对结果进行输出的检验，思路一定要清晰
    int k = 0;//控制每一个选项
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            b[i][j] = 0;
            d[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        double sum = 0;
        for (int ii = 0; ii < M; ii++)
        {
            for (int jj = 0; jj < 5; jj++)
            {
                b[ii][jj] = 0;
            }
        }
        for (int j = 0; j < M; j++)
        {
            cin >> c;//左括号
            cin >> k;
            for (int l = 0; l < k; l++)
            {
                cin >> c;//输入每个学生的选项
                b[j][(int)c - (int)'a'] = 1;
            }
            cin >> c;//为右括号
            //下面开始进行分数与错题的统计
            sum += judge(j);
        }
        cout << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
    }//输入每个学生的答题情况，输出其分数
    //在输出分数完成后需要进行错误题数的统计，也是最难的
    int max = d[0][0];
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (d[i][j] != 0)
            {
                count++;
            }
            if (d[i][j] > max)
            {
                max = d[i][j];
            }
        }
    }
    if (count != 0)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (d[i][j] == max)
                {
                    cout << d[i][j] << " " << i + 1 << "-" << char('a' + j) << endl;
                }
            }
        }
    }
    else if (count == 0)
    {
        cout << "Too simple" << endl;
    }
    return 0;
}
