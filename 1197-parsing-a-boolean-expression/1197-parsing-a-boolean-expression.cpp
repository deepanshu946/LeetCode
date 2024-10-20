class Solution {
private:
bool oper(char ch){
    if(ch=='!' || ch=='&' || ch=='|'){
        return true;
    }
    return false;
}
public:
    bool parseBoolExpr(string nums) {
        if(nums[0]=='f'){
            return false;
        }
        if(nums[0]=='t'){
            return true;
        }
        stack<char> s;
        for(int i=0 ; i<nums.length() ; i++){
            if(oper(nums[i])){
                s.push(nums[i]);
            }
            if(nums[i]=='(' || nums[i]==','){
                continue;
            }
            if(nums[i]=='f'){
                s.push('0');
            }
            if(nums[i]=='t'){
                s.push('1');
            }
            if(nums[i]==')'){
                string ans;
                while(!oper(s.top())){
                    ans.push_back(s.top());
                    s.pop();
                }
                cout<<ans<<endl;
                bool temp;
                if(s.top() == '&'){
                    if(ans[0]=='0'){
                        temp=0;
                    }
                    else{
                        temp=1;
                    }
                    for(int j=1 ; j<ans.length() ; j++){
                        if(ans[j]=='0'){
                            temp = 0;
                            break;
                        }
                        else{
                            temp=temp&1;
                        }
                    }
                }
                if(s.top()=='|'){
                     if(ans[0]=='0'){
                        temp=0;
                    }
                    else{
                        temp=1;
                    }
                    for(int j=1 ; j<ans.length() ; j++){
                        if(ans[j]=='0'){
                            temp = temp|0;
                            // break;
                        }
                        else{
                            temp=1;
                            break;
                        }
                    }
                }
                if(s.top()=='!'){
                     if(ans[0]=='0'){
                        temp=1;
                    }
                    else{
                        temp=0;
                    }
                }
                s.pop();
                cout<<temp<<endl;
                if(temp){
                    s.push('1');
                }
                else{
                    s.push('0');
                }
            }
        }
        if(s.top()=='1'){
            return 1;
        }
        else{
            return 0;
        }
    }
};