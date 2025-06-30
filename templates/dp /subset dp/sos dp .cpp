/*

f(x) : count something from all subsets of x
time complexity to find f(x) for all nubmers upto n : O(NLogN)

max_log = 1 + max(31 - __builtin_ctz(all values))
max_n = 1 << max_log

iterate from 0 to max_log - 1
iterate from 0 to max_n - 1

1) if we want count of elements that are subset/superset of x, then store count of each element in dp and use take_contribution from 
    subset/supserset
    
2) if we want count of elements that are exactly x, then first do method 1, then use remove_contribution from 
    subset/supserset
    
3) if we want count of subsets that are subset/superset of x, then first use method 1 to store count of elements
    that are subset/supserset of x, then change dp[i] to (1 << dp[i]) - 1
    
4) if we want count of subsets that are exactly x, then first use method 3 to generate count of subsets that are
    subset/superset of x, then use remove_contribution to get count of subsets/supersets that are exactly x
    
5) remove_contribution_from_subset/supserset are undo operations of take contributions from subset/superset

6) if we want to count how many values in the array are subset of x, then we can store cnt in dp, then use take contribution from subset
    basically what is happening, instead of iterating on all values of array we are iterating on all subsets of x, then incrementing count, 
    and we do this in sos dp in such a way such that we dont overcount

7) if we have dp[x] ans that form exactly x, then we can use take contribution so that dp[x] changes to dp[x] that form superset / subset of x
    and we dont need to worry about overcounting

8) if we have any one of these : 

    - count / ans that form exactly me OR count / ans for exactly me
    - count / ans that form my subset OR count / ans for my subset
    - count / ans that form my superset OR count / ans for my superset

    then we can get any of above

    If we have count / ans that form exactly me, then we can get count / ans that form my subset / superset
    If we have count / ans that form my subset / superset, then we can get count / ans that form exactly me

    for example for each x if we want to count / calculate / ans that form supserset / subset of x, then we can
    just calculate ans for x such that dp[x] contains ans / count that form exactly x, now we can convert this answer
    such that dp[x] contains count for each x that form supserset / subset of x using sos dp, we dont need to explicitly calculate / apply 
    logic to get answer for superset / subset of x, we can use sos dp for that

    same vice versa, if we want to count / calculate / ans that form exactly x, then we can just calcuate ans for x such 
    dp[x] contains count / ans that form superset / subset of x, now we can convert this answer such that dp[x] contains count for 
    each x such that dp[x] contains count for each x that form exactly x using sos dp, we dont need to explicitly calculate / apply logic to get 
    answer for exactly x, we can use sos dp for that

    if we want for superset of x, we can calculate for subset of x, then convert to exactly x, then convert to superset of x
    if we want for subset of x, we can calculate for superset of x, then convert to exactly x, then convert to subset of x

9) If we want to count for each x, how many subbsets (formed using elements of array) form x (or form superset of x or form subset of x, can be calculated ) then first
    we will count no of elements that form subset / superset of x (by storing count of each element in dp) then calling take_contri function
    then we will replace dp[i] with 1 << dp[i] for all i
    
10) if we have any one of these we can find any one of these : 
    counf of elements of array that satisfy f(x)
    count of subsequence / subset of array that satify f(x)
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
