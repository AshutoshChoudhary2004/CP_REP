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
    vi start;
    vi finish;
    int cnt;
    FenwickTree tree;
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
    void start_dfs(int u){
        dfs(u, -1);
    }
    void update_subtree(int u, ll x){
        tree.update(start[u], finish[u], x);
    }
    void update_node(int u, ll x){
        tree.update(start[u], start[u], x);
    }
    ll query_node(int u){
        return tree.query(start[u], start[u]);
    }
    ll query_subtree(int u){
        return tree.query(start[u], finish[u]);
    }
    void set_value_node(int u, ll x){
        return tree.set_value(start[u], x);
    }
};
