class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        result= reduce(math.gcd,numsDivide)
        #stnums=nums[::]
        nums.sort()
        dele=0
        for i in nums:
            if(result % i==0):
                return dele
            else:
                dele+=1
        
        if(dele== len(nums)):
            return -1
        
        #return dele