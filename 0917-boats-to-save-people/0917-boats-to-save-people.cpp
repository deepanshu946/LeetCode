class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int i=0;
        int j=n-1;
        int ans = 0;
        while(i<=j){
            if(people[i]+people[j] > limit){
                j--;
            }
            else{
                i++;
                j--;
            }
            ans++;
        }
        return ans;
    }
};