#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
bool compare(const Interval& a, const Interval& b)
{
	return a.start == b.start ? a.end < b.end : a.start < b.start;
}
class Solution {
        public:
        vector<Interval> merge(vector<Interval>& intervals){
		if (intervals.empty())
		vector<Interval> res;
		sort(intervals.begin(), intervals.end(), compare);
		Interval tmp = intervals[0];
		for (int i = 1 ; i < intervals.size() ; i++){
			if (intervals[i].start <= tmp.end){
				tmp.end = max(intervals[i].end, tmp.end);
			} else {
				res.push_back(tmp);
				tmp = intervals[i];
			}
		}
		res.push_back(tmp);
		return res;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
