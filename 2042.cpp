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
vll tree;

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
    if (end < left || start > right) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(2 * node, start, mid, index, diff);
    update(2 * node + 1, mid + 1, end, index, diff);
}

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    v.resize(N);
    forn(i, N) {
        cin >> v[i];
    }

    int h = 0;
    int tmp = N;
    while (tmp > 0) {
        h++;
        tmp /= 2;
    }
    tree.resize(1 << (h + 1));
    dbg(sz(tree));
    init(1, 0, N - 1);
    forn(i, M + K) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N - 1, b - 1, c - v[b - 1]);
            v[b - 1] = c;
        } else {
            cout << sum(1, 0, N - 1, b - 1, c - 1) << nl;
        }
    }
}

int main() {
    fast_cin();

    solve();
    return 0;
}