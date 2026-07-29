class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        ctr0=0
        ctr1=0

        for i in students:
            if(i==0): 
                ctr0+=1
            else:
                ctr1+=1

        for i in sandwiches:
            if(i==0):
                if(ctr0==0):
                    return ctr1
                ctr0-=1
            
            else:#i=1
            
                if(ctr1==0):
                    return ctr0
                ctr1-=1
            
        return 0


        