class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int target = k - 1;
        while (true) {  
            int p = partition(nums, left, right);
            if (p == target) return nums[p];
            else if (p < target) left = p + 1;
            else right = p - 1;
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int slow = left;
        for (int fast = left; fast < right; fast++) {
            if (nums[fast] >= pivot) {
                swap(nums[fast], nums[slow++]);
            }
        }
        swap(nums[slow], nums[right]);
        return slow;
    }
};
