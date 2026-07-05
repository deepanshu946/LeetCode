class MyCalendarThree {
public:
    map<int,int> m;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        m[startTime]+=1;
        m[endTime]-=1;
        int curr = 0;
        int ans = 0;
        for(auto i:m){
            curr = curr + i.second;
            ans=max(ans , curr);

        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */