class Solution {
public:
    int evalRPN(vector<string>& nums) {
        stack<int> s;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            string temp = nums[i];
            if(temp=="+" || temp=="-"|| temp=="*"|| temp=="/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(temp=="+"){
                    s.push(b+a);
                }
                if(temp=="-"){
                    s.push(b-a);
                }
                if(temp=="*"){
                    s.push(b*a);
                }
                if(temp=="/"){
                    s.push(b/a);
                }
            }
            else{
                
                int num = stoi(temp); // using stoi to convert string to int
                s.push(num);
            }
        }
        return s.top();
    }
};