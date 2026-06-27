#define mod 1000000007
class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        vector<int> nse(arr.size(),arr.size());
        
        stack<pair<int,int>> st;
        st.push({arr[arr.size()-1],arr.size()-1});
        for(int i=arr.size()-2 ; i>=0 ; i--){
            while(!st.empty() && st.top().first >arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top().second;
            }
            st.push({arr[i],i});
            
        }
        // for(int i=0 ;i<nse.size() ; i++){
        //     cout<<nse[i]<<" ";
            
        // }
        // st.clear();
        cout<<endl;
        vector<int> pse(arr.size(),-1);
        
        stack<pair<int,int>> st2;
        st2.push({arr[0],0});
        for(int i=1 ; i<arr.size() ; i++){
            while(!st2.empty()&& st2.top().first >= arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                pse[i]=st2.top().second;
            }
            st2.push({arr[i],i});
            
        }
        // for(int i=0 ;i<pse.size() ; i++){
        //     cout<<pse[i]<<" ";
            
        // }
        long long mini = 0;
        for(int i=0 ; i<arr.size() ; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            mini = (mini + ((arr[i] ) * (left ) * (right )) ) ;
        }
        vector<int> nge(arr.size(),arr.size());
        
        stack<pair<int,int>> st3;
        st3.push({arr[arr.size()-1],arr.size()-1});
        for(int i=arr.size()-2 ; i>=0 ; i--){
            while(!st3.empty() && st3.top().first < arr[i]){
                st3.pop();
            }
            if(!st3.empty()){
                nge[i]=st3.top().second;
            }
            st3.push({arr[i],i});
            
        }
        // for(int i=0 ;i<nse.size() ; i++){
        //     cout<<nse[i]<<" ";
            
        // }
        // st.clear();
        cout<<endl;
        vector<int> pge(arr.size(),-1);
        
        stack<pair<int,int>> st4;
        st4.push({arr[0],0});
        for(int i=1 ; i<arr.size() ; i++){
            while(!st4.empty()&& st4.top().first <= arr[i]){
                st4.pop();
            }
            if(!st4.empty()){
                pge[i]=st4.top().second;
            }
            st4.push({arr[i],i});
            
        }
        // for(int i=0 ;i<pse.size() ; i++){
        //     cout<<pse[i]<<" ";
            
        // }
        long long maxi = 0;
        for(int i=0 ; i<arr.size() ; i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;

            maxi = (maxi + ((arr[i] ) * (left ) * (right )) ) ;
        }
        return maxi-mini;

    }
};