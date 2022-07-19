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
ll MOD = 1000000007;
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
vll tree;

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    return tree[node] = ((init(node * 2, start, mid) % MOD) * (init(node * 2 + 1, mid + 1, end) % MOD)) % MOD;
}

void update(int node, int idx, int start, int end) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, idx, start, mid);
    update(node * 2 + 1, idx, mid + 1, end);
    tree[node] = (tree[node * 2] % MOD * tree[node * 2 + 1] % MOD) % MOD;
}

ll query(int node, int start, int end, int left, int right) {
    if (end < left || start > right) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return ((query(node * 2, start, mid, left, right) % MOD) * (query(node * 2 + 1, mid + 1, end, left, right) % MOD)) % MOD;
}

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    v.resize(N);
    forn(i, N) {
        cin >> v[i];
    }

    ll h = 1, tmp = N;
    while (tmp > 0) {
        tmp /= 2;
        h++;
    }
    tree.resize(1 << h, 1);
    init(1, 0, N - 1);

    forn(i, M + K) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            v[b - 1] = c;
            update(1, b - 1, 0, N - 1);
        } else if (a == 2) {
            cout << query(1, 0, N - 1, b - 1, c - 1) << nl;
        }
    }
}

int main() {
    fast_cin();

    solve();
    return 0;
}