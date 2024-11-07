class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        std::vector<int> bit_count(32, 0);
        
        for (int num : candidates) {
            for (int bit = 0; bit < 32; ++bit) {
                if (num & (1 << bit)) {
                    bit_count[bit]++;
                }
            }
        }
        return *std::max_element(bit_count.begin(), bit_count.end());
    }
};
