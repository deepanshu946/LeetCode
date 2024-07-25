class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int> , greater<int>> minheap;
        for(int i=0 ; i<nums.size() ; i++){
            minheap.push(nums[i]);
        }
        nums.clear();
        while(!minheap.empty()){
            nums.push_back(minheap.top());
            minheap.pop();
        }
        return nums;
    }
};