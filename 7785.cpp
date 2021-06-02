#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
vector<string> v;
map<string, string> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name, status;
		cin >> name >> status;
		if (!m.count(name))
		{
			v.push_back(name);
		}
		m[name] = status;
	}

	sort(v.begin(), v.end(), greater<string>());

	for (int i = 0; i < v.size(); i++)
	{
		if (m[v[i]] == "enter")
		{
			cout << v[i] << '\n';
		}
	}

	return 0;
}