#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define pb push_back
#define ins insert
#define fr(i, n) for(int i = 0; i < n; ++ i)
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
#define per(i, a, b) for (int i = a; i >= b; -- i)
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

#define min2(a, b) ((a) < (b) ? (a) : (b))
#define min3(a, b, c) min2(min2(a, b), c)
#define min4(a, b, c, d) min2(min2(a, b), min2(c, d))
#define min5(a, b, c, d, e) min2(min4(a, b, c, d), e)
#define min6(a, b, c, d, e, f) min2(min4(a, b, c, d), min2(e, f))
#define min7(a, b, c, d, e, f, g) min2(min4(a, b, c, d), min3(e, f, g))

typedef vector<int> vi;
typedef vector<ll> vl;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pli> vpli;
typedef vector<pil> vpil;

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
