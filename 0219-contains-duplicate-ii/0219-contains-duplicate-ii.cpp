class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {

           unordered_map<int,int> m;
            
            for(int i = 0; i < nums.size(); i++)
            {
                auto it = m.find(nums[i]);
                if(it != m.end() && abs(i-it->second) <= k)
                {
                    
                        return true;
                }
                
                m[nums[i]] = i;
            }

            return false;
        }
};