class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> project;
        for(int i=0 ; i<profits.size() ; i++){
            project.push_back({capital[i],profits[i]});
        }
        sort(project.begin() , project.end());
        priority_queue<int> maxheap;
        int i=0;
        while(k--){
           while(i<project.size() && project[i].first <= w){
            maxheap.push(project[i].second);
            i++;
           }
           if(maxheap.empty()){
            break;
           } 
           w = w + maxheap.top();
           maxheap.pop();
        }
        return w;
    }
};