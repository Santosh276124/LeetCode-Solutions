class Solution {
public:
    int countOdds(int low, int high) {
        
        if(low == high){
            if(low%2 == 0) return 0;
            else return 1;
        }
      
        int range = high-low+1;
        if(range % 2 == 0) return range/2;
        
        else{
            
            if(low%2 == 0) return range/2;
            else return range/2 + 1;
        }
        
       
    }
};