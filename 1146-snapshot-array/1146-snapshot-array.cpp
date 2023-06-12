class SnapshotArray {
public:
    
    vector<vector<pair<int,int>> > nums;
    // unordered_map<int, vector<int> > mp;
    int snap_id;
    
    SnapshotArray(int n) {
        
        snap_id = 0;
        
        nums.resize(n);
        for(int i = 0; i < n; i++)
            nums[i].push_back({0,0});
        
    }
    
    void set(int index, int val) {
        
        nums[index].push_back({snap_id, val});
        
    }
    
    int snap() {
        snap_id++;

        return snap_id-1;
        
    }
    
    int get(int index, int snap_id) {

        // auto arr = nums[index];
        int ans = -1;
        
        int l = 0;
        int h = nums[index].size()-1;
        
        while(l <= h){
            int mid= l + (h-l)/2;
            
            if(nums[index][mid].first <= snap_id){
                ans = nums[index][mid].second;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        
        return ans;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */