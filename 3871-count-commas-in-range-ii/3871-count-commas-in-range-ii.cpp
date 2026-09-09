class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0, p;

        p = 1000;

        for(int i = 1; i < 6; i++) {
            count += max(0LL, n - p + 1);

                p *= 1000LL;
        }

        return count;
    }
};