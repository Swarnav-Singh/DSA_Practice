class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        int largest = nums[nums.size()-1];

        while (largest % smallest != 0) {
            int rem = largest % smallest;
            largest = smallest;
            smallest = rem;
        }

        return smallest;
    }
};