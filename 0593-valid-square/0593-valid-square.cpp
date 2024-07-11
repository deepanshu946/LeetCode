class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1 == p2 || p2==p3 || p3==p4 || p4==p1 || p3==p1 || p2==p4){
            return false;
        }
        unordered_map<double,int> m ;
        double l1 = sqrt(pow(p1[0]-p2[0],2)+ pow(p1[1]-p2[1],2));
        double l2 = sqrt(pow(p2[0]-p3[0],2)+ pow(p2[1]-p3[1],2));
        
        double l3 = sqrt(pow(p3[0]-p4[0],2)+ pow(p3[1]-p4[1],2));
        double l4 = sqrt(pow(p4[0]-p1[0],2)+ pow(p4[1]-p1[1],2));
        double l5 = sqrt(pow(p2[0]-p4[0],2)+ pow(p2[1]-p4[1],2));
        double l6 = sqrt(pow(p3[0]-p1[0],2)+ pow(p3[1]-p1[1],2));

        m[l1]++;
        m[l2]++;
        m[l3]++;
        m[l4]++;
        m[l5]++;
        m[l6]++;
        bool check1=0;
        bool check2=0;

        for(auto i:m){
            if(i.second==4){
                check1=1;
            }
            else if(i.second==2){
                check2=1;
            }
            else{
                return false;
            }
            if(check1 && check2){
                return true;
            }
        }
        return false;



    }
};