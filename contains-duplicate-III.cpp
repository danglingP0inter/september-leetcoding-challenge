class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //O(n^2) won't pass; Difficult than what I thought first :(
        
        vector<pair<long, long>> a;
        for(int i=0;i<nums.size();i++)
            a.push_back({nums[i], i});
        
        sort(a.begin(), a.end());
        int low = 0;
        int high = 1;
        while(high<nums.size()) {
            if((abs(a[low].first - a[high].first) <= t) && (abs(a[low].second - a[high].second) <= k))
                return true;
            else if(abs(a[low].first - a[high].first) > t) {
                low++;
                high = low+1;
            } else {
                high++;
            }
        }
        return false;
    }
};
