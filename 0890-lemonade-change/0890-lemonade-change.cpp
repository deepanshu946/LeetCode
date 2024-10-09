class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0);
        for(int i=0 ; i<bills.size() ; i++){
            if(bills[i]==5){
                change[2]++;
            }
            if(bills[i]==10){
                change[1]++;
            }
            if(bills[i]==20){
                change[0]++;
            }
            int left = bills[i]-5;
            if(left>=20){
                int req = left/20;
                left = left - (min(req,change[0])*20);
                change[0] -= min(req,change[0]);

            }
            if(left>=10){
                int req = left/10;
                left = left - (min(req,change[1])*10);
                change[1] -= min(req,change[1]);

            }
            if(left>=5){
                int req = left/5;
                left = left - (min(req,change[2])*5);
                change[2] -= min(req,change[2]);
            }
            if(left != 0){
                return false;
            }

        }
        return true;
    }
};