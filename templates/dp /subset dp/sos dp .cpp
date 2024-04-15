/*

f(x) : count something from all subsets of x
time complexity to find f(x) for all nubmers upto n : O(NLogN)

max_log = ceil(log2(max_value)) + 1

1) if we want count of elements that are subset/superset of x, then store count of each element in dp and use take_contribution from 
    subset/supserset
    
2) if we want count of elements that are exactly x, then first do method 1, then use remove_contribution from 
    subset/supserset
    
3) if we want count of subsets that are subset/superset of x, then first use method 1 to store count of elements
    that are subset/supserset of x, then change dp[i] to (1 << dp[i]) - 1
    
4) if we want count of subsets that are exactly x, then first use method 3 to generate count of subsets that are
    subset/superset of x, then use remove_contribution to get count of subsets/supersets that are exactly x
    
5) remove_contribution_from_subset/supserset are undo operations of take contributions from subset/superset


*/

const ll max_log = 20;
const ll max_n = 1 << max_log;

//count subset : count how many subset's of x exist in array
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
//count superset : count how many superset's of x exist in array
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
        fr(i, max_n){
            if (i & (1 << bit)){
                dp[i ^ (1 << bit)] -= dp[i];
            }
        }
    }
}
