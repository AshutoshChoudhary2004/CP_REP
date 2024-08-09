/*
call start_dfs to initialize, and call this after adding all the edges
To change : 
    - change addition in fenwick tree
    - 108, 111, 115
*/
struct FenwickTree{
    int n;
    vl b1, b2;

    void init(int _n){
        n = _n;
        b1.resize(n + 1, 0);
        b2.resize(n + 1, 0);
    }
    void point_update(int idx, ll x, vl &b){
        for (int i = idx; i <= n; i += i & -i){
            b[i] += x;
        }
    }
    void update(int l, int r, ll x){
        l += 1;
        r += 1;
        point_update(l, x, b1);
        point_update(r + 1, -x, b1);
        point_update(l, x * (l - 1), b2);
        point_update(r + 1, -x * r, b2);
    }
    ll sum(int idx, vl &b){
        ll res = 0;
        for (int i = idx; i > 0; i -= i & -i){
            res += b[i];
        } 
        return res;
    }
    ll prefix_sum(int idx){
        return sum(idx, b1) * idx - sum(idx, b2);
    }
    ll query(int l, int r){
        return prefix_sum(r + 1) - prefix_sum(l - 1 + 1);
    }
    void set_value(int idx, ll val){
        update(idx, idx, val - query(idx, idx));
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
    FenwickTree tree;

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
        ll res = 0;
        while (chain[u] != chain[v]){
            if (level[chain[u]] < level[chain[v]]) swap(u, v);
            res += tree.query(id[chain[u]], id[u]);
            u = par[chain[u]];
        }
        if (level[u] > level[v]) swap(u, v);
        return res + tree.query(id[u], id[v]);
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

    void set_value_node(int u, ll x){
        update_path(u, u, x - query_path(u, u));
    }
};
