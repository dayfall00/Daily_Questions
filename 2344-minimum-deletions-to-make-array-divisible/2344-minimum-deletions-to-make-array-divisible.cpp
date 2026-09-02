class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        for(int i:numsDivide)
        {
            g=gcd(g,i);
        }
        sort(nums.begin(), nums.end());
        int d=0;
        for(int i: nums){
            if(g%i==0){
                return d;
            }
            else{
                d++;
            }
        }
        return -1;
    }
};