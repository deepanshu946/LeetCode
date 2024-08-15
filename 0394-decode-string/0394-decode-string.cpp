class Solution {
public:
    
    
    string decodeString(string s) {
       stack<string> st;
       for(int i=0;i<s.size();i++)
       {  char ch=s[i];
        if(ch==']')
        { 
            string repeating="";
            while(st.top()!="[")
            {
                repeating=repeating+st.top();
                st.pop();
            }

            st.pop();
            string number="";
            while(!st.empty() && isdigit(st.top()[0]))
            {
                number=number+st.top();
                st.pop();
            }
            reverse(number.begin(),number.end());
            int no=stoi(number);
             
             string temp="";
            while(no!=0)
            {
                 temp=temp+repeating;
                 no--;
            }
            st.push(temp);
        }
        else{
            string temp = "";
            temp.push_back(ch);
            st.push(temp);
        }
       }
       string ans="";
       while(!st.empty())
       {
            ans=ans+st.top();
            st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};