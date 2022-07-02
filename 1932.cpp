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

int N, S = 0;

vll dp;
void sum(int end, int level) {
    if (level == 0) return;
    forsn(i, end - level, end) {
        dp[i - level] = max(dp[i], dp[i + 1]) + dp[i - level];
    }
    sum(end - level - 1, level - 1);
}

void solve() {
    cin >> N;
    rforn(i, N) {
        S += i;
    }
    dp.resize(S);
    forn(i, S) {
        cin >> dp[i];
    }
    sum(S - 1, N - 1);
    cout << dp[0] << nl;
}

int main() {
    fast_cin();

    solve();
    return 0;
}