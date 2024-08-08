/*
This code calculates min, to calculate max, sum or any other thing
just change : 
    - func on line 15
    - default value on line 12
    - and if you want sum then multiply by (high - low + 1) on line 30
*/
struct SegmentTree{
    int n;
    vl seg;
    vvl lazy;
    ll default_value = (ll)(1e18);

    ll func(ll x, ll y){
        return min(x, y);
    }
    void init(int _n){
        n = _n;
        seg.resize(4 * n, 0); 
        lazy.resize(4 * n, vl(2, 0));
    }
    void set_lazy(int ind, int low, int high){
        if (lazy[ind][1]){
            seg[ind] = lazy[ind][1] = 0;
            if (low != high){
                lazy[2 * ind + 1][1] = lazy[2 * ind + 2][1] = true; 
                lazy[2 * ind + 1][0] = lazy[2 * ind + 2][0] = 0;
            }
        } 
        seg[ind] += lazy[ind][0];
        if (low != high){
            lazy[2 * ind + 1][0] += lazy[ind][0];
            lazy[2 * ind + 2][0] += lazy[ind][0];
        }
       lazy[ind][0] = 0;
    }
    ll query(int ind, int low, int high, int left, int right){
        set_lazy(ind, low, high);
        if (low >= left && high <= right) return seg[ind];
        if (high < left || low > right) return default_value;
        int mid = (low + high) >> 1;
        return func(query(2 * ind + 1, low, mid, left, right), query(2 * ind + 2, mid + 1, high, left, right));
    }
    void update(int ind, int low, int high, int left, int right, ll x, bool flag){
        set_lazy(ind, low, high);
        if (low >= left && high <= right){
            lazy[ind][0] = x;
            lazy[ind][1] = flag; 
            return set_lazy(ind, low, high);
        }
        if (high < left || low > right) return;
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, left, right, x, flag);
        update(2 * ind + 2, mid + 1, high, left, right, x, flag);
        seg[ind] = func(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int l, int r, ll val){
        return update(0, 0, n - 1, l, r, val, false);
    }

    void set_value(int l, int r, ll val){
        return update(0, 0, n - 1, l, r, val, true);
    }
    ll query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }
};

struct Tree{

    int n;
    vvi g;
    vi start;
    vi finish;
    int cnt;
    SegmentTree tree;
    void init(int _n){
        n = _n;
        g.resize(n);
        start.resize(n, 0);
        finish.resize(n, 0);
        cnt = -1;
        tree.init(n);
    }
    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }
    void dfs(int u, int p){
        start[u] = ++ cnt;
        for (int v : g[u]){
            if (v != p){
                dfs(v, u);
            }
        }
        finish[u] = cnt;
    }
    void start_dfs(int u = 0){
        dfs(0, -1);
    }
    void update_subtree(int u, ll x){
        tree.update(start[u], finish[u], x);
    }
    void update_node(int u, ll x){
        tree.update(start[u], start[u], x);
    }
    void set_value_node(int u, ll x){
        tree.set_value(start[u], start[u], x);
    }
    void set_value_subtree(int u, ll x){
        tree.set_value(start[u], finish[u], x);
    }
    ll query_node(int u){
        return tree.query(start[u], start[u]);
    }
    ll query_subtree(int u){
        return tree.query(start[u], finish[u]);
    }
};
