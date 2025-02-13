class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> map;
    
            for(const auto &s : strs) {
                string key = s;
                sort(key.begin(), key.end());
                map[key].push_back(s);
            }
    
            vector<vector<string>> res;
            for(auto &entry : map) {
                res.push_back(move(entry.second));
            }
            return res;
        }
    };
    