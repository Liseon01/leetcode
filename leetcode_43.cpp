// 값이 너무 크면 오버플로우 발생해서 터짐
class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") return "0";
    
            long long sum = 0;
            long long digit2 = 1;
    
            for (int i = num1.size() - 1; i >= 0; i--) {
                long long digit1 = 1;
                for (int j = num2.size() - 1; j >= 0; j--) {
                    long long mul = (num1[i] - '0') * (num2[j] - '0') * digit2 * digit1;
                    sum += mul;
                    digit1 *= 10;
                }
                digit2 *= 10;
            }
    
            string res;
            while(sum > 0) {
                int s = sum % 10;
                sum /= 10;
                res.push_back(s + '0');
            }
            reverse(res.begin(), res.end());
            return res;
        }
};
// vector를 사용해서 자릿수 저장
class Solution {
    public:
        string multiply(string num1, string num2) {
            // 하나라도 "0"이면 결과는 "0"
            if(num1 == "0" || num2 == "0") return "0";
            
            int n = num1.size(), m = num2.size();
            // 곱셈 결과는 최대 n + m 자리
            vector<int> result(n + m, 0);
            
            // num1과 num2의 각 자리수를 곱함 (역순으로 접근)
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    // 두 자릿수의 곱
                    int mul = (num1[i] - '0') * (num2[j] - '0');
                    // 현재 결과 배열의 해당 자리와 곱셈 결과를 더함
                    int sum = mul + result[i + j + 1];
                    // 현재 자리는 sum의 일의 자리
                    result[i + j + 1] = sum % 10;
                    // 올림은 바로 앞 자리로 전달
                    result[i + j] += sum / 10;
                }
            }
            
            // 벡터를 문자열로 변환 (앞쪽의 불필요한 0 제거)
            string ans;
            for (int num : result) {
                // ans가 비어있고 현재 숫자가 0이면 넘어감 (leading zero 제거)
                if (!(ans.empty() && num == 0)) {
                    ans.push_back(num + '0');
                }
            }
            
            return ans.empty() ? "0" : ans;
        }
    };
    