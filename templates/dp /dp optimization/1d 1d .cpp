//add 0 (a dummy element) to the start of a, if required 
//i.e if you can split at index -1 also
//call solve function for each test case
//if you want ans for max dp modify line 35 and 45, change <= to >= 

void solve(){

    //take input here

    vl dp(n);
    //set the value of dp[0]
    dp[0] = 0;

    //define const function

    auto cost = [&](int i, int j){
    
    };

    vpii st = {mp(0, 0)};
    for (int i = 1; i < n; ++ i){
        int opt = (-- ub(all(st), mp(i, n + 1))) -> S;

        //modify the call to cost function i.e if you want 
        //to call cost(i, start) instead of cost(i + 1, start)

        dp[i] = dp[opt] + cost(opt + 1, i);
        for (int j = si(st) - 1; j >= 0; -- j){
            int old_opt = st[j].S;
            int start = st[j].F;

            //modify the call to cost function i.e if you want 
            //to call cost(i, start) instead of cost(i + 1, start)

            if (i < start && dp[i] + cost(i + 1, start) <= dp[old_opt] + cost(old_opt + 1, start)){
                st.pop_back();
            }else{
                int s = max(start + 1, i + 1), e = n - 1, res = n;
                while (s <= e){
                    int m = (s + e) >> 1;

                    //modify the call to cost function i.e if you want 
                    //to call cost(i, start) instead of cost(i + 1, start)

                    if (dp[i] + cost(i + 1, m) <= dp[old_opt] + cost(old_opt + 1, m)){
                        res = m;
                        e = m - 1;
                    }else s = m + 1;
                }
                if (res != n){
                    st.pb(mp(res, i));
                }
                break;
            }
        }
    }

    cout << dp[n - 1] << "\n";
}
