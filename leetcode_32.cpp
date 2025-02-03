class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        
        int res = 0;
        stack<int> st;
        st.push(-1);  // 기준점으로 -1을 push

        for (int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};
