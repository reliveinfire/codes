#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int quick_select(vector<int> nums, int k, int start, int end)
{
	int pivot = nums[start];
	int l = start + 1;
	int r = end;
	int tmp;

//#define DEBUG
#ifdef DEBUG
	cout << "start:" << start;
	cout << " end:" << end;
	cout << " pivot:" << pivot << "\n";
#endif
/* quick sort and quick select 要檢查邊界, 與 l>=r for 極端case*/
	while(true) {
				// 這邊的邊界條件可以改
				//  l < end, r > start
		while(nums[l] < pivot && l+1 <= end)
			l++;
		while(nums[r] > pivot && r-1 >= start)
			r--;
		if (l >= r)
			break;
		tmp = nums[l];
		nums[l] = nums[r];
		nums[r] = tmp;
	}
#ifdef DEBUG
	cout << "r:" << r << "\n";
#endif
	tmp = nums[start];
	nums[start] = nums[r];
	nums[r] = tmp;

#ifdef DEBUG
	for (int i = 0 ; i < nums.size() ; i++)
		cout << " " << nums[i];
	cout << "\n";

#endif

	if (r==k) 
		return nums[r];

	if ( k < r)	
		return quick_select(nums, k, start, r - 1);
	else
		return quick_select(nums, k, r + 1, end);
}

void quicksort(vector<int>& nums, int start, int end)
{
	int pivot = nums[start];
	int l = start + 1;
	int r = end;
	int tmp;
	if (start >= end)
		return;
#ifdef DEBUG
	cout << "start:" << start;
	cout << " end:" << end;
	cout << " pivot:" << pivot << "\n";
#endif

	while (true) {
		while (nums[l] < pivot && l+1 <= end) // l < end
			l++;
		while (nums[r] > pivot && r-1 >= start) // r >start
			r--;
		if(l>=r)
			break;
		tmp = nums[l];
		nums[l] = nums[r];
		nums[r] = tmp;
	}
	tmp = nums[r];
	nums[r] = nums[start];
	nums[start] = tmp;

#ifdef DEBUG
	for (int i = 0 ; i < nums.size() ; i++)
		cout << " " << nums[i];
	cout << "\n";
#endif

	if (r!= start || r!= end){
	quicksort(nums, start, r - 1);
	quicksort(nums, r + 1, end);
	}

	return;
}
int main()
{
	int ret;
	int k = 10;
	int test[] = {10,8,1,6,7,3,5,9,4,2};
	//int test[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(test)/sizeof(test[0]);
	vector<int> data(test, test + size);
	vector<int> data2(test, test + size);

	quicksort(data, 0 , size - 1);
	for (int i = 0 ; i < data.size() ; i++)
		cout << " " << data[i];
	cout << "\n";

	cout << quick_select(data2, k - 1, 0 , size - 1) << "\n";
	return 0;

}
