class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {

            int n1 = nums1.size();
            int n2 = nums2.size();
             vector<int> ans(n2);

            stack<int> s;
            s.push(-1);
            
            for (int i = n2 - 1; i >= 0; i--)
            {
                while (nums2[i] >= s.top() && s.top() != -1)
                    s.pop();

                ans[i] = s.top();
                // cout<<ans[i]<<" ";
                s.push(nums2[i]);
            }

           
            unordered_map<int, int> m;
            for (int i = 0; i < ans.size(); i++)
            {
                m[nums2[i]] = ans[i];
            }

            vector<int> res;
            for (int i = 0; i < nums1.size(); i++)
            {
              if(m.count(nums1[i]))
                  res.push_back(m[nums1[i]]);
                else res.push_back(-1);
            }

            return res;
        }
};