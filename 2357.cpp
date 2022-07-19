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

vll v;
vpll tree;

pll init(int node, int start, int end) {
    if (start == end) return tree[node] = {v[start], v[end]};
    int mid = (start + end) / 2;
    pll p1 = init(2 * node, start, mid);
    pll p2 = init(2 * node + 1, mid + 1, end);
    return tree[node] = {min(p1.fi, p2.fi), max(p1.se, p2.se)};
}

pll get(int node, int start, int end, int left, int right) {
    if (end < left || start > right) return {INF, -INF};
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    pll p1 = get(2 * node, start, mid, left, right);
    pll p2 = get(2 * node + 1, mid + 1, end, left, right);
    return {
        min(p1.fi, p2.fi),
        max(p1.se, p2.se)
    };
}

void solve() {
    int N, M;
    cin >> N >> M;
    v.resize(N);
    forn(i, N) {
        cin >> v[i];
    }

    int h = 1, tmp = N;
    while (tmp > 0) {
        h++;
        tmp /= 2;
    }
    tree.resize(1 << h, {INF, -INF});
    init(1, 0, N - 1);

    forn(i, M) {
        int a, b;
        cin >> a >> b;
        pll ans = get(1, 0, N - 1, a - 1, b - 1);
        cout << ans.fi << ' ' << ans.se << nl;
    }
}

int main() {
    fast_cin();

    solve();
    return 0;
}