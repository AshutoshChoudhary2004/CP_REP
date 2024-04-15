/*

f(x) : count something from all subsets of x
time complexity to find f(x) for all nubmers upto n : O(NLogN)

max_log = ceil(log2(max_value)) + 1

applications : 

1) we want to count how many subsets/supersets of x, exist in an array 


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
