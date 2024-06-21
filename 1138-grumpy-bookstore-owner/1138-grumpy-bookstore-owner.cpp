class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        for(int i=0 ; i<grumpy.size() ; i++){
            if(grumpy[i]==0){
                ans = ans + customers[i];
            }
        }
        queue<int> q;
        for(int i=0 ; i<minutes ; i++){
            if(grumpy[i]==1){
                q.push(i);
            }
        }
        int finalans =0;
        for(int i=minutes ; i<grumpy.size() ; i++){
            int temp=ans;
            int size = q.size();
            queue<int> copy = q;
            if(size != 0){
                for(int j=0 ; j<size ; j++){
                int front = copy.front();
                copy.pop();
                temp =temp+ customers[front];
            }
            }
            
            finalans = max(temp,finalans);
            if(grumpy[i]==1){
                q.push(i);
            }
            //check for top index
            while( !q.empty() && q.front() <= i-minutes){
                q.pop();
            }
        }

        int temp=ans;
        int size = q.size();
        queue<int> copy = q;
        if(size != 0){
        for(int j=0 ; j<q.size() ; j++){
        int front = copy.front();
        copy.pop();
        temp =temp+ customers[front];
        }
        }
        finalans = max(temp,finalans);
        return finalans;
    }

};