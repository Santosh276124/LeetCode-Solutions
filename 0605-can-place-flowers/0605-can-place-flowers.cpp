class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n == 0) return true;
        
        int len = flowerbed.size();
        
        for(int i = 0; i < len; i++){
            
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && 
               (i == len-1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                n--;
            }
            
            if(n == 0) return true;
        }
        
        return false;
        
    }
};