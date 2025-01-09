class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int sign = 1;
        long long result = 0;  // 더 큰 자료형 사용
        
        // 공백 무시
        while(index < s.length() && s[index] == ' ') {
            index++;
        }
        
        // 부호 처리
        if(index < s.length() && s[index] == '-') {
            sign = -1;
            index++;
        } else if(index < s.length() && s[index] == '+') {
            sign = 1;
            index++;
        }
        
        // 숫자 변환
        while(index < s.length() && s[index] >= '0' && s[index] <= '9'){
            result = result * 10 + (s[index] - '0');
            
            // 현재 시점에서 오버플로우 체크
            if(sign == 1 && result >= INT_MAX) {
                return INT_MAX;
            }
            if(sign == -1 && -result <= INT_MIN) {
                return INT_MIN;
            }
            index++;
        }
        
        return static_cast<int>(result * sign);
    }
};
