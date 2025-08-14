class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        int n = nums1.size();
        int m = nums2.size();
        while(i<n && j==0){
            if(nums2[1] < nums1[i][0]){
                ans.push_back(nums2);
                j++;
            }
            else if(nums2[0] <= nums1[i][1]){
                ans.push_back({min(nums2[0],nums1[i][0]) , max(nums2[1],nums1[i][1])});
                i++;
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
            }
        }
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        if(j==0){
            ans.push_back(nums2);
        }
        vector<vector<int>> ans2;
        ans2.push_back(ans[0]);
        for(int i=1 ; i<ans.size() ; i++){
            vector<int> b = ans2.back();
            ans2.pop_back();
            if(ans[i][0] <= b[1]){
                ans2.push_back({min(ans[i][0],b[0]),max(ans[i][1],b[1])});
            }
            else{
                ans2.push_back(b);
                ans2.push_back(ans[i]);
            }

        }
        return ans2;

    }
};