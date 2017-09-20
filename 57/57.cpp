#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
bool compare(const Interval& a, const Interval& b){
	return a.start < b.start;
}
class Solution {
        public:
        vector<Interval> insert(vector<Interval>& intervals, Interval nn){
                vector<Interval> res;
		int pushn = 0;
		for (int i = 0 ; i < intervals.size() ; i++){
			Interval cur = intervals[i];
			if (nn.end < cur.start && !pushn){
				res.push_back(nn);
				res.push_back(cur);
				pushn = 1;
			} else if ( (cur.start <= nn.start  && nn.start <= cur.end)||
				    (nn.start<= cur.start && cur.start <= nn.end))
			{
					nn.start = min(cur.start, nn.start);
					nn.end = max(cur.end, nn.end);
			} else {
				res.push_back(cur);
			}
		}
		if (!pushn)
			res.push_back(nn);
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
