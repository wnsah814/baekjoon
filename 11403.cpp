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

void solve() {
    int N;
    cin >> N;
    vvi adj(N, vi(N));
    forn(i, N) {
        forn(j, N) {
            cin >> adj[i][j];
        }
    }

    forn(k, N) {
        forn(i, N){
            forn(j, N) {
                if (adj[i][k] == 1 && adj[k][j] == 1) {
                    adj[i][j] = 1;
                }
            }
        }
    }

    for (auto a : adj) {
        for (auto n : a) {
            cout << n << ' ';
        }
        cout << nl;
    }
}

int main() {
    fast_cin();

    solve();
    return 0;
}