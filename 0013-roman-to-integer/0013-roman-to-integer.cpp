class Solution {
    private:
    int value(char ch1){
        int I             = 1;
        int V             = 5;
        int X             = 10;
        int L             = 50;
        int C             = 100;
        int D             = 500;
        int M             = 1000;
        int c1;
         if(ch1=='I'){
            c1=I;
        }
        else if(ch1=='V'){
            c1=V;
        }
        else if(ch1=='X'){
            c1=X;
        }
        else if(ch1=='L'){
            c1=L;
        }
        else if(ch1=='C'){
            c1=C;
        }
        else if(ch1=='D'){
            c1=D;
        }
        else if(ch1=='M'){
            c1=M;
        }
        else{
            return -1;
        }
        return c1;
    }
public:
    int romanToInt(string s) {
    int total=0;
    char ch1,ch2;
    int v1,v2;
    int n= s.length();
    for(int i=0;i<n;i++)
    {
        ch1=s[i];
        ch2=s[i+1];
        v1= value(ch1);
        v2= value(ch2);
        if (v1<v2){
            total+=(v2-v1);
            i+=1;
            cout<<total<<" "<<v1<<" "<<v2<<endl;
        }
        else 
        {
            total+=v1;
             cout<<total<<" "<<v1<<endl;

        }

        
    }
     return total;



    }
};