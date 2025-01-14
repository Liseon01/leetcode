class Solution {
public:
    string intToRoman(int num) {
        // 로마 숫자와 값의 쌍 정의
        vector<pair<string, int>> symList = {
            {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
            {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
            {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900},
            {"M", 1000}
        };
        
        std::string res = "";
        
        // 거꾸로 순회하며 로마 숫자 생성
        for (auto it = symList.rbegin(); it != symList.rend(); ++it) {
            string sym = it->first;
            int val = it->second;
            
            // num에서 val이 몇 번 포함될 수 있는지 계산
            while (num >= val) {
                res += sym; // 해당 로마 숫자를 추가
                num -= val; // 숫자를 감소
            }
        }
        
        return res;
    }
};