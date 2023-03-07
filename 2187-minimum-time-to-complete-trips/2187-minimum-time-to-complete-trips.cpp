class Solution {
public:
    long long totalNoOfTripsCompletedInMidTime(long long mid, vector<int> &time)
    {
        long long cnt = 0;
        for(int i = 0; i < time.size(); i++)
        {
            
            cnt += (mid / time[i]);
            
        }
        return cnt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long s = *min_element(time.begin(), time.end());
        long long e = 1LL * ( *max_element(time.begin(), time.end()) ) * totalTrips;
        
        while(s < e)
        {
            long long mid = s + (e-s)/2;
            
            if(totalTrips <= totalNoOfTripsCompletedInMidTime(mid, time))
                e = mid;
            else
                s = mid+1;
        }
        
        return s;
        
    }
};