#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class BloodRelation
{
public:
	BloodRelation(unordered_map<int, pair<int,int> > &map)
	{
		this->map = map;
	}

	bool isRelated(int id1, int id2)
	{
		hash.clear();
		queue<int> queue;

		hash.insert(id1);
		queue.push(id1);
		while(!queue.empty())
		{
			int cur = queue.front();
			queue.pop();

			if(map.find(cur) != map.end())
			{
				pair<int,int> parents = map[cur];

				hash.insert(parents.first);
				queue.push(parents.first);

				hash.insert(parents.second);
				queue.push(parents.second);
			}
		}

		queue.push(id2);
		while(!queue.empty())
		{
			int cur = queue.front();
			queue.pop();
			if(hash.find(cur) != hash.end())
				return true;

			if(map.find(cur) != map.end())
			{
				pair<int,int> parents = map[cur];
				queue.push(parents.first);
				queue.push(parents.second);
			}
		}
		return false;
	}

private:
	unordered_map<int, pair<int,int> > map;
	unordered_set<int> hash;
};

int main()
{
	unordered_map<int, pair<int,int> > map;
	map[7] = make_pair(5,6);
	map[5] = make_pair(1,2);
	map[6] = make_pair(3,4);
	map[11] = make_pair(9,10);
	map[9] = make_pair(4,8);

	BloodRelation relation(map);
	cout << relation.isRelated(7, 11) << endl;
	cout << relation.isRelated(7, 9) << endl;
	cout << relation.isRelated(5, 11) << endl;
	cout << relation.isRelated(6, 11) << endl;
	cout << relation.isRelated(7, 10) << endl;

	return 0;
}
