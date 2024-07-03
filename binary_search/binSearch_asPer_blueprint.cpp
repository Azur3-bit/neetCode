
int min = *min_element(piles.begin(), piles.end());
int max = *max_element(piles.begin(), piles.end());
while (max - min > 1) {
	int curr_hours = 0;
	int mid = min + (max - min) / 2;
	for (auto it : piles) {
		if (it % mid == 0) {
			curr_hours += it / mid;

		}
		if (it % mid != 0) {
			curr_hours += it / mid;
			curr_hours++;
		}
	}
	// break;
	if (curr_hours > h)
		min = mid;
	else
		max = mid;
}
return max;
