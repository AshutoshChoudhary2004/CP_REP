//call func for each test case

int n;
vl dp, prv;

//define the cost function
ll cost(int i, int j){

}
void solve(int l, int r, int opt1, int opt2){
    if (l > r) return;
    int m = (l + r) >> 1;
    pll best = mp(1e18, -1);
    for (ll i = max(0, opt1); i <= min(m - 1, opt2); ++ i){
        //call cost(i + 1, m) or cost(i, m) according to the question
        //and how cost function is defined
        best = min(best, mp(prv[i] + cost(i, m), i));
    }
    int opt = best.S;
    dp[m] = best.F;
    solve(l, m - 1, opt1, opt);
    solve(m + 1, r, opt, opt2);
}

void func(){
    //take input here
    //resize dp, prv
    
    //init value of dp when k = 1, ans last cut at i
    fr(i, n){
        dp[i] = ;
    }
    for (int x = 2; x <= k; ++ x){
        prv = dp;
        solve(0, n - 1, 0, n - 1);
    }
    ll res = 1e18;
    fr(i, n){
        //here dp[i] contains ans when last cut is at i
        //add the cost func for (i + 1, n - 1) or whatever value is required
        res = min(res, dp[i] + );
    }
    cout << res << "\n";
}
