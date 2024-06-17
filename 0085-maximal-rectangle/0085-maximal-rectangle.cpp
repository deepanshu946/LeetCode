class Solution {
private:
void next(vector<int> &height , vector<int> &next){
    stack<int> s;
    int n = height.size();
    s.push(-1);
    for(int i=n-1 ; i>=0 ; i--){
        int curr =height[i];
        while(s.top() != -1 && height[s.top()]>= curr){
            s.pop();
        }
        next[i]=s.top();
        s.push(i);
    }
}
void prev(vector<int> &height , vector<int> &prev){
    stack<int> s;
    int n = height.size();
    s.push(-1);
    for(int i=0 ; i<n ; i++){
        int curr = height[i];
        while( s.top() != -1 &&height[s.top()]>= curr){
            s.pop();
        }
        prev[i]=s.top();
        s.push(i);
    }
}
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextsmall(n);
        vector<int> prevsmall(n);
        next(heights,nextsmall);
        prev(heights,prevsmall);
        int ans =INT_MIN;
        for(int i=0 ; i<n ; i++){
            int next = nextsmall[i];
            int prev = prevsmall[i];
            if(next == -1){
                next = n;
            }
            int width = next - prev -1;
            int temp = width*heights[i];
            ans = max(ans,temp);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> temp(matrix[0].size());
        for(int i=0 ; i<matrix[0].size() ; i++){
            temp[i]=matrix[0][i]-48;
        }
        int ans = largestRectangleArea(temp);
        for(int i=1 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[0].size() ; j++){
                if(matrix[i][j]=='0'){
                    temp[j]=0;
                }
                else{
                    temp[j]++;
                }
            }
            ans = max(ans , largestRectangleArea(temp));
        }
        return ans;
    }
};