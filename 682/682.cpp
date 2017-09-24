#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
	public:
		int calPoints(vector<string>& ops){
			vector<int> tmp;
			int sum = 0;
			for (int i = 0 ; i < ops.size() ; i++){
				int num;
				int size = tmp.size();
				if (ops[i]=="+"){
					num = tmp[size-1] + tmp[size-2];
					sum += num;
					tmp.push_back(num);
				} else if (ops[i]=="D"){
					num = tmp[size-1] * 2;
					sum += num;
					tmp.push_back(num);
				} else if (ops[i]=="C"){
					num = tmp[size-1] * -1;
					sum += num;
					tmp.pop_back();
				} else {
					num = stoi(ops[i]);
					sum += num;
					tmp.push_back(num);
				}
			}
			return sum;
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
