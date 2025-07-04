/*

Returns the value of max flow
No need of constructing graph, just init the value of total nodes(N) and add all the edges using add_edges
Time Complexity : O(V * E * E)
Space Complexity : O(V ^ 2)

*/

struct MaxFlow{
    int n;
    vector<bool> vis;
    vvi g;
    vvl c;
    vi p;

    void init(int _n) {
        n = _n;
        c.assign(n, vl(n, 0));
        g.resize(n);
        p.resize(n);
        vis.resize(n);
    }
    void add_edge(int u, int v, ll x){
        g[u].pb(v);
        g[v].pb(u);
        c[u][v] += x;
    }
    ll bfs(int s, int t) {
        fill(all(vis), false);
        fill(all(p), -1); 
        vis[s] = true;
        queue<pll> q;
        q.push(mp(s, INT_MAX));
        while (si(q)){
            int u = q.front().F;
            ll cur = q.front().S;
            q.pop();
            if (u == t) return cur;
            for (int v : g[u]){
                if (!vis[v] && c[u][v]){
                    vis[v] = true;
                    p[v] = u;
                    q.push(mp(v, min(cur, c[u][v])));
                }
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        fr(i, n) get_unique(g[i]);
        ll res = 0;
        ll cur = 0;
        do {
            cur = bfs(s, t);
            res += cur;
            int v = n - 1;
            while (v){
                int u = p[v];
                if (u == -1) break;
                c[u][v] -= cur;
                c[v][u] += cur;
                v = u; 
            }
        } while (cur);
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    MaxFlow obj;
    obj.init(n);
    fr(i, m){
        int u, v, x;
        cin >> u >> v >> x;
        -- u, -- v;
        obj.add_edge(u, v, x);
    }
    cout << obj.max_flow(0, n - 1);
}
