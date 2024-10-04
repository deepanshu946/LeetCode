class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        sort(skill.begin(),skill.end());
        int i=0 ; 
        int n  = skill.size();
        int j = n-1;
        int sum = -1;
        while(i<j){
            int temp = skill[i]+skill[j];
            if(sum != -1){
                if(sum != temp){
                    return -1;
                }
            }
            else{
                sum = temp;
            }
            ans = ans + (skill[i]*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};