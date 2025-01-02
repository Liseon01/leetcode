class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen; // 문자와 그 위치 저장
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // 중복된 문자가 윈도우에 있으면, left를 이동
            if (seen.find(currentChar) != seen.end() && seen[currentChar] >= left) {
                left = seen[currentChar] + 1;
            }

            // 현재 문자 위치 업데이트
            seen[currentChar] = right;

            // 최대 길이 갱신
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
