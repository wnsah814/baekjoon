#include <iostream>
<<<<<<< HEAD
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
=======
#include <vector>
#include <utility>
#include <string>
using namespace std;

vector<pair<int, string>> v;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if
    }
>>>>>>> b96d999fdbe3e4ed377210aaab907434831f632c
}