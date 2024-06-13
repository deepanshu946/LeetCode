class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin() , seats.end());
        sort(students.begin() , students.end());
        int n = students.size();
        int ans = 0;
        // vector<int> visited(n,0);
        // for(int i=0 ; i<n; i++){
        //     int mini = INT_MAX;
        //     int index;
        //     for(int j=0 ; j<n ; j++){
        //         if(visited[j]==0 && abs(seats[j]-students[i])< mini){
        //             index = j;
        //             mini = abs(seats[j]-students[i]);
        //         }
        //     }
        //     visited[index]=1;
        //     ans = ans+mini;

        // }
        for(int i=0 ; i<n ; i++){
            ans = ans + abs(seats[i]-students[i]);
        }
        return ans;
    }
};