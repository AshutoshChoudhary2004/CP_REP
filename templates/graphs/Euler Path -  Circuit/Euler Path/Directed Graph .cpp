struct Euler{
    
    int n;
    vvi g;
    vvi e;
    vi a;
    vi in;
    vi out;
    vector<bool> vis;

    void init(int _n){
        n = _n; 
        g.resize(n);
        vis.resize(n, false);
        in.resize(n, 0);
        out.resize(n, 0); 
    }

    void add_edge(int u, int v){
        g[u].pb(v);
        ++ in[v];
        ++ out[u];
    }

    void dfs(int u){

        vis[u] = true;

        while (si(g[u])){
            int v = g[u].back();
            g[u].pop_back();
            dfs(v);
        }
        a.pb(u);
    }

    pair<bool, vi> get_euler_path(int start, int finish){

        bool flag = true;
        fr(i, n){
            if (i == start || i == finish){
                flag = flag && ((i == start && out[i] == in[i] + 1) || (i == finish && in[i] == out[i] + 1));
            }
            else flag = flag && in[i] == out[i];  
        }

        dfs(start);
        fr(i, n){
            if (!vis[i] && (in[i] || out[i])) flag = false;
        }
        vi temp;
        if (!flag) return mp(false, temp);
        else{
            reverse(all(a));
            return mp(true, a);
        }
    }
};
