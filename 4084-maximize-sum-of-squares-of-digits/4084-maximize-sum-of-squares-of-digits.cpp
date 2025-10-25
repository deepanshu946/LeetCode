class Solution {
// private:
// void solve(int num , int sum , string& temp , string &ans){
//     if(num==0 && sum==0){
//         // cout<<temp<<endl;
//         string sortedTemp = temp;
//             // sort(sortedTemp.begin(), sortedTemp.end());
//             // reverse(sortedTemp.begin(), sortedTemp.end());
            

//             if(sortedTemp > ans){
//                 ans = sortedTemp;
//             }

//     }
//     if(num<=0 || sum<0){
//         return ;
//     }
//     for(int i=9; i>=0 ; i--){
//         char c = '0'+i;
//         temp.push_back(c);
//         solve(num-1 , sum-i , temp,ans);
//         temp.pop_back();

//     }
// }
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        // string temp = "";
        // solve(num,sum,temp,ans); 
        while(sum>=9){
            char ch = '9';
            ans.push_back(ch);
            sum -= 9;

        }
        if(sum != 0){
            char ch = '0'+sum;
            ans.push_back(ch);
        }
        num = num - ans.size();
        if(num<0){
            return "";
        }
        for(int i=0 ; i<num ; i++){
            ans.push_back('0');
        }
        return ans;
    }
};