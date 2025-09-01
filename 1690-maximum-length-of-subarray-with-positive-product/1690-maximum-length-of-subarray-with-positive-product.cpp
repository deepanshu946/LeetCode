class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int negcount = 0;
        int totalcount = 0;
        int firstneg =0;
        int lastneg=0;
        int start = 0;
        int end = 0;
        bool f = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0){
                end--;
                if(negcount%2==0){
                    ans = max(ans , totalcount);
                }
                // else if(end-start == 1 && totalcount==1 && negcount==1){
                //     // continue;
                // }
                else {
                    ans = max(ans , max(end-firstneg,lastneg-start));
                }
                negcount = 0;
                totalcount = 0;
                start = end = i+1;
                firstneg=lastneg=0;
                f=0;
            }
            else{
                if(nums[i]<0){
                    negcount++;
                    if(f==0){
                        firstneg = i;
                        f=1;
                    }
                    lastneg = i;

                }
                totalcount++;
                end++;
            }
        }
        end--;
        cout<<totalcount<<endl;
        cout<<negcount<<endl;
        cout<<firstneg<<endl;
        cout<<lastneg<<endl;
        cout<<start<<endl;
        cout<<end<<endl;

        if(negcount%2==0){
            ans = max(ans , totalcount);
        }
        else{
            ans = max(ans , max(end-firstneg,lastneg-start));
        }
        return ans;
    }
};