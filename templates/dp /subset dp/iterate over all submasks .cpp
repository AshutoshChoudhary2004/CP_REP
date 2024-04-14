/*

  time complexity of increasing / decreasing _order is 2 ^ N, only but runtime better
  time complexity of iterating over all submasks of all masks from 0 to 2 ^ N : 3 ^ N
*/

void decreasing_order(ll mask){
    ll cur = mask;
    while (true){
        cout << cur << "\n";
        if (cur == 0) break;
        cur = (cur - 1) & mask;
    }
}

void increasing_order(ll mask){
    ll cur = 0;
    do{
        cout << cur << "\n";
    } while (cur = (cur - mask) & mask);
}
