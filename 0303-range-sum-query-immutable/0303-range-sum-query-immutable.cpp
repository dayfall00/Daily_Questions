class NumArray {
private:
    vector<int> ps;
public:
    NumArray(vector<int>& nums) {
        ps.push_back(0);
        int s=0;
        for(auto x: nums){
            s+=x;
            ps.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        return(ps[right+1]-ps[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */