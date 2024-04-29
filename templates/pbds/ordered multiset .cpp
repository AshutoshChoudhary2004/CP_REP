#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mod2 998244353
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

template <typename T>
void get_unique(vector<T>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
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

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
 
void Insert(ordered_set &s,int x){ //this function inserts one more occurrence of (x) into the set.
 
     s.insert(x);
 
}
 
 
bool Exist(ordered_set &s,int x){ //this function checks weather the value (x) exists in the set or not.
 
     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);
 
}
 
 
void Erase(ordered_set &s,int x){ //this function erases one occurrence of the value (x).
 
     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }
 
}
 
 
int FirstIdx(ordered_set &s,int x){ //this function returns the first index of the value (x)..(0 indexing).
 
    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));
 
}
 
 
int Value(ordered_set &s,int idx){ //this function returns the value at the index (idx)..(0 indexing).
 
   return (*s.find_by_order(idx));
 
}
 
 
int LastIdx(ordered_set &s,int x){ //this function returns the last index of the value (x)..(0 indexing).
 
    if(!Exist(s,x)){
        return -1;
    }
    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;
 
}
 
 
int Count(ordered_set &s,int x){ //this function returns the number of occurrences of the value (x).
 
     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;
 
}
 
 
void Clear(ordered_set &s){ //this function clears all the elements from the set.
 
     s.clear();
 
}
 
 
int Size(ordered_set &s){ //this function returns the size of the set.
 
     return (int)(s.size());
 
}
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ordered_set st;
}
