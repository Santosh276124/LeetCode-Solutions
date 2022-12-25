class Solution {
//     int dfs(int i, vector<int> &nums, int tar)
//     {
//         if(tar == 0) return 1;
        
//         if(i == 0) 
//         {
//             if(nums[0] <= tar) return 1;
//             else return 0;
//         }
        
//         int nottake = dfs(i-1, nums, tar);
//         int take = 0;
//         if(nums[i] <= tar)
//             take = 1 + dfs(i-1, nums, tar-nums[i]);
        
//         return max(take , nottake);
//     }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        int m = queries.size();
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(auto tar : queries)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] <= tar)
                {
                    tar = tar-nums[i];
                    cnt++;
                }
                else
                    break;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};