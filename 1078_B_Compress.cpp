#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count = 1, i, j;
	char choose;
	string str, output = "";
	cin >> choose;
	getchar();
	if (choose == 'C')
	{
		getline(cin, str);
		for (i = 1; i < str.size(); i++)
		{

			if (str[i] == str[i - 1])
				count++;
			else if (str[i] != str[i - 1])
			{
				if (count > 1)
					output += (to_string(count) + str[i - 1]);
				else
					output += str[i - 1];
				count = 1;
			}
			if (i == str.size() - 1)
			{
				if (count > 1)
					output += (to_string(count) + str[i - 1]);
				else
					output += str[i];
				break;
			}
		}

	}
	if (choose == 'D')
	{
		getline(cin, str);
		for (i = 0; i < str.size(); )
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				j = i;
				while (j < str.size() && str[j] >= '0' && str[j] <= '9')	j++;
				int num = atoi(str.substr(i, j - i).c_str());
				for (int m = 0; m < num; m++)
					output += str[j];
				i = j + 1;
			}
			else
			{
				output += str[i];
				i++;
			}
		}
	}
	cout << output << endl;
	return 0;
}


