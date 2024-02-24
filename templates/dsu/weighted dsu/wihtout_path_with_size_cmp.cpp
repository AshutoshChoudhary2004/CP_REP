/*
code for weighted dsu without path compression, but using size compression
time complexity : logN each dsu operation

- find(x) : gives ultimate parent or set no of x
- unite(x, y) : returns true if the given relation is valid / consistent, also if it is valid adds the relation, and merges botht the sets

*/

struct DSU {
    vector<int> par, sz;
    vector<ll> d;

    void init(int n) {
        par.resize(n);
        sz.assign(n, 1);
        d.assign(n, 0LL);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int x) {
        if (x == par[x]) return x;
        return find(par[x]);
    }

    ll get_sum_to_root(int x) {
        if (x == par[x]) return 0LL;
        return d[x] + get_sum_to_root(par[x]);
    }

    //returns true if the given relation is valid / consistent
    bool unite(int x, int y, ll r) {
        int xx = find(x);
        int yy = find(y);
        if (xx == yy) {
            ll xd = get_sum_to_root(x);
            ll yd = get_sum_to_root(y);
            //we already have a relation return true if the ans for x, y matches r
            return xd - yd == r;
        }
        if (sz[xx] > sz[yy]) {
            swap(xx, yy), swap(x, y);
            //write code to
            //change the value of r, acc to the question, i.e relation
            //was given for u -> v, what will will be the relation for v -> u
        }
        par[xx] = yy;
        sz[yy] += sz[xx];
        d[xx] = r + get_sum_to_root(y) - get_sum_to_root(x);
        return true;
    }
};
