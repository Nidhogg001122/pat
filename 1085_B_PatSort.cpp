#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
struct department1 {
    int A = 0, B = 0, T = 0;    //该单位甲级，乙级，顶级的分数和
    int num = 0;    //考生人数
};
struct department2 {
    int total_score, total_num;
    string school;
};
bool cmp(department2 a, department2 b) {
    if (a.total_score != b.total_score) {
        return a.total_score > b.total_score;
    }
    else if (a.total_num != b.total_num) {
        return a.total_num < b.total_num;
    }
    else {
        return a.school < b.school;
    }
}
map <string, department1> mp;
vector <department2> vi;
int main() {
    int N;
    cin >> N;
    while (N--) {
        string str1, str2;
        int tmp;
        cin >> str1 >> tmp >> str2;
        transform(str2.begin(), str2.end(), str2.begin(), ::tolower);   //转换为小写字母
        mp[str2].num++;
        switch (str1[0]) {
        case 'A':
            mp[str2].A += tmp; break;
        case 'B':
            mp[str2].B += tmp; break;
        default:
            mp[str2].T += tmp;
        }
    }
    cout << mp.size() << endl;
    for (map <string, department1> ::iterator it = mp.begin(); it != mp.end(); it++) {
        department2 tmp;
        tmp.school = it->first;
        tmp.total_num = it->second.num;
        tmp.total_score = int(it->second.B / 1.5 + it->second.A + it->second.T * 1.5);
        vi.push_back(tmp);
    }
    sort(vi.begin(), vi.end(), cmp);
    int k = 1, c = 0;
    int score = vi[0].total_score;
    for (vector <department2> ::iterator it = vi.begin(); it != vi.end(); it++) {
        c++;
        if (score != it->total_score) {
            score = it->total_score;
            k = c;
        }
        cout << k << " " << it->school << " " << it->total_score << " " << it->total_num << endl;
    }
    return 0;
}
