class Solution {
 public:
  int minDeletion(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i + 1 < nums.size(); ++i)
      // I - ans := index after deletion
      if (nums[i] == nums[i + 1] && (i - ans) % 2 == 0)
        ++ans;

    return ans + ((nums.size() - ans) & 1);
  }
};
