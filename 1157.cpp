#include <iostream>
using namespace std;

int n[26];

int main()
{
    cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(0);

	string str;
	cin >> str;

	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		temp = toupper(str[i]) - 'A';
		n[temp]++;
	}

	int max = 0;
	char ch;
	for (int i = 0; i < 26; i++) {
		if (n[i] == max)
			ch = '?';
		else if (n[i] > max) {
			ch = i + 'A';
			max = n[i];
		}
	}

	cout << ch;

	return 0;
}