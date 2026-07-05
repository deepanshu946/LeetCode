class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
       
    }
    
    bool book(int startTime, int endTime) {
        int curr = 0;
        bool check =1;
        m[startTime]+=1;
        m[endTime]-=1;

        for(auto i:m){
            curr = curr + i.second;
            if(curr>2){
                check=0;
                break;
            }
        }
        if(check==0){
            m[startTime]--;
            m[endTime]++;
        }
        return check;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */