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

vvi graph;

void solve() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1, vi(n + 1, 1e9));
    forn(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
    }
    forsn(i, 1, n + 1) {
        graph[i][i] = 0;
    }
    forsn(k, 1, n+1) {
        forsn(i, 1, n+1) {
            forsn(j, 1, n+1) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    forsn(i, 1, n + 1) {
        forsn(j, 1, n + 1) {
            if (graph[i][j] == 1e9) {
                cout << 0 << ' ';
            } else {
                cout << graph[i][j] << ' ';
            }
        }
        cout << nl;
    }
}

int main() {
    fast_cin();

    solve();
    return 0;
}