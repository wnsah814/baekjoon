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

vector<pair<pi, pi>> lines;
vi p;

int Find(int idx) {
    if (p[idx] < 0) return idx;
    return p[idx] = Find(p[idx]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (a < b) {
        p[a] += p[b];
        p[b] = a;
    } else if (a > b){
        p[b] += p[a];
        p[a] = b;
    } else {
        p[a] += p[b] - 1;
        p[b] = a;
    }
}

int ccw(pi A, pi B, pi C) {
    int det = A.fi * B.se + B.fi * C.se + C.fi * A.se - (A.se * B.fi + B.se * C.fi + C.se * A.fi);
    if (det > 0) return 1; //ccw;
    else if (det == 0) return 0; //parallel
    else return -1; //cw;
}

bool isIntersect(pi A, pi B, pi C, pi D) {
    int ab = ccw(A, B, C) * ccw(A, B, D);
    int cd = ccw(C, D, A) * ccw(C, D, B);
    if (ab == 0 && cd == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        return C <= B && A <= D;
    }
    return ab <= 0 && cd <= 0;
}

void solve() {
    int N;
    cin >> N;
    p.resize(N, -1);
    forn(i, N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        lines.pb({{a, b}, {c, d}}); 
    }

    forn(i, N - 1) {
        pair<pi, pi> L1 = lines[i];
        forsn(j, i + 1, N) {
            pair<pi, pi> L2 = lines[j];
            if (isIntersect(L1.fi, L1.se, L2.fi, L2.se)) {
                Union(i, j);
            }
        }
    }

    forn(i, N) {
        Find(i);
    }
    int cnt = 0;
    for(int n : p) {
        if (n < 0) {
            cnt++;
        }
    }
    cout << cnt << nl << -*min_element(p.begin(), p.end());
}

int main() {
    fast_cin();

    solve();
    return 0;
}