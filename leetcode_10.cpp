class Solution {
public:
    int cache[1000][1000];
    bool isMatch(string s, string p) {
        memset(cache, -1, sizeof(cache));
        return match(0, 0, s, p);
    }
    
    bool match(int i, int j, const string& s, const string& p){
        if(cache[i][j] != -1)
            return cache[i][j];

        bool ans;
        if(j == p.size()){
            ans = i == s.size();
        }
        else {
            bool first_match = (i < s.size() && (s[i] == p[j] || p[j] =='.'));
            if(j + 1 < p.size() && p[j+1] == '*'){
                ans = match(i, j+2, s, p) || (first_match && match(i+1, j, s, p));
            }
            else {
                ans = first_match && match(i+1, j+1, s, p);
            }
        }
        cache[i][j] = ans ? 1 : 0;
        return ans;
    } 
};