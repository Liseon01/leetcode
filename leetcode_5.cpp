class Solution {
public:
    string longestPalindrome(string s) {
        int l, r;
        int maxLen = 0;
        string res;

        for (int i = 0; i < s.length(); i++) {
            l = i;
            r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > maxLen) {
                    res = s.substr(l, r - l + 1); // Use substr
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }

            // Case 2: Even length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > maxLen) {
                    res = s.substr(l, r - l + 1); // Use substr
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return res; // Ensure this is at the end of the function
    }
};
