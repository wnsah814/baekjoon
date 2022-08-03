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

vector<tuple<int, int, int>> dp; // 2, 5, 10

void solve() {
    int N;
    cin >> N;
    dp.resize(N + 1);
    dp[0] = {0, 0, 0};
    forsn(i, 1, N + 1) {
        int tmp = i;
        int x = 0, y = 0, z = 0;
        while(tmp % 2 == 0) {
            x++;
            tmp /= 2;
        }
        while (tmp % 5 == 0) {
            y++;
            tmp /= 5;
        }
        while (x > 0 && y > 0) {
            x--;
            y--;
            z++;
        }
        dp[i] = {x + get<0>(dp[i - 1]), y + get<1>(dp[i - 1]), z + get<2>(dp[i - 1])};
    }
    int n = 0;
    for (auto a : dp) {
        int u,v,w;
        tie(u,v,w) = a;
        cout << n++ << ' ' << u << ' ' << v << ' ' << w << nl;
    }
    cout << get<2>(dp[N]);
}

int main() {
    fast_cin();

    solve();
    return 0;
}