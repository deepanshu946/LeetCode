class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // return {{}};
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            int fstart = nums1[i][0];
            int fend= nums1[i][1];
            int sstart = nums2[j][0];
            int send = nums2[j][1];
            //lies inside
            if(sstart >= fstart && sstart<= fend){
                int start = max(fstart,sstart);
                int end = min(fend,send);
                ans.push_back({start,end});
            }
            else if(fstart >= sstart && fstart <= send){
                ans.push_back({max(fstart,sstart),min(send,fend)});
            }
            if(send <= fend){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};