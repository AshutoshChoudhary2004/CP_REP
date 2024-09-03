/*
Example for range min
whatever is the deafult value, is the default value in seg tree
if dont want that than use set_value to set value
*/
template <typename T, typename U, T default_value, U lazy_default_value, T (*combine)(T, T), U (*combine_lazy)(U, U), T (*add_lazy)(T, U, int, int)>
struct SegmentTree{
    int n;
    vector<T> seg;
    vector<U> lazy;

    void init(int _n){
        n = _n;
        seg.resize(4 * n, default_value); 
        lazy.resize(4 * n, lazy_default_value);
    }
    T query(int ind, int low, int high, int left, int right){
        set_lazy(ind, low, high, lazy_default_value);
        if (low >= left && high <= right) return seg[ind];
        if (high < left || low > right) return default_value;
        int mid = (low + high) >> 1;
        return combine(query(2 * ind + 1, low, mid, left, right), query(2 * ind + 2, mid + 1, high, left, right));
    }
    void set_lazy(int ind, int low, int high, U val){
        lazy[ind] = combine_lazy(lazy[ind], val);
        if (low != high){
            lazy[2 * ind + 1] = combine_lazy(lazy[ind], lazy[2 * ind + 1]);
            lazy[2 * ind + 2] = combine_lazy(lazy[ind], lazy[2 * ind + 2]);
        }
        seg[ind] = add_lazy(seg[ind], lazy[ind], low, high);
        lazy[ind] = lazy_default_value;
    }
    void set_value(int ind, int low, int high, int idx, T x){
        set_lazy(ind, low, high, lazy_default_value);
        if (low == high){
            seg[ind] = x;
            return;
        }
        int mid = (low + high) >> 1;
        if (idx >= low && idx <= mid){
            set_value(2 * ind + 1, low, mid, idx, x);
        }else set_value(2 * ind + 2, mid + 1, high, idx, x);
        seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void set_value(int i, T val){
        set_value(0, 0, n - 1, i, val);
    }
    void update(int ind, int low, int high, int left, int right, U val){
        set_lazy(ind, low, high, lazy_default_value);
        if (low >= left && high <= right){
            return set_lazy(ind, low, high, val);
        }
        if (high < left || low > right) return;
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, left, right, val);
        update(2 * ind + 2, mid + 1, high, left, right, val);
        seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    void update(int l, int r, U val){
        update(0, 0, n - 1, l, r, val);
    }

    T query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }
};

ll combine(ll x, ll y){return min(x,  y);}
ll combine_lazy(ll x, ll y){return x + y;}
ll add_lazy(ll x, ll y, int low, int high){return x + y;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SegmentTree<ll, ll, (ll)(1e18), 0LL, combine, combine_lazy, add_lazy> tree;
   
    int n;
    cin >> n;
    tree.init(n);

    for (int i = 0; i < n; ++ i){
        int a;
        cin >> a;
        tree.set_value(i, a);
    } 

}
