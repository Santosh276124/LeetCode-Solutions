class Solution {
public:
    int findDgSUm(int n){
        
        int sum = 0;
        while(n > 0){
            int dg = n%10;
            sum += dg;
            n = n/10;
        }
        return sum;
    }
    int addDigits(int num) {
        
        while(num > 9){
            int sum = findDgSUm(num);
            num = sum;
        }
        
        return num;
    }
};