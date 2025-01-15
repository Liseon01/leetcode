class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return ""; // 빈 벡터 처리

        string res = ""; // 결과 문자열 초기화

        for (int i = 0; i < strs[0].size(); ++i) { // 첫 번째 문자열의 길이만큼 반복
            char currentChar = strs[0][i]; // 첫 번째 문자열의 i번째 문자

            for (const string& s : strs) { // 모든 문자열 확인
                if (i >= s.size() || s[i] != currentChar) { // 범위를 벗어나거나 문자가 다르면
                    return res; // 현재까지의 결과 반환
                }
            }

            res += currentChar; // 공통 문자 추가
        }

        return res; // 결과 반환
    }
};