// class comp{
//     public:
//     bool operator()(pair<int,int>& a, pair<int,int>& b)
//     {
//         if(a.first == b.first)
//             return a.second < b.second;
        
//         return a.first > b.first;
//     }
// };
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        
        vector<pair<int,int>> arr;
        
        for(int i = 0; i < n; i++)
        {
            arr.push_back({capital[i], profits[i]});
        }
        
        sort(arr.begin(), arr.end());
        
        priority_queue< int > pq;
        
        int i = 0;
        while(k--)
        {
            while(i < n && arr[i].first <= w)
            {
               pq.push(arr[i].second);
                
                i++;

            }
            
            if(pq.empty())
            {
                break;
            }
            
            w += pq.top();
            pq.pop();

        }
        
        
        return w;
    }
};