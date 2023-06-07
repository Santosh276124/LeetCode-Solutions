class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int cnt = 0;
        
        while(a || b || c){
            
            int bitOfC = (c & 1) != 0 ? 1 : 0;
            
            c = c>>1;
            
            int bitOfA = (a & 1) != 0 ? 1 : 0;
            a = a>>1;
            
            int bitOfB = (b & 1) != 0 ? 1 : 0;
            b = b>>1;
            
            // cout<<bitOfA << "|"<<bitOfB <<"->"<<bitOfC <<" ";
            
            if(bitOfC == 0){
                
                if(bitOfA == 1 && bitOfB == 1){
                    cnt += 2;
                }
                else if(bitOfA == 1 || bitOfB == 1){
                    cnt++;
                }
                
            }
            else{  //bitOfC == 1
                
                if(bitOfA == 0 && bitOfB == 0){
                    cnt++;
                }
              
                
            }
        }
        
        return cnt;
    }
};