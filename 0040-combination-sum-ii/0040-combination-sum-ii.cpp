class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void backtrack(vector<int>& cand, int target, int start) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i < cand.size(); i++) {
            // Skip duplicates
            if (i > start && cand[i] == cand[i - 1]) continue;

            // Stop if number exceeds target
            if (cand[i] > target) break;

            temp.push_back(cand[i]);
            backtrack(cand, target - cand[i], i + 1);  // move to next index
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return result;
    }
};
