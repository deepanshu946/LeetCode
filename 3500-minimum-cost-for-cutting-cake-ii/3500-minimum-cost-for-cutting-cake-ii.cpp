class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        unordered_map<int,int> hor;
        priority_queue<int> pq;
        for(int i=0 ; i<horizontalCut.size() ; i++){
            int val = horizontalCut[i];
            hor[val]++;
            pq.push(horizontalCut[i]);
        }
        unordered_map<int,int> ver;
        for(int i=0 ; i<verticalCut.size() ; i++){
            int val = verticalCut[i];
            ver[val]++;
            pq.push(verticalCut[i]);
        }
        long long horpart=1;
        long long verpart=1;
        long long ans = 0;
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(hor.find(val) != hor.end() && hor[val] != 0){
                ans = ans + (val*verpart);
                horpart++;
                hor[val]--;
            }
            if(ver.find(val) != ver.end() && ver[val] != 0){
                ans = ans + (val*horpart);
                verpart++;
                ver[val]--;
            }
        }
        return ans;




    }
};