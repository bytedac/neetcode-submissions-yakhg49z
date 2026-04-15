class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // xiaodingdui small to big
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int num : nums) {
            queue.push(num);
            if (queue.size() > k) {
                queue.pop();
            }
        }
        return queue.top();
    }
};
