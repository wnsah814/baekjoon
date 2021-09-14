#include <iostream>
#include <string>

using namespace std;

string name[105];
int arr[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    cin.get();

    int times = 1;
    while(N) {
        for (int i = 0; i < N; i++) {
            getline(cin, name[i]);
        }
        
        int k;
        string x;

        for (int i = 0; i < 2*N-1 ; i++) {    
            cin >> k;
            getline(cin, x);
            arr[k]++;
        }

        int num;
        for (num = 0; num < N ; num++) {
            if(arr[num] % 2 == 1) {
                break;
            }
        }
        cout << times++ << " " << name[num-1] << endl;

        cin >> N;
        cin.get();
    }

    return 0;
}