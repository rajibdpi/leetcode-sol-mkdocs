class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    return dfs(ring, key, 0, {}) + key.length();
  }

 private:
  // # of rotates of ring to match key[index:]
  int dfs(const string& ring, const string& key, int index,
          unordered_map<string, int>&& memo) {
    if (index == key.length())
      return 0;
    // Add the index to prevent duplicate
    const string hashKey = ring + to_string(index);
    if (const auto it = memo.find(hashKey); it != cend(memo))
      return it->second;

    int ans = INT_MAX;

    // For each ring[i] == key[index]
    // We rotate the ring to match ring[i] w/ key[index]
    // Then recursively match newRing w/ key[index + 1:]
    for (size_t i = 0; i < ring.length(); ++i)
      if (ring[i] == key[index]) {
        const int minRotates = min(i, ring.length() - i);
        const string& newRing = ring.substr(i) + ring.substr(0, i);
        const int remainingRotates = dfs(newRing, key, index + 1, move(memo));
        ans = min(ans, minRotates + remainingRotates);
      }

    return memo[hashKey] = ans;
  }
};
