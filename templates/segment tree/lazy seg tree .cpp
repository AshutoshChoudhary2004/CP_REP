/*
Example for range sum
whatever is the deafult value, is the default value in seg tree
if dont want that than use set_value to set value
*/
template <typename T, typename U, T (*default_value)(), U (*lazy_default_value)(), T (*combine)(T, T), U (*combine_lazy)(U, U), T (*add_lazy)(T, U, int, int)>
struct SegmentTree{
    int n;
    vector<T> seg;
    vector<U> lazy;
    vector<bool> lazy2;

    void init(int _n){
        n = _n;
        seg.resize(4 * n, default_value()); 
        lazy.resize(4 * n, lazy_default_value());
        lazy2.resize(4 * n, false);
    }
    void set_lazy(int ind, int low, int high){
        if (lazy2[ind]){
            seg[ind] = default_value();
            lazy2[ind] = false;
            if (low != high){
                lazy2[2 * ind + 1] = lazy2[2 * ind + 2] = true; 
                lazy[2 * ind + 1] = lazy[2 * ind + 2] = lazy_default_value();
            }
        } 
        seg[ind] = add_lazy(seg[ind], lazy[ind], low, high);
        if (low != high){
            lazy[2 * ind + 1] = combine_lazy(lazy[2 * ind + 1], lazy[ind]);
            lazy[2 * ind + 2] = combine_lazy(lazy[2 * ind + 2], lazy[ind]);
        }
       lazy[ind] = lazy_default_value();
    }
    T query(int ind, int low, int high, int left, int right){
        set_lazy(ind, low, high);
        if (low >= left && high <= right) return seg[ind];
        if (high < left || low > right) return default_value();
        int mid = (low + high) >> 1;
        return combine(query(2 * ind + 1, low, mid, left, right), query(2 * ind + 2, mid + 1, high, left, right));
    }
    void update(int ind, int low, int high, int left, int right, U x, bool flag){
        set_lazy(ind, low, high);
        if (low >= left && high <= right){
            lazy[ind] = x;
            lazy2[ind] = flag; 
            return set_lazy(ind, low, high);
        }
        if (high < left || low > right) return;
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, left, right, x, flag);
        update(2 * ind + 2, mid + 1, high, left, right, x, flag);
        seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int l, int r, U val){
        return update(0, 0, n - 1, l, r, val, false);
    }
    void set_value(int l, int r, U val){
        return update(0, 0, n - 1, l, r, val, true);
    }
    T query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }
};

ll default_value(){return 0LL;}
ll lazy_default_value(){return 0LL;}
ll combine(ll x, ll y){return x + y;}
ll combine_lazy(ll x, ll y){return x + y;}
ll add_lazy(ll x, ll y, int low, int high){return x + y * (high - low + 1);}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    SegmentTree<ll, ll, default_value, lazy_default_value, combine, combine_lazy, add_lazy> tree;
   
    tree.init(n);
    fr(i, n){
        ll val;
        cin >> val;
        tree.set_value(i, i, val); 
    }
}
