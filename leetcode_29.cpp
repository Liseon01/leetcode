class Solution {
public:
    int divide(int dividend, int divisor) {
    // Handle edge cases
    if (divisor == 0) throw invalid_argument("Division by zero is not allowed");
    if (dividend == 0) return 0;

    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    // Determine the sign of the result
    bool isNegative = (dividend < 0) ^ (divisor < 0);

    // Work with positive values
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);
    long long quotient = 0;

    // Perform repeated subtraction using bit shifts
    while (absDividend >= absDivisor) {
        long long currentDivisor = absDivisor, numShifts = 1;
        while (absDividend >= (currentDivisor << 1)) {
            currentDivisor <<= 1;
            numShifts <<= 1;
        }
        absDividend -= currentDivisor;
        quotient += numShifts;
    }

    // Apply the sign to the result
    quotient = isNegative ? -quotient : quotient;

    // Clamp the result to 32-bit integer range
    return max(INT_MIN, min(INT_MAX, (int)quotient));
    }    
};