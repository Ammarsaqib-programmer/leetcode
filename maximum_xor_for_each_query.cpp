class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> answer(n);
        
        // Calculate the maximum value with `maximumBit` bits set
        int maxVal = (1 << maximumBit) - 1;
        
        // Calculate the cumulative XOR of all elements
        int cumulativeXor = 0;
        for (int num : nums) {
            cumulativeXor ^= num;
        }
        
        // Calculate the result for each query in reverse order
        for (int i = 0; i < n; ++i) {
            answer[i] = cumulativeXor ^ maxVal; // Optimal k for maximum XOR
            cumulativeXor ^= nums[n - 1 - i];   // Remove the last element from cumulativeXor
        }
        
        return answer;
    }
};
maximum_xor_for_each_query
