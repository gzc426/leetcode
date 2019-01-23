```
class Solution {
public:
	vector<vector<int>> result;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		combinate(candidates, candidates.size() - 1, {}, target);
		return result;
	}
	void combinate(vector<int>& candidates, int pos, vector<int>contain, int target)
	{
		if (target == 0)
			result.push_back(contain);
		if (target < 0)
			return;
		for (int i = pos; i >= 0; i--)
		{
			if (i != pos && candidates[i] == candidates[i + 1]) //important!
				continue;
			contain.push_back(candidates[i]);
			combinate(candidates, i - 1, contain, target - candidates[i]);
			contain.pop_back();
		}
	}
};
```
