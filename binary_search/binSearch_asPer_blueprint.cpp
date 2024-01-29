class Solution {
public:
	bool searchMatrix(vector<vector<int>>& vec, int target) {

		int rows = vec.size();
		int cols = vec[0].size();

		int start = 0, end = (rows * cols) - 1;

		while (start <= end) {
			int mid = start + (end - start) / 2;

			int row_index = mid / cols;
			int col_index = mid % cols;

			if (vec[row_index][col_index] == target)
				return 1;
			else if (vec[row_index][col_index] < target) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		return 0;
	}
};
