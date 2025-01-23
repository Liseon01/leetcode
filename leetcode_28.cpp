class Solution {
public:
    int strStr(string haystack, string needle) {
        string temp;
        for(int i = 0; i < haystack.size(); i++){
            string temp = haystack.substr(i, needle.size());
            if(needle == temp){
                return i;
            }
        }
        return -1;
    }
};