class Solution {
private:
void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
  // Create a new array to store the merged elements
  vector<int> mergedArray;

  // Iterate over both arrays and add the smaller element to the mergedArray
  auto it1 = arr1.begin();
  auto it2 = arr2.begin();
  while (it1 != arr1.end() && it2 != arr2.end()) {
    if (*it1 < *it2) {
      mergedArray.push_back(*it1);
      it1++;
    } else {
      mergedArray.push_back(*it2);
      it2++;
    }
  }

  // Add the remaining elements from arr1 to the mergedArray
  while (it1 != arr1.end()) {
    mergedArray.push_back(*it1);
    it1++;
  }

  // Add the remaining elements from arr2 to the mergedArray
  while (it2 != arr2.end()) {
    mergedArray.push_back(*it2);
    it2++;
  }

  // Copy the mergedArray back to arr1
  arr1 = mergedArray;
}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        mergeSortedArrays(nums1 , nums2);
        double ans=0;
        if(nums1.size()%2 ==1){
            int n = nums1.size()/2;
             ans = nums1[n];
        }
        else{
            int n = (nums1.size())/2 ;
            int m = (nums1.size()/2)-1;
            cout<<n<<m;
            double temp1 = nums1[n];
            double temp2 = nums1[m];
            ans = (temp1+temp2)/2;
        }
        return ans;
    }
};