class Spreadsheet {
public:
    vector<vector<int>> nums;
    int getrow(string cell){
        int ans = 0;
        int j=0 ;
        for(int i=cell.length()-1 ; i>=1 ; i--){
            ans= ans +( pow(10,j)*(cell[i]-'0'));
            j++;
        }
        return ans;
    }
    int mystoi(string cell){
        int ans = 0;
        int j=0;
        for(int i=cell.length()-1 ; i>=0 ; i--){
            ans= ans +( pow(10,j)*(cell[i]-'0'));
            j++;
        }
        return ans;
    }
    bool check(char ch){
        if(ch>='0' && ch<='9'){
            return true;
        }
        return false;
    }
    int myvalue(string cell){
        int col = cell[0]-'A';
        int row = getrow(cell);
        return nums[row][col];
    }
    Spreadsheet(int rows) {
        nums.resize(rows+1, vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int row = getrow(cell);
        nums[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int row = getrow(cell);
        nums[row][col]=0;
    }
    
    int getValue(string formula) {
        string first = "";
        string second = "";
        int i=1;
        while(formula[i] != '+'){
            first = first + formula[i];
            i++;
        }
        i++;
        while(i<formula.length()){
            second = second + formula[i];
            i++;
        }
        if(check(first[0]) && check(second[0])){
            return mystoi(first)+mystoi(second);
        }
        else if(!check(first[0]) && check(second[0])){
            return myvalue(first)+mystoi(second);
        }
        else if(check(first[0]) && !check(second[0])){
            return mystoi(first)+myvalue(second);
        }
        else{
            return myvalue(first)+myvalue(second);
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */