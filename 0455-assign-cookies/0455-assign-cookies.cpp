class Solution {
private:
// int getindex(int num , vector<int> &s){
//     if(s.size()==1 && s[0]>=num){
//         return 0;
//     }
//     int st=0;
//     int end = s.size()-1;
//     int store=-2;
//     while(st <= end){
//         int mid = (st+end)/2;
//         if(s[mid]>=num){
//             store = mid;
//             end = mid-1;
//             // if(st==end){
//             //     break;
//             // }
//         }
//         else{
//             st = mid+1;
//         }
//     }
//     return store;
// }
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int ans = 0;
        int i=0 ; 
        int j=0;
        while(i<g.size() && j<s.size()){
            while(j<s.size()){
                if(s[j] >= g[i]){
                    ans++;
                    j++;
                    break;
                }
                j++;


            }
            i++;
        }
        return ans;








    //     int ans = 0;
    //     unordered_set<int> st;
    //     for(int i=0 ; i<g.size() ; i++){
    //         int index = getindex(g[i],s);
    //         cout<<index<<endl;
    //         if(index >=0){
    //             if(st.find(index) == st.end()){
    //             ans++;
    //             st.insert(index);
    //         }
    //         }
    //     }
    //     return ans;
    }
};