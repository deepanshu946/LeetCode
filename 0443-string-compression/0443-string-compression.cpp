class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i =n-1;
        while(i >=0 ){
            int j = i-1;
            int count = 1;
            char ch = chars[i];
            chars.erase(chars.begin()+i);
            while( j>=0 && chars[j] == ch){
                chars.erase(chars.begin()+j);
                count++;
                j--;
            }

            if(count==1){
                chars.push_back(ch);
            }
            else{
                while(count!=0){
                int temp = count%10;
                count=count/10;
                chars.push_back(temp+48);
            }
            chars.push_back(ch);
            }
            i=j;
        }
        reverse(chars.begin() , chars.end());
        return chars.size();
    }
};