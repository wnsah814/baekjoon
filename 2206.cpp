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

vector<vvi> v;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void solve() {
    int N, M;
    cin >> N >> M;
    v.resize(2, vvi(N, vi(M)));

    forn(i, N) {
        string str;
        cin >> str;
        forn(j, sz(str)) {
            v[0][i][j] = str[j] - '0';
            v[1][i][j] = str[j] - '0';
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 2});
    while (!q.empty()) {
        int z, y, x, nd;
        tie(z, y, x, nd) = q.front();
        q.pop();
        if (v[z][y][x] > 1 && v[z][y][x] < nd) continue;
        v[z][y][x] = nd;
        if (y == N -1 && x == M - 1) {
            cout << v[z][y][x] - 1;
            return;
        }
        forn(d, 4) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (v[z][ny][nx] > 1 && v[z][ny][nx] < nd + 1) continue;
            if (z == 0 && v[z][ny][nx] == 1) {
                v[1][ny][nx] = nd + 1;
                q.push({1, ny, nx, nd + 1});
                continue;
            } 
            if (v[z][ny][nx] == 0) {
                v[z][ny][nx] = nd + 1;
                q.push({z, ny, nx, nd + 1});
            }
        }
    }
    cout << -1;
}

int main() {
    fast_cin();

    solve();
    return 0;
}