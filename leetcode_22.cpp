class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(res, s, 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string> &res, string &s, int open, int close, int n){
        if(open == n && close == n){
            res.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            backtrack(res, s, open + 1, close, n);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            backtrack(res, s, open, close + 1, n);
            s.pop_back();
        }
    }
};