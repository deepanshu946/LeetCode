class Solution {
private:
int getmaxindex(vector<int> &arr , int right){
    int maxi = 0;
    int index = 0;
    for(int i=0 ; i<=right ; i++){
        if(arr[i]>maxi){
            maxi = arr[i];
            index=i;
        }

    }
    return index;
}
void swaparr(vector<int> &arr , int ind){
    int left = 0;
    int right = ind-1;
    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }

}
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int j = arr.size()-1;
        vector<int> ans;
        while(j != 0){
            int ind = getmaxindex(arr,j);
            
            if(ind != 0 && ind != j){
                ans.push_back(ind+1);
                swaparr(arr,ind+1);
            }
            if(ind != j){
                ans.push_back(j+1);
                swaparr(arr,j+1);
            }
            j--;

        }
        return ans;

    }
};