class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int cnt = 0;
        int n = people.size();
        int s = 0;
        int e = n-1;
        
        while(s <= e){
            if(people[s] + people[e] <= limit){
                s++;
                e--;
                
            }
            else{
                e--;
            }
            
            cnt++;
        }
        
        return cnt;
        
    }
};