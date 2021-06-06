#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.length() > b.length())
	{
		b.append(a.length() - b.length(), '0');
	}
	else
	{
		a.append(b.length() - a.length(), '0');
	}
	vector<int> v;
	for (int i = 0; i < b.length(); i++)
	{
		int sum = 0;
		if ((i + 1) % 2 == 0)
		{
			sum = (b[i] - '0') - (a[i] - '0');
			if (sum < 0)
			{
				sum += 10;
			}
		}
		else
		{
			sum = ((b[i] - '0') + (a[i] - '0')) % 13;
		}
		v.push_back(sum);
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] == 10)
		{
			cout << "J";
		}
		else if (v[i] == 11)
		{
			cout << "Q";
		}
		else if (v[i] == 12)
		{
			cout << "K";
		}
		else
		{
			cout << v[i];
		}
	}
	return 0;
}