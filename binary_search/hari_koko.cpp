// hari_koko

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minEatingSpeed(vector<int> piles, int h)
{
	cout << "inside func \n";
	int first = *min_element(piles.begin(), piles.end());
	int last = *max_element(piles.begin(), piles.end());
	cout << "min " << first << " max " << last << endl;

	int hrs = 0;

	while (last - first > 1)
	{
		int mid = (first + last) / 2;
		cout << mid << " -> mid  " << endl;
		hrs = 0;

		// for (int i = 0; i < piles.size(); i++)
		// {
		// 	cout << "total hours now : " << hrs << "\n";
		// 	int data = piles[i];
		// 	cout << "it : " << data << "\n";
		// 	int rem = data % mid;
		// 	// cout << rem <<"  -> rem " << endl;
		// 	if (rem != 0) {
		// 		cout << "-- rem != 0\n";
		// 		hrs = hrs + (data / mid) + 1;
		// 	}
		// 	else {
		// 		cout << "--++ rem == 0\n";
		// 		hrs = hrs + (data / mid);
		// 	}
		// }
		for (auto it : piles) {
			if (it % mid == 0) {
				cout << "-- if --- current hours => " << hrs << "... now : ";
				hrs += it / mid;
				cout << hrs << "\n";

			}
			if (it % mid != 0) {
				cout << "-- else -- current hours => " << hrs << "... now : ";
				hrs += it / mid;
				hrs++;
				cout << hrs << "\n";
			}
		}

		cout << hrs << " -> hrs " << endl;

		if (hrs > h)
		{
			first = mid ;
		}
		else
		{
			last = mid ;
		}
		cout << "min " << first << " max " << last << endl;
		if (hrs == h)
		{
			cout << "total hrs == h\n";
			return last;
		}
	}
	return last;
}

int main()
{
	vector<int> piles = {3, 6, 7, 11};
	int ans = minEatingSpeed(piles, 8);
	cout << "answer : " << ans << "\n";

//     Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

	return 0;
}
