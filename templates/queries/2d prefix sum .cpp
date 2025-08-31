// first call init and pass matrix
//call get and give r1, c1, r2, c2 to get prefix sum of submatrix


struct PrefixSum {
    vvl p;
    void init(vvl a){
        int n = si(a), m = si(a[0]);
        p.assign(n + 1, vl(m + 1, 0));
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
                p[i][j] += a[i - 1][j - 1];
            }
        }
    }
    ll get(int r1, int c1, int r2, int c2){
        ++ r1, ++ c1, ++ r2, ++ c2;
        return p[r2][c2] - p[r2][c1 - 1] - p[r1 - 1][c2] + p[r1 - 1][c1 - 1];
    }
};
