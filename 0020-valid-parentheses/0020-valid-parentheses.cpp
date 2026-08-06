class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
       char a='(';
       char b= ')';
       char c= '{';
       char d= '}';
       char e= '[';
       char f= ']';
       st.push('a');
       for(auto x: s)
       {
        if(x==b & st.top()==a)
        {
            st.pop();
        }
        else if(x==d & st.top()==c)
        {
            st.pop();
        }
        else if(x==f & st.top()==e)
        {
            st.pop();
        }
        else{
            st.push(x);
        }

            
       }
    return st.top()=='a';
    }
};