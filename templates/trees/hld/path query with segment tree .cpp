/*
- call start_dfs to intialize, call this after adding all edges
This code calculates max, to calculate max, sum or any other thing
just change : 
    - func on line 16
    - default value on line 13
    - and if you want sum then multiply by (high - low + 1) on line 31

changes needed to be done in Tree struct: 
    line 141, 144, 148
*/

struct SegmentTree{
    int n;
    vl seg;
    vvl lazy;
    ll default_value = -(ll)(1e18);

    ll func(ll x, ll y){
        return max(x, y);
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
    vi sz; 
    vi par; 
    vi heavy; 
    vi chain; 
    vi id; 
    vi level;
    int cnt;
    SegmentTree tree;

    void init(int _n){
        n = _n;
        tree.init(n);
        g.resize(n);
        sz.resize(n);
        par.resize(n, -1);
        heavy.resize(n, -1);
        chain.resize(n, 0);
        id.resize(n, 0);
        level.resize(n, 0);
        cnt = -1; 
    }

    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(int u){
        sz[u] = 1;
        int mx = 0;
        for (int v : g[u]){
            if (v != par[u]){
                par[v] = u;
                level[v] = level[u] + 1;
                dfs(v);
                sz[u] += sz[v];
                if (sz[v] > mx){
                    mx = sz[v];
                    heavy[u] = v;
                }
            }
        }
    }

    void dfs(int u, int h){
        chain[u] = h;
        id[u] = ++ cnt;
        if (heavy[u] != -1){
            dfs(heavy[u], h);
        }
        for (int v : g[u]){
            if (v != par[u] && v != heavy[u]){
                dfs(v, v);
            }
        }
    }

    void start_dfs(){
        dfs(0);
        dfs(0, 0);
    }

    ll path_query(int u, int v){
        ll res = -(ll)(1e18);
        while (chain[u] != chain[v]){
            if (level[chain[u]] < level[chain[v]]) swap(u, v);
            res = max(res, tree.query(id[chain[u]], id[u]));
            u = par[chain[u]];
        }
        if (level[u] > level[v]) swap(u, v);
        return max(res, tree.query(id[u], id[v]));
    }

    void update_path(int u, int v, ll x){
        while (chain[u] != chain[v]){
            if (level[chain[u]] < level[chain[v]]) swap(u, v);
            tree.update(id[chain[u]], id[u], x);
            u = par[chain[u]];
        }
        if (level[u] > level[v]) swap(u, v);
        tree.update(id[u], id[v], x);
    }

    void set_value_path(int u, int v, ll x){
        while (chain[u] != chain[v]){
            if (level[chain[u]] < level[chain[v]]) swap(u, v);
            tree.set_value(id[chain[u]], id[u], x);
            u = par[chain[u]];
        }
        if (level[u] > level[v]) swap(u, v);
        tree.set_value(id[u], id[v], x);
    }
};
