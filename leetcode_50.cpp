// iteration
class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) return 1.0;
            bool isNegative = n < 0;
            long long N = n;
            if (isNegative) {
                N = -N;
            }       
            double result = 1.0;
            for (int i = 0; i < N; i++) {
                result *= x;
            }
            if (isNegative) {
                result = 1.0 / result;
            }
            return result;
        }
    };
    
// quick

class Solution {
    public:
        double myPow(double x, int n) {
            // n이 음수일 경우, 양수 지수로 변환
            long long N = n;  // n이 INT_MIN인 경우를 고려하여 long long 사용
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            
            double ans = 1.0;
            while (N > 0) {
                // 현재 지수가 홀수라면, ans에 x를 곱함
                if (N % 2 == 1)
                    ans *= x;
                // x를 제곱하여 다음 단계로 넘어감
                x *= x;
                N /= 2;
            }
            
            return ans;
        }
    };
    