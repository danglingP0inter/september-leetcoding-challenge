class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0], currMin = nums[0], prevMax = nums[0], prevMin = nums[0];
        int ans = nums[0];
        for(int i = 1; i< nums.size(); i++) {
            currMax = max(nums[i], max(prevMin*nums[i], prevMax*nums[i]));
            currMin = min(nums[i], min(prevMin*nums[i], prevMax*nums[i]));
            ans = max(ans, currMax);
            prevMax = currMax;
            prevMin = currMin;
        }
        return ans;
    }
};
