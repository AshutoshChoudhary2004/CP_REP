#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define pb push_back
#define ins insert
#define fr(i, n) for(int i = 0; i < n; ++ i)
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
#define si(x) (int)(x).size()
#define mset(m,v) memset(m,v,sizeof(m))
#define mp make_pair
#define F first
#define S second

template <class S, class T> ostream& operator<<(ostream& os, const vector<pair<S, T>>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const vector<vector<T>>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << "[ "; for (auto inner_it = it->begin(); inner_it != it->end(); ++inner_it) { os << *inner_it; if (inner_it != prev(it->end())) { os << ", "; } } os << " ]"; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class S, class T> ostream& operator<<(ostream& os, const pair<S, T>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const unordered_set<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (next(it) != p.end()) { os << ", "; } } return os << " ]"; }
template <class S, class T> ostream& operator<<(ostream& os, const unordered_map<S, T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << it->first << ": " << it->second; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const set<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const multiset<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class S, class T> ostream& operator<<(ostream& os, const map<S, T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << it->first << ": " << it->second; if (it != prev(p.end())) { os << ", "; } } os << " ]"; return os; }
template <class T> ostream& operator<<(ostream& os, const unordered_multiset<T>& p) { os << "[ "; for (auto it = p.begin(); it != p.end(); ++it) { os << *it; if (next(it) != p.end()) { os << ", "; } } os << " ]"; return os; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
