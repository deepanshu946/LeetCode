class Solution {
private:
    bool static cmp(vector<string> &a , vector<string> &b){
        if(stoi(a[1])==stoi(b[1])){
            return a[0]>b[0];
        }
        return stoi(a[1])<stoi(b[1]);
    }
    vector<int> check(string s){
        vector<int> ans;
        int i=2;
        while(i<s.length()){
            string temp;
            while(i<s.length() && s[i] != ' '){
                temp = temp+s[i];
                i++;
            }
            // cout<<temp<<endl;
            ans.push_back(stoi(temp));
            i+=3;
        }
        for(int i=0 ; i<ans.size() ; i++){
            // cout<<ans[i]<<endl;
        }
        return ans;
        
    }
public:
    vector<int> countMentions(int num, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),cmp);
        // for(int i=0 ; i<events.size() ; i++){
        //     cout<<stoi(events[i][1])<<" ";
        // }
        // return {};
        vector<int> ans(num,0);
        vector<int> offline(num,-61);
        for(int i=0 ; i<events.size() ; i++){
            cout<<events[i][0]<<" "<<events[i][1]<<endl;
            if(events[i][0]=="MESSAGE"){
                int time = stoi(events[i][1]);
                // cout<<time<<endl;
                if(events[i][2]=="ALL"){
                    for(int j=0 ; j<ans.size() ; j++){
                        ans[j]++;
                    }
                }
                else if(events[i][2]=="HERE"){
                    for(int i=0 ; i<num ; i++){
                        if( time >= offline[i]+60){
                            ans[i]++;
                        }
                    }
                }
                else{
                    vector<int> count = check(events[i][2]);
                    for(int j=0 ; j<count.size() ; j++){
                        ans[count[j]]++;
                    }
                }
            }
            else{
                offline[stoi(events[i][2])]=stoi(events[i][1]);
            }
        }
        return ans;

    }
};