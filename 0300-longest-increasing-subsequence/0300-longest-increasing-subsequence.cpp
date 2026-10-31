class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                int left = 0; 
                int right = temp.size() - 1;
                while(left < right) {
                    int mid = left + (right-left)/2;
                    if(temp[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                temp[left] = nums[i];
            }
        }
        return temp.size();
    }
};