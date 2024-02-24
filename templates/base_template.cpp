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

template <class S, class T> ostream& operator <<(ostream& os, const vector<pair<S, T>>& p) { os << "[ "; for (const auto& it : p) os << it << " "; return os << "]"; }
template <class T> ostream& operator <<(ostream& os, const vector<vector<T>>& p) { os << "[ "; for (const auto& inner_vec : p) { os << "[ "; for (const auto& elem : inner_vec) os << elem << " "; os << "] "; } return os << "]"; }
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
