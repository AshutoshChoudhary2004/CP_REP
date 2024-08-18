struct Stack{

    int n;
    vl a;
    vector<int> get_next_greater(){
        stack<int> st;
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; -- i){
            while (st.size() && a[st.top()] <= a[i]) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }
    vector<int> get_next_greater_or_equal(){
        stack<int> st;
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; -- i){
            while (st.size() && a[st.top()] < a[i]) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }
    vector<int> get_next_smaller(){
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; -- i){
            while (st.size() && a[st.top()] >= a[i]) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }
    vector<int> get_next_smaller_or_equal(){
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; -- i){
            while (st.size() && a[st.top()] > a[i]) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }
    vector<int> get_prev_greater(){
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++ i){
            while (st.size() && a[st.top()] <= a[i]) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }
    vector<int> get_prev_greater_or_equal(){
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++ i){
            while (st.size() && a[st.top()] < a[i]) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }
    vector<int> get_prev_smaller(){
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++ i){
            while (st.size() && a[st.top()] >= a[i]) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }
    vector<int> get_prev_smaller_or_equal(){
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++ i){
            while (st.size() && a[st.top()] > a[i]) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }
    void init(vl _a){
        a = _a;
        n = a.size();
    }
};
