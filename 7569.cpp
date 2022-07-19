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

int n, m, h;
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
vector<vvi> day;
bool flag = true;
queue<tuple<int, int, int>> q;

void solve() {
    cin >> m >> n >> h;
    day.resize(h, vvi(n, vi(m)));
    forn (i, h) {
        forn (j, n) {
            forn (k, m) {
                cin >> day[i][j][k];
                if (day[i][j][k] == 0) flag = false;
                else if(day[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }
    if (flag) {
        cout << 0;
        return;
    }
    while (!q.empty()) {
        int z, y, x;
        tie(z, y, x) = q.front();
        q.pop();
        forn (d, 6) {
            int nz = z + dz[d];
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue;

            if (day[nz][ny][nx] == 0) {
                day[nz][ny][nx] = day[z][y][x] + 1;
                q.push({nz, ny, nx});
            }
        }
    }
    int ans = 0;
    forn (i, h) {
        forn (j, n) {
            forn (k, m) {
                if (day[i][j][k] == 0) {
                    cout << -1;
                    return;
                }
                ans = max(ans, day[i][j][k]);
            }
        }
    }
    
    cout << ans - 1;
}

int main() {
    fast_cin();

    solve();
    return 0;
}