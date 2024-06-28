class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int sum = 0;
        for(int i=0 ; i<wall[0].size() ; i++){
            sum = sum + wall[0][i];
        }
        map<int,int> m;
        for(int i=0 ; i<wall.size() ; i++){
            int temp=0;
            for(int j=0 ; j<wall[i].size()-1 ; j++){
                temp = temp + wall[i][j];
                m[temp]++;
            }
        }

        if(m.empty()){
            return wall.size();
        }
        for(auto& i:m){
            i.second = wall.size()-i.second;
        }

        int mini=INT_MAX;
        int ans =0;
        for(auto i:m){
            if(i.second<mini){
                mini=i.second;
            }
        }
        return mini;
        // for(int i=1 ; i<sum ; i++){
        //     for(int j=0 ; j<wall.size() ; j++){
        //         vector<int> k = m[j];
        //         for(int a=0 ; a<k.size() ; a++){
        //             if(k[a]==i){
        //                 ans++;
        //             }
        //             if(k[a]>i){
        //                 break;
        //             }
        //         }
        //     }
        // }
    }

};