class Solution {
public:
    string reverseParentheses(string nums) {
        stack<char> s;
        for(int i=0 ; i<nums.length() ; i++){
            if(nums[i]==')'){
                string temp = "";
                while(s.top() != '('){
                    temp.push_back(s.top());
                    s.pop();
                }
                s.pop();
                for(int j=0 ; j<temp.length() ; j++){
                    s.push(temp[j]);
                }
            }
            else{
                s.push(nums[i]);
            }
        }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};