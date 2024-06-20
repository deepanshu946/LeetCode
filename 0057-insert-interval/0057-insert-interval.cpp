class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newi) {
        vector<vector<int>> ans;
        if(interval.size()==0){
            ans.push_back(newi);
            return ans;
        }
        bool pushed=0;
        if(newi[1]<interval[0][0]){
            ans.push_back(newi);
            pushed=1;
        }
        for(int i=0 ; i<interval.size() ; i++){
            if(pushed){
                //merge
                if(interval[i][0]<=ans.back()[1]){
                    ans.back()[1]=max(ans.back()[1],interval[i][1]);
                }
                else{
                    ans.push_back(interval[i]);
                }
            }
            else{
                ans.push_back(interval[i]);
                if(newi[1]<ans.back()[0]){
                    ans.pop_back();
                    ans.push_back(newi);
                    ans.push_back(interval[i]);
                    pushed=1;

                }
                //check if newi is present in back
                else if(newi[0]<=ans.back()[1]){
                    ans.back()[1]=max(ans.back()[1],newi[1]);
                    ans.back()[0]=min(ans.back()[0],newi[0]);
                    pushed=1;
                }
                // if(newi[1]<=ans.back()[1]){
                //     ans.back()[0]=min(ans.back()[0],newi[0]);
                //     pushed=1;
                // }
            }
        }
        if(!pushed){
            ans.push_back(newi);
        }
        return ans;
    }
};