#include <bits/stdc++.h>

using namespace std;

struct grade
{
    double full;
    int na;
    int nr;//��ȷѡ�����
    int zhengque[5] = { 0 }; //��¼��ÿһ�����ȷѡ��
} gg[110];

int b[110][5];//��¼����������

int d[110][5];//��¼�´�������,��Ҫ��һ��Int�;����ʾ

int max = 0;//max���ڼ�¼���������Ŀ

double judge(int j)
{
    double fenshu = 0;
    int flag = 0;//�����ж�
    int count0 = 0;//������1�������Ե�ѡ��
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
                //�൱�ڳ����˴�ѡ
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
}//��������ǶԲ�ͬѧ����ÿһ��������жϣ���Ҫ�����ֵ�Ǵ���������Ŀ��ѡ��ȼ�¼�´�������

int main()
{
    int N, M;
    cin >> N >> M;//����ѧ����������Ŀ����Ŀ��ѧ������ΪN����Ŀ��ĿΪM
    char c;//�����ַ�����Ҫ��Ӧ��ѡ�������
    for (int i = 0; i < M; i++)
    {
        cin >> gg[i].full >> gg[i].na >> gg[i].nr;
        for (int j = 0; j < gg[i].nr; j++)
        {
            cin >> c;
            gg[i].zhengque[(int)c - (int)'a'] = 1;
        }
    }//����ÿ��һ����Խ����������ļ��飬˼·һ��Ҫ����
    int k = 0;//����ÿһ��ѡ��
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
            cin >> c;//������
            cin >> k;
            for (int l = 0; l < k; l++)
            {
                cin >> c;//����ÿ��ѧ����ѡ��
                b[j][(int)c - (int)'a'] = 1;
            }
            cin >> c;//Ϊ������
            //���濪ʼ���з���������ͳ��
            sum += judge(j);
        }
        cout << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
    }//����ÿ��ѧ���Ĵ����������������
    //�����������ɺ���Ҫ���д���������ͳ�ƣ�Ҳ�����ѵ�
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
