class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int first, int second) {
        int n = nums.size();
        vector<int> leftfirstsum(n,0);
        vector<int> leftsecondsum(n,0);
        vector<int> rightfirstsum(n,0);
        vector<int> rightsecondsum(n,0);
        int temp = 0;
        int maxi = 0;
        for(int i=0 ; i<first ; i++){
            temp += nums[i];
        }
        maxi = temp;
        leftfirstsum[first-1]=maxi;
        int left = 0;
        for(int i=first ; i<n ; i++){
            temp -= nums[left];
            left++;
            temp+=nums[i];
            maxi=max(maxi,temp);
            leftfirstsum[i]=maxi;

        }
         temp = 0;
         maxi = 0;
        for(int i=0 ; i<second ; i++){
            temp += nums[i];
        }
        maxi = temp;
        leftsecondsum[second-1]=maxi;
         left = 0;
        for(int i=second ; i<n ; i++){
            temp -= nums[left];
            left++;
            temp+=nums[i];
            maxi=max(maxi,temp);
            leftsecondsum[i]=maxi;

        }
         temp = 0;
         maxi = 0;
        for(int i=n-1 ; i>= n-second ; i--){
            temp += nums[i];
        }
        
        maxi = temp;
        rightsecondsum[n-second]=maxi;
        left = n-1;
        for(int i=n-second-1 ; i>=0 ; i--){
            temp -= nums[left];
            left--;
            temp+=nums[i];
            maxi=max(maxi,temp);
            rightsecondsum[i]=maxi;

        }
        temp = 0;
        maxi = 0;
        for(int i=n-1 ; i>= n-first ; i--){
            temp += nums[i];
        }
        maxi = temp;
        rightfirstsum[n-first]=maxi;
        left = n-1;
        for(int i=n-first-1 ; i>=0 ; i--){
            temp -= nums[left];
            left--;
            temp+=nums[i];
            maxi=max(maxi,temp);
            rightfirstsum[i]=maxi;

        }
        // for(int i=0 ; i<n ; i++){
        //     cout<<leftfirstsum[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0 ; i<n ; i++){
        //     cout<<leftsecondsum[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0 ; i<n ; i++){
        //     cout<<rightfirstsum[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0 ; i<n ; i++){
        //     cout<<rightsecondsum[i]<<" ";
        // }
        
        int ans = 0;
        for (int i = first - 1; i < n - second; i++) {

            ans = max(ans, leftfirstsum[i] + rightsecondsum[i + 1]);

        }

        for (int i = second - 1; i < n - first; i++) {

            ans = max(ans, leftsecondsum[i] + rightfirstsum[i + 1]);

        }
        return ans;
       

    }
};