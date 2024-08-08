ll func(ll a, ll b){
    return max(a, b);
}
ll default_value = -(ll)(1e18);

struct SegmentTree{
    int n;
    vl seg;

    void init(int _n){
        n = _n;
        seg.resize(2 * n, 0); 
    }
    void update(int i, ll val){
        i += n;
        seg[i] += val; 
        while ((i >>= 1) > 0){
            seg[i] = func(seg[i << 1], seg[i << 1 | 1]);
        }
    }
    ll query(int l, int r){
        ll res = default_value;
        l += n;
        r += n;
        while (l <= r){
            if (l & 1){
                res = func(res, seg[l ++]);
            }
            if (r % 2 == 0){
                res = func(res, seg[r --]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    void set_value(int i, ll val){
        update(i, val - query(i, i));
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

    void start_dfs(int u){
        dfs(u);
        dfs(u, u);
    }

    ll query_path(int u, int v){
        ll res = default_value;
        while (chain[u] != chain[v]){
            if (level[chain[u]] < level[chain[v]]) swap(u, v);
            res = func(res, tree.query(id[chain[u]], id[u]));
            u = par[chain[u]];
        }
        if (level[u] > level[v]) swap(u, v);
        return func(res, tree.query(id[u], id[v]));
    }
    void update_node(int u, ll x){
        tree.update(id[u], x);
    }
    void set_value_node(int u, ll x){
       tree.set_value(id[u], x);
    }
};
