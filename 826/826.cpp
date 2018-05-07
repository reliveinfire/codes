#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
struct Element{
	int profit;
	int difficulty;
};
bool compare(const Element& a, const Element& b){
	if (a.difficulty == b.difficulty)
		return a.profit < b.profit;
	else
		return	a.difficulty < b.difficulty;
}
class Solution {
        public:
        int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
		vector<Element> tmp;
		int max_profit = 0;
		int res = 0;
		for(int i = 0 ; i < difficulty.size() ; i++){
			Element e;
			e.profit = profit[i];
			e.difficulty = difficulty[i];
			tmp.push_back(e);
		}
		sort(tmp.begin(), tmp.end(), compare);
		sort(worker.begin(), worker.end());
		int i = 0, j = 0;
		while(true){
			while(i < tmp.size() && tmp[i].difficulty <= worker[j]){
				max_profit = max(max_profit, tmp[i].profit);
				i++;
			}
			if (i==tmp.size())
				break;
			res += max_profit;
			j++;
			if (j == worker.size())
				break;
		}
		for (; j < worker.size() ; j++){
			if (worker[j] >= tmp[i-1].difficulty )
				res += max_profit;
		}
		return res;
        }
};
