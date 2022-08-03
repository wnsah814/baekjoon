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

vll arr;
vll tree;

ll sum(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, diff);
    update(node * 2 + 1, mid + 1, end, idx, diff);
}

int N, M;
void solve() {
    cin >> N >> M;
    arr.resize(N);
    int tmp = N;
    int h = 1;
    while (tmp > 0) {
        tmp /= 2;
        h++;
    }
    tree.resize(1 << h);

    forn(i, M) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) {
            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            cout << sum(1, 0, N - 1, a - 1, b - 1) << nl;
        } else if (c == 1) {
            int d = b - arr[a - 1];
            arr[a - 1] = b;
            update(1, 0, N - 1, a-1, d);
        }
    }
}

int main() {
    fast_cin();

    solve();
    return 0;
}