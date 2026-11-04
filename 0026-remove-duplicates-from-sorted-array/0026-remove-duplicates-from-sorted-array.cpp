class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
       int n=nums.size();
       for(int i=n-1;i>0;i--){
        if(nums[i-1]==nums[i]){
            nums[i]=-1000;
        }
       } 
          for(int i = 0; i < n; i++) {
            if(nums[i] == -1000) {
                for(int j = i; j < n-1; j++) {
                    nums[j] = nums[j+1];
                }
                n--;
                i--;
            }
        }
      return n;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[k-1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};