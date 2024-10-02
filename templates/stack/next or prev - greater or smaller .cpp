/*
will work directly if two values of array are comparable 
using operators =, <, >
like string, integer, vector, long long 

If they are not directly comparable change the functions : 

- is_equal
- is_greater
- is_smaller

*/

template<typename T>
struct Stack {
    int n;
    vector<T> a;

    bool is_equal(T a, T b) {
        return a == b;
    }
    bool is_greater(T a, T b) {
        return a > b;
    }
    bool is_smaller(T a, T b) {
        return a < b;
    }

    vector<int> get_next_greater() {
        stack<int> st;
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && (is_equal(a[st.top()], a[i]) || is_smaller(a[st.top()], a[i]))) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }

    vector<int> get_next_greater_or_equal() {
        stack<int> st;
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && is_smaller(a[st.top()], a[i])) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }

    vector<int> get_next_smaller() {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && (is_greater(a[st.top()], a[i]) || is_equal(a[st.top()], a[i]))) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }

    vector<int> get_next_smaller_or_equal() {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && is_greater(a[st.top()], a[i])) st.pop();
            res[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        return res;
    }

    vector<int> get_prev_greater() {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            while (st.size() && (is_equal(a[st.top()], a[i]) || is_smaller(a[st.top()], a[i]))) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }

    vector<int> get_prev_greater_or_equal() {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            while (st.size() && is_smaller(a[st.top()], a[i])) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }

    vector<int> get_prev_smaller() {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            while (st.size() && (is_greater(a[st.top()], a[i]) || is_equal(a[st.top()], a[i]))) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }

    vector<int> get_prev_smaller_or_equal() {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            while (st.size() && is_greater(a[st.top()], a[i])) st.pop();
            res[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return res;
    }

    void init(vector<T> _a) {
        a = _a;
        n = a.size();
    }
};

