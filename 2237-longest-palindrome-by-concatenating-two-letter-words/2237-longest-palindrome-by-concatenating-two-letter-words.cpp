class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> s1;
        unordered_map<string,int> s2;
        for(auto i:words){
            s1[i]++;
            string temp = i;
            reverse(temp.begin(),temp.end());
            s2[temp]++;
        }
        int ans = 0;
        // string bothsame="";
        unordered_map<string,int> m;
        for(auto i:s1){
            string temp = i.first;
            char first=temp[0];
            char second = temp[1];
            if(first==second){
                m[temp] = s1[temp];
            }
            else{
                if(s2.find(temp) != s2.end()){
                    ans = ans + (min(s2[temp],s1[temp]))*4;
                    // s2[temp]--;
                    // if(s2[temp]==0){
                         s2.erase(temp);
                    // }
                    string temp2=temp;
                    reverse(temp2.begin(),temp2.end());
                    // s2[temp2]--;
                    // if(s2[temp2]==0){
                         s2.erase(temp2);
                    // }
                }
            }
        }
        int maxx=0;
        for(auto i:m){
            cout<<i.first<<" "<<i.second<<endl;
            ans = ans + (i.second/2)*4;
            if(i.second%2==1){
                maxx=1;
            }
        }
        if(maxx){
            ans=ans + 2;
        }
        return ans;
    }
};