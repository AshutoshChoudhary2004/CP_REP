//add 0 (a dummy element) to the start of a, if required 
//i.e if you can split at index -1 also
//call solve function for each test case
//if you want ans for max dp modify line 36 and 46, change <= to >= 
//dp[i][k] represents ans for array 0 .. i, and the last element of the kth group / subarray is i

int n;
vl dp, prv;

//define the cost function
ll cost(int i, int j){

}
void solve(int l, int r, int opt1, int opt2){
    if (l > r) return;
    int m = (l + r) >> 1;
    dp[m] = 1e18;
    int opt = opt1;
    for (ll i = opt1; i <= min(m - 1, opt2); ++ i){
        //call cost(i + 1, m) or cost(i, m) according to the question
        //and how cost function is defined
        val = prv[i] + cost(i, m);
        if (val < dp[m]){
            dp[m] = val;
            opt = i;
        }
    }
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
