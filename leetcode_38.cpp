class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = "1";
        for(int i = 1; i < n; i++) {
            res = RLE(res);
        }
        return res;
    }
private:
    string RLE(string &s) {
        string res;
        int cnt = 1;
        for (int i = 0; i < s.size(); i++) {
            if(i == s.size() - 1 || s[i] != s[i + 1]) {
                res += to_string(cnt) + s[i];
                cnt = 1;
            }
            else {
                cnt ++;
            }
        }
        return res;
    }
};