class Solution:
    def countCommas(self, n: int) -> int:
        count=0
        for i in range(1,6):
            count+=max(0,n-10**(i*3)+1)
        return count
