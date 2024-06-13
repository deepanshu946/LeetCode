class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        int i=0;
        int j=0;
        unordered_map<int,bool> m;
        if(x==1 && y==1){
            if(2<=bound){
                ans.push_back(2);
            }
            return ans;
        }
        else if(x==1){
            int k=0;
            while(true){
                if(1+pow(y,k) <= bound){
                    ans.push_back(1+pow(y,k));
                }
                k++;
                if(1+pow(y,k) > bound){
                    break;
                }

            }
        }
        else if(y==1){
            int k=0;
            while(true){
                if(1+pow(x,k) <= bound){
                    ans.push_back(1+pow(x,k));
                }
                k++;
                if(1+pow(x,k) > bound){
                    break;
                }

            }
        }
        else{
        while(true){
            while(true){
                if(pow(x,i)+pow(y,j)<=bound && m[pow(x,i)+pow(y,j)] != 1){
                    ans.push_back(pow(x,i)+pow(y,j));
                    m[pow(x,i)+pow(y,j)] = 1;
                }
                j++;
                if(pow(x,i)+pow(y,j) > bound){
                    break;
                }
            }
            i++;
            j=0;
            if(pow(x,i)+pow(y,j)>bound){
                break;
            }
            
        }
        }
        return ans;
    }
};