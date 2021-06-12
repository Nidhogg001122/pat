#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct data {
    string name;
    int height;
};
int cmp(struct data a, struct data b) {
    if (a.height > b.height) return true;
    else if (a.height < b.height) return false;
    else {
        return a.name < b.name;
    }
}
int main() {
    int n, k, m;
    cin >> n >> k;
    vector<struct data> people(n);
    for (int i = 0; i < n; i++) cin >> people[i].name >> people[i].height;
    sort(people.begin(), people.end(), cmp);
    //�����������һ��
    int last = n - n / k * (k - 1);     //���һ�а������������
    vector<string> current(last);
    current[last / 2] = people[0].name; //��Ϊ��0��ʼ���ʲ���+1
    int j = last / 2 - 1;               //��ߣ�������룬��i��2
    for (int i = 1; i < last; i = i + 2)
        current[j--] = people[i].name;
    j = last / 2 + 1;                   //�ұ�
    for (int i =2; i < last; i = i + 2)
        current[j++] = people[i].name;
    // ���
    cout << current[0];
    for (int i = 1; i < last; i++)
        cout << " " << current[i];
    cout << endl;
    int row = k-1;
    int t = last;
    while (row) {
        m = n / k;
        current[m / 2] = people[t].name;
        int j = m / 2 - 1;
        for (int i = t + 1; i < t + m; i = i + 2)
            current[j--] = people[i].name;
        j = m / 2 + 1;
        for (int i = t + 2; i < t + m; i = i + 2)
            current[j++] = people[i].name;
        cout << current[0];
        for (int i = 1; i < m; i++)
            cout << " " << current[i];
        cout << endl;
        t = t + m;
        row--;
    }
    return 0;
}