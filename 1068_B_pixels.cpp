#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int picture[1005][1005] = { 0 }, sub1, sub2, num;
map<int, int> match;
int main() {
	int M, N, tol, cnt = 0, f = 0;
	cin >> M >> N >> tol;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> picture[i][j];
			match[picture[i][j]]++;
		}

	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int flag = 0;
			if (match[picture[i][j]] != 1)
				continue;
			for (int k = i - 1; k <= i + 1; k++) {
				for (int l = j - 1; l <= j + 1; l++) {
					if (k == i && l == j)
						continue;
					if ((abs(picture[i][j] - picture[k][l]) <= tol)) {
						flag = 1;
						break;
					}
				}
				if (flag)	break;
			}
			if (!flag) {
				sub1 = i;
				sub2 = j;
				num = picture[i][j];
				cnt++;
			}
		}
	}
	if (!cnt)	cout << "Not Exist";
	else if (cnt > 1)	cout << "Not Unique";
	else	cout << "(" << sub2 << ", " << sub1 << "): " << num;
	return 0;
}