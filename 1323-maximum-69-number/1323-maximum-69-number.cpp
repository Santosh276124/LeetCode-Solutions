class Solution {
public:
    int maximum69Number (int num) {
        
        vector<int> a;
        while(num > 0)
        {
            int dg = num%10;
            a.push_back(dg);
            num = num/10;
        }
        bool flag = false;
        for(int i = a.size()-1; i >= 0; i--)
        {
            if(a[i] == 9)
                continue;
            else
            {
                a[i] = 9;
                flag = true;;
            }
            
            if(flag == true)
                break;
        }
        int n = a.size();
        int mul = 1;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += a[i]*mul;
            mul = mul*10;
        }
        return  ans;
        
    }
};