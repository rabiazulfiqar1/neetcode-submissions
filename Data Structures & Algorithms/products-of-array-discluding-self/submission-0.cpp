class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes(nums.size());
        prefixes[0] = 1;
        vector<int> suffixes(nums.size());
        for (int i=1; i<nums.size(); i++) {
            prefixes[i] = prefixes[i-1]*nums[i-1];
        }
        suffixes[nums.size()-1] = 1;
        for (int i=nums.size()-2; i>=0; i--) {
            suffixes[i] = nums[i+1]*suffixes[i+1];
        }
        vector<int> result;
        for (int i=0; i<nums.size(); i++) {
            result.push_back(prefixes[i]*suffixes[i]);
        }
        return result;
    }
};
