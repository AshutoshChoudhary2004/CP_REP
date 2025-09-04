#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//swap lb, ub
//to erase : if (st.ub(x) != st.end()) st.erase(st.ub(x))

constexpr int mod = 1000000007;
constexpr int mod2 = 998244353;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define pb push_back
#define ins insert
#define fr(i, n) for(int i = 0; i < n; ++ i)
#define si(x) (int)(x).size()
#define mset(m,v) memset(m,v,sizeof(m))
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound

#define max2(a, b) ((a) > (b) ? (a) : (b))
#define max3(a, b, c) max2(max2(a, b), c)
#define max4(a, b, c, d) max2(max2(a, b), max2(c, d))
#define max5(a, b, c, d, e) max2(max4(a, b, c, d), e)
#define max6(a, b, c, d, e, f) max2(max4(a, b, c, d), max2(e, f))
#define max7(a, b, c, d, e, f, g) max2(max4(a, b, c, d), max3(e, f, g))
#define max8(a, b, c, d, e, f, g, h) max2(max4(a, b, c, d), max4(e, f, g, h))
#define max9(a, b, c, d, e, f, g, h, i) max2(max8(a, b, c, d, e, f, g, h), i)
#define max10(a, b, c, d, e, f, g, h, i, j) max2(max8(a, b, c, d, e, f, g, h), max2(i, j))

#define min2(a, b) ((a) < (b) ? (a) : (b))
#define min3(a, b, c) min2(min2(a, b), c)
#define min4(a, b, c, d) min2(min2(a, b), min2(c, d))
#define min5(a, b, c, d, e) min2(min4(a, b, c, d), e)
#define min6(a, b, c, d, e, f) min2(min4(a, b, c, d), min2(e, f))
#define min7(a, b, c, d, e, f, g) min2(min4(a, b, c, d), min3(e, f, g))
#define min8(a, b, c, d, e, f, g, h) min2(min4(a, b, c, d), min4(e, f, g, h))
#define min9(a, b, c, d, e, f, g, h, i) min2(min8(a, b, c, d, e, f, g, h), i)
#define min10(a, b, c, d, e, f, g, h, i, j) min2(min8(a, b, c, d, e, f, g, h), min2(i, j))


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<vvvvi> vvvvvi;
typedef vector<vvvvvi> vvvvvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<vvpii> vvvpii;
typedef vector<vvvpii> vvvvpii;
typedef vector<vvvvpii> vvvvvpii;
typedef vector<vvvvvpii> vvvvvvpii;

typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<vvvvl> vvvvvl;
typedef vector<vvvvvl> vvvvvvl;

typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vvpll> vvvpll;
typedef vector<vvvpll> vvvvpll;
typedef vector<vvvvpll> vvvvvpll;
typedef vector<vvvvvpll> vvvvvvpll;

template <typename T>
void get_unique(vector<T>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

ll floor_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x >= 0) return x / y;
	return (x + 1) / y - 1;
}

ll ceil_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x <= 0) return x / y;
	return (x - 1) / y + 1;
}

template <class S, class T> ostream& operator<<(ostream& os, const vector<pair<S, T>>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const vector<vector<T>>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << "[ "; for (auto inner_it = it->begin(); inner_it != it->end(); ++inner_it) { os << *inner_it; if (inner_it != prev(it->end())) { os << ", "; } } os << " ]"; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class S, class T> ostream& operator<<(ostream& os, const pair<S, T>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const unordered_set<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (next(it) != p.end()) { os << ", "; } } return os << " ]"; }
template <class S, class T> ostream& operator<<(ostream& os, const unordered_map<S, T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << "( " << it->first << ": " << it->second << " )"; if (next(it) != p.end()) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const set<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const multiset<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class S, class T> ostream& operator<<(ostream& os, const map<S, T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << "( " << it->first << ": " << it->second << " )" << (it != prev(p.end()) ? ", " : ""); } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const unordered_multiset<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (next(it) != p.end()) { os << ", "; } } os << " ]"; return os; }

void ashuhua(){
    int n;
    cin >> n;
    vi a(n);
    fr(i, n) cin >> a[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t --){
        ashuhua();
    }
}
