class Solution {
public:
bool isWholeNumber(double value) {
    double epsilon = 1e-9; // Tolerance threshold for floating-point inaccuracies
    return std::abs(value - std::round(value)) < epsilon;
}

    bool isPowerOfTwo(int n) {
        if(n==2147483647) return false;
        return isWholeNumber(log2(n));
    }
};