#include<iostream>
#include<string>
using namespace std;

int main() {
	string broken, input;
	getline(cin, broken);	//由于可能没有坏键，第一行为空，使用传统方式读取困难
	cin >> input;
	
	bool up = (broken.find('+') == string::npos) ? false : true; //在坏键中找不到+为false;

	int i;
	for (i = 0; i < input.length(); i++) {
		if (broken.find(toupper(input[i])) != string::npos) continue;	//在坏键中找到，不输出
		if (isupper(input[i]) && up) continue;	//输入为大写且+坏了，不输出
		cout << input[i];
	}
	cout << endl;
	return 0;
}