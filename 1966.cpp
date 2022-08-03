#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define nl '\n'
#define dbg(x) cout<<#x<<" = "<<x<<nl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool cmp(int a, int b) {
    if (a > b) return true;
    return false;
}

void solve() {
    int N, M;
    cin >> N >> M;
    int arr[N], order[N];

    forn (i, N) {
        cin >> arr[i];
        order[i] = arr[i];
    }
    sort(order, order + N, cmp);
    int arrIdx = 0, orderIdx = 0;
    while (1) {
        while (arr[arrIdx] != order[orderIdx]) {
            arrIdx++;
            if (arrIdx >= N) arrIdx = 0;
        }
        if (arrIdx == M) {
            cout << orderIdx + 1 << nl;
            return;
        }
        arr[arrIdx] = -1;
        orderIdx++;
    }
}

int main() {
    fast_cin();
    int T;
    cin >> T;
    forn(t, T) {
        solve();
    }
    return 0;
}