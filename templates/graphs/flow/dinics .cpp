/*

Works for both directed and undirected graph
min_cut : returns {u, v, flow}
call max_flow() before calling mincut

can find edges in mincut, max_flow

Time Complexity : O(V * V * E)

*/

struct MaxFlow{
    enum e_type{
        directional,
        directional_reverse,
        bidirectional
    };
    struct Edge{
        int v;
        int rev;
        ll cap;
        ll ocap;
        e_type type;

        Edge() {}
        Edge(int _v, int _rev, ll _cap, ll _ocap, e_type _type) : v(_v), rev(_rev), cap(_cap), ocap(_ocap), type(_type) {}
    };

    int n;
    vector<vector<Edge>> g;
    vi level, next;
    vector<bool> vis;
    ll max_flow_res;

    void init(int _n){
        n = _n;
        g.resize(n, {});
    }
    void add_edge(int u, int v, ll c1, ll c2, e_type t1, e_type t2){
        Edge uv(v, si(g[v]) + (u == v), c1, c1, t1);
        Edge vu(u, si(g[u]), c2, c2, t2);
        g[u].pb(uv);
        g[v].pb(vu);
    }
    void add_directional_edge(int u, int v, ll c){
        add_edge(u, v, c, 0, directional, directional_reverse);
    }
    void add_bidirectional_edge(int u, int v, ll c){
        add_edge(v, u, c, c, bidirectional, bidirectional);
    }
    int bfs(int s, int t){
        level.assign(n, -1);
        next.assign(n, 0);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (si(q)){
            int u = q.front(); q.pop();
            for (Edge& e : g[u]){
                if (level[e.v] == -1 && e.cap){
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t];
    }
    ll dfs(int u, int t, ll cur){
        if (u == t) return cur;
        for (; next[u] != si(g[u]); ++ next[u]){
            Edge& e = g[u][next[u]];
            if (level[e.v] == level[u] + 1 && e.cap){
                ll val = dfs(e.v, t, min(cur, e.cap));
                if (val){
                    e.cap -= val;
                    g[e.v][e.rev].cap += val;
                    return val;
                }
            }
        }
        return 0;
    }
    ll max_flow(int s, int t){
        ll res = 0;
        while (bfs(s, t) != -1){
            while (ll cur = dfs(s, t, LLONG_MAX)){
                res += cur;
            }
        }
        return max_flow_res = res;
    }
    void dfs2(int u){
        vis[u] = true;
        for (Edge& e : g[u]){
            if (!vis[e.v] && e.cap){
                dfs2(e.v);
            }
        }
    }
    vvl min_cut(int s, int t){
        if (!max_flow_res) return {};
        vis.resize(n, false);
        dfs2(s);
        vvl res;
        fr(u, n){
            if (!vis[u]) continue;
            for (Edge& e : g[u]){
                if (!vis[e.v] && e.type != directional_reverse){
                    ll flow = g[e.v][e.rev].cap;
                    if (e.type == bidirectional) flow /= 2;
                    res.pb({u, e.v, flow});
                }
            }
        }
        return res;
    }
};
