const ll max_log = 20;
const ll max_n = 1 << max_log;

void take_contribution_from_subset(vl &dp){
    fr(bit, max_log){
        fr(i, max_n){
            if (i & (1 << bit)){
                dp[i] += dp[i ^ (1 << bit)];
            }
        }
    }
}
void remove_contribution_from_subset(vl &dp){
    fr(bit, max_log){
        for (int i = max_n - 1; i >= 0; -- i){
            if (i & (1 << bit)){
                dp[i] -= dp[1 ^ (1 << bit)];
            }
        }
    }
}
void take_contribution_from_superset(vl &dp){
    fr(bit, max_log){
        for (int i = max_n - 1; i >= 0; -- i){
            if (i & (1 << bit)){
                dp[i ^ (1 << bit)] += dp[i];
            }
        }
    }
}
void remove_contribution_from_superset(vl &dp){
    fr(bit, max_log){
        fr(max_n){
            if (i & (1 << bit)){
                dp[i ^ (1 << bit)] -= dp[i];
            }
        }
    }
}
