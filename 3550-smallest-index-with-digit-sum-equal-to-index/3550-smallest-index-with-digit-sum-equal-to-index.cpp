class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){ if(sum(nums[i])==i) return i;
        }
         return -1;
    }
private:
int sum( int x){
    int s=0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
};