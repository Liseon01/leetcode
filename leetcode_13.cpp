class Solution {
public:
    int romanToInt(const string& s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int res = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        // 현재 문자보다 다음 문자가 더 크면 뺄셈, 아니면 덧셈
        if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
            res -= roman[s[i]]; // 뺄셈
        } else {
            res += roman[s[i]]; // 덧셈
        }
    }

    return res;
}
};