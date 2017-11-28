#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> asteroidCollision(vector<int>& as){
		vector<int> res;
		deque<int> dq;
		for (int i = 0 ; i < as.size() ; i++){
			if (as[i] < 0){
				while(!dq.empty()){
					if (dq.back() < abs(as[i]))
						dq.pop_back();
					else
						break;
				}
				if (dq.empty())
					res.push_back(as[i]);
				else {
					if (dq.back() == abs(as[i]))
						dq.pop_back();
				}
			} else {
				dq.push_back(as[i]);
			}
		}
		while(!dq.empty()){
			res.push_back(dq.front());
			dq.pop_front();
		}
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
