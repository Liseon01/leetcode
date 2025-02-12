class Solution {
    public:
        bool isMatch(string s, string p) {
            int sIdx = 0, pIdx = 0;
            int starIdx = -1, match = 0;
            
            while (sIdx < s.size()) {
                // 문자 일치 또는 '?'인 경우
                if (pIdx < p.size() && (p[pIdx] == s[sIdx] || p[pIdx] == '?')) {
                    sIdx++;
                    pIdx++;
                }
                // '*'를 만난 경우
                else if (pIdx < p.size() && p[pIdx] == '*') {
                    starIdx = pIdx;
                    match = sIdx;
                    pIdx++;
                }
                // 이전에 '*'가 있었던 경우, '*'를 통해 한 문자 더 매칭
                else if (starIdx != -1) {
                    pIdx = starIdx + 1;
                    match++;
                    sIdx = match;
                }
                else {
                    return false;
                }
            }
            
            // 남은 패턴이 모두 '*'인지 확인
            while (pIdx < p.size() && p[pIdx] == '*') {
                pIdx++;
            }
            
            return pIdx == p.size();
        }
    };
    