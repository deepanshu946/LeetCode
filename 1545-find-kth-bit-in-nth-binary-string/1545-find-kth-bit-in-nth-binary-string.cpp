class Solution {
public:
    char findKthBit(int n, int k) {
        int size = pow(2,n)-1;
        
        if(k==(size/2)+ 1){
            if(n==1){
                return '0';
            }
            return '1';
        }
        if( k < (size/2)+1 ){
            return findKthBit(n-1,k);
        }
        else{
            int temp = pow(2,n-1)-1;
            char ch = findKthBit(n-1, temp-(k- ((size/2)+ 1))+1 ) ;
            if(ch=='0'){
                return '1';
            }
            else{
                return '0';
            }
        }
    }
};