struct Euler{
    
    int n, m;
    vvi g;
    vvi e;
    vi a;
    vector<bool> vis, vis2;
    void init(int _n, int _m = 0){
        n = _n; 
        m = _m;
        g.resize(n);
        vis.assign(m, false);
        vis2.resize(n, false);
    }

    void add_edge(int u, int v){
        e.pb({u, v});
        g[u].pb(si(e) - 1);
        g[v].pb(si(e) - 1); 
        m = si(e);
    }

    int get_v(int u, int i){
        return u ^ e[i][0] ^ e[i][1];
    }

    void dfs(int u){
        vis2[u] = true;
        while (si(g[u])){
            int i = g[u].back();
            g[u].pop_back();
            if (!vis[i]){
                vis[i] = true;
                dfs(get_v(u, i));
            }
        }
        a.pb(u);
    }

    pair<bool, vi> get_euler_circuit(int start = 0){
        vi temp;
        fr(i, n){
            if (si(g[i]) & 1) return mp(false, temp);
        }

        vis.assign(m, false);
        vis2.assign(n, false);

        dfs(start);

        fr(i, n){
            if (!vis2[i] && si(g[i])) return mp(false, temp);
        }

        return mp(true, a);
    }
};
