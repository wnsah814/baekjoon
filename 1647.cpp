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

vi p;
vector<tuple<int, int, int>> adj;

int Find(int x) {
    if (p[x] == 0) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    p[x] = y;
}

bool isDividedInTwo() {
    int cnt = 0;
    for (int n : p) {
        if (n == 0) cnt++;
    }
    return cnt == 3;
}

void solve() {
    int N, M;
    cin >> N >> M;
    p.resize(N + 1);
    int u, v, w;
    forn(i, M) {
        cin >> u >> v >> w;
        adj.pb({w, u, v});
    }
    sort(adj.begin(), adj.end());
    int sum = 0;
    queue<tuple<int, int, int>> q;
    forn(i, M) {
        q.push(adj[i]);
    }
    while (!q.empty() && !isDividedInTwo()) {
        tie(w, u, v) = q.front();
        q.pop();
        sum += w;
        Union(u, v);
    }
    cout << sum;
}

int main() {
    fast_cin();

    solve();
    return 0;
}