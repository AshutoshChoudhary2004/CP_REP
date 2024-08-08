struct SegmentTree{
    int n;
    vl seg;
    vl lazy;
    ll inf = (ll)(1e18);
    void init(int _n){
        n = _n;
        seg.resize(4 * n, 0); 
        lazy.resize(4 * n, 0);
    }
    void set_lazy(int ind, int low, int high, ll val){
        lazy[ind] += val;
        if (low != high){
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        seg[ind] += lazy[ind] * (high - low + 1);
        lazy[ind] = 0;
    }
    ll query(int ind, int low, int high, int left, int right){
        set_lazy(ind, low, high, 0);
        if (low >= left && high <= right) return seg[ind];
        if (high < left || low > right) return -inf;
        int mid = (low + high) >> 1;
        return max(query(2 * ind + 1, low, mid, left, right), query(2 * ind + 2, mid + 1, high, left, right));
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
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
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
    void update_subtree(int u, ll x){
        tree.update(0, 0, n - 1, start[u], finish[u], x);
    }
    void update_node(int u, ll x){
        //adds x to the node u, does not set the value of u to x
        tree.update(0, 0, n - 1, start[u], start[u], x);
    }
    ll query_node(int u){
        return tree.query(0, 0, n - 1, start[u], start[u]);
    }
    ll query_subtree(int u){
        return tree.query(0, 0, n - 1, start[u], finish[u]);
    }
};
