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

int ilen(int i) {
    int len = 0;
    while (i > 0) {
        i /= 10;
        len++;
    }
    return len;
}

int iget(int n, int i) {
    int len = ilen(n);
    forn(j, len - i) {
        n /= 10;
    }
    return n % 10;
}

bool goLeft(int a, int b) {
    int lena = ilen(a);
    int lenb = ilen(b);
    forn(i, min(lena, lenb)) {
        int na = iget(a, i + 1);
        int nb = iget(b, i + 1);
        if (na == nb) continue;
        if (na < nb) return true;
        else return false;
    }
    if (lena > lenb) return true;
    
    return false;
}

bool goRight(int a, int b) {
    int lena = ilen(a);
    int lenb = ilen(b);
    forn(i, min(lena, lenb)) {
        int na = iget(a, i + 1);
        int nb = iget(b, i + 1);
        if (na == nb) continue;
        if (na < nb) return true;
        else return false;
    }
    if (lena > lenb) return true;
    
    return false;
}

void solve() {
    int N;
    cin >> N;
    vi v(N);
    forn(i, N) {
        cin >> v[i];
    }
    int M;
    cin >> M;
    int idx = 0;
    while (M > 0) {
        if (idx >= N) 
            break;
        else if (goRight(v[idx], v[idx + 1])) {
            swap(v[idx], v[idx + 1]);
            idx++;
        } else if (idx > 0 && goLeft(v[idx - 1], v[idx])) {
            swap(v[idx - 1], v[idx]);
            idx--;
        } else {
            idx++;
            continue;
        }
        --M;
    }

    for (int n : v) {
        cout << n << ' ';
    }
}

int main() {
    fast_cin();

    solve();
    return 0;
}