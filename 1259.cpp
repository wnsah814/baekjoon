#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string input;
	while (true) {
		cin >> input;
		if (input == "0") break;
		
		string temp = input;
		reverse(temp.begin(), temp.end());
		if (temp == input) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	} 
	return 0;
}
