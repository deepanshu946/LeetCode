class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size(),0);
        vector<bool> vis(deck.size(),0);
        int n = deck.size();
        sort(deck.begin(),deck.end());
        ans[0]=deck[0];
        vis[0]=1;
        int index = 0;
        for(int i=1 ; i<n ;i++){
            int j=(index+1) %n;
            int space = 0;
            while(true){
                
                if(vis[j]==0){
                    space++;
                }
                if(space==2){
                    break;
                }
                j=(j+1)%n;

            }
            index = j;
            ans[j]=deck[i];
            vis[j]=1;
        }
        return ans;

    }
};