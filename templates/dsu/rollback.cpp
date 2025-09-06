TC : LogN

struct DSU {
    vi p;
    vi sz;
    vi st;
    int n;
    void init(int _n) {
        n = _n;
        p.resize(n);
        sz.assign(n, 1);
        fr(i, n) p[i] = i;
    }
    int find(int x) {
        if (x == p[x]) return x;
        return find(p[x]);
    }
    void unite(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) {
            st.pb(-1);
            return;
        }
        if (sz[xx] < sz[yy]) swap(xx, yy);
        st.pb(yy);
        sz[xx] += sz[yy];
        p[yy] = xx;
    }
    void rollback() {
        if (si(st)) {
            int u = st.back();
            st.pop_back();
            if (u == -1) return;
            sz[p[u]] -= sz[u];
            p[u] = u;
        }
    }
};
