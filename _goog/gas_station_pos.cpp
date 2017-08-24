#include "../helpers.cpp"
/*
 *
https://www.careercup.com/question?id=5199985426563072

We have N gas stations, and we are given all the distances between each pair of station. So we have nC2 distances provided to us. For example if I have 3 stations namely A, B, C the distances provided will be AB, AC, BC. We have to find the exact position of each gas station provided with these nC2 distances.

eg. we have 5 stations so 5C2 distances are given in random order - 10, 20, 70, 80, 30, 20, 100, 70, 50, 90

Output the exact positions of gas stations A, B, C, D, E
i.e
A - 0
B - 10
C - 30
D - 80
E - 100
 
 */
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
	vector<int> ans;
        vector<int> gaspos(int n, vector<int>& dis){
		unordered_set<int> pos;
		vector<int> used(dis.size(), 0);
		pos.insert(0);
		helper(n, pos, dis, used);
		return ans;
        }
	void helper(int n, unordered_set<int>& pos, vector<int>& dis, vector<int>& used)
	{
		if (pos.size()==n && ans.empty()){
			for (auto ii = pos.begin() ; ii != pos.end() ; ii++)
				ans.push_back(*ii);
			return;
		}
		for (int i = 0 ; i < dis.size() ; i++){
			if (!used[i] && pos.count(dis[i])==0){
				vector<int> diffs;
				//cout << "new one:" << dis[i] << endl;
				for (auto iter = pos.begin() ; iter!=pos.end() ; iter++){
					int diff = abs(dis[i] - *iter);
					//cout << "diff:" << diff << endl;
					diffs.push_back(diff);
				}
				pos.insert(dis[i]);
				int j;
				vector<int> tmp;
				for (j = 0 ; j < diffs.size() ; j++){
					int k;
					for (k = 0 ; k < dis.size() ; k++){
						if (diffs[j] == dis[k] && !used[k]){
							used[k] = 1;
							tmp.push_back(k);
							break;
						}
					}
					if (k== dis.size())
						break;
				}
				if (j == diffs.size()){
					helper(n, pos, dis, used);
				}
				for (int k = 0 ; k < tmp.size() ; k++){
					if (used[tmp[k]])
						used[tmp[k]] = 0;
				}
				pos.erase(dis[i]);
			}
		}
		return;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {10,20,30};
	vector<int> B = {10,20,70,80,30,20,100,70,50,90};
	vector<int> C = {10,10,20,30,70,80,100,190,200,260,270,270,280,290,300};
	Solution sol;
//	auto ret_vec = sol.gaspos(3, A);
//	auto ret_vec = sol.gaspos(5, B);
	auto ret_vec = sol.gaspos(6, C);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
