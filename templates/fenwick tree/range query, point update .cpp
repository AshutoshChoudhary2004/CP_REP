struct FenwickTree{
    int n;
    vl b;

    void init(int _n){
        n = _n;
        b.resize(n + 1, 0);
    }
    void update(int idx, ll x){
        for (int i = idx + 1; i <= n; i += i & -i) b[i] += x;
    }
    void set_value(int idx, ll x){
        update(idx + 1, x - query(idx + 1, idx + 1));
    }
    ll sum(int idx){
        ll res = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) res += b[i];
        return res;
    }
    ll query(int l, int r){
        return sum(r + 1) - sum(l - 1 + 1);
    }
};
