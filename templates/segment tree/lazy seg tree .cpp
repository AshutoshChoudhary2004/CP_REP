/*
This code calculates min, to calculate max, sum or any other thing
just change : 
    - func on line 16
    - default value on line 13
    - and if you want sum then multiply by (high - low + 1) on line 29
*/

struct SegmentTree{
    int n;
    vl seg;
    vl lazy;
    ll default_value = (ll)(1e18);

    ll func(ll x, ll y){
        return min(x, y);
    }
    void init(int _n){
        n = _n;
        seg.resize(4 * n, 0); 
        lazy.resize(4 * n, 0);
    }
    void set_lazy(int ind, int low, int high, ll val){
        lazy[ind] += val; 
        if (low != high){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        seg[ind] += lazy[ind];
        lazy[ind] = 0;
    }
    ll query(int ind, int low, int high, int left, int right){
        set_lazy(ind, low, high, 0);
        if (low >= left && high <= right) return seg[ind];
        if (high < left || low > right) return default_value;
        int mid = (low + high) >> 1;
        return func(query(2 * ind + 1, low, mid, left, right), query(2 * ind + 2, mid + 1, high, left, right));
    }
    void update(int ind, int low, int high, int left, int right, ll x){
        set_lazy(ind, low, high, 0);
        if (low >= left && high <= right){
            return set_lazy(ind, low, high, x);
        }
        if (high < left || low > right) return;
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, left, right, x);
        update(2 * ind + 2, mid + 1, high, left, right, x);
        seg[ind] = func(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int l, int r, ll val){
        return update(0, 0, n - 1, l, r, val);
    }

    void set_value(int i, ll val){
        update(i, i, val - query(i, i));
    }

    ll query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }
};
