class Solution {
private:
int convert(string ans){
    int temp = 0;
        for(int i=0 ; i<ans.size() ; i++){
            temp = temp*10;
            temp = temp + ans[i]-'0';
        }
        return temp;
}
public:

    int maximumSwap(int num) {
        string ans;
        while(num != 0){
            ans.push_back(num%10 + '0');
            num = num/10;

        }
        reverse(ans.begin(),ans.end());
        int temp = convert(ans);
        for(int i=0 ; i<ans.size(); i++ ){
            for(int j=1 ; j<ans.size() ; j++){
                if(ans[i]<ans[j]){
                    swap(ans[i],ans[j]);
                    temp = max(temp , convert(ans));
                    swap(ans[i],ans[j]);
                }
            }
        }
        return temp;
        
    }
};