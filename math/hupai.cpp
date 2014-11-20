#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX_TILE_INDEX 34
int tiles[MAX_TILE_INDEX];

void init()
{
	for(int i=0; i<MAX_TILE_INDEX; i++)
		tiles[i] = 0;
}

struct Hupai
{
	vector<vector<int> > sequence;
	int pair;

	Hupai() {}
};

bool range(int idx, int low, int high)
{
	return (idx >= low && idx <= high);
}

void dfs(Hupai &cur, vector<Hupai> &result)
{
	int idx;
	for(idx=0; idx < MAX_TILE_INDEX; idx++)
		if(tiles[idx])
			break;

	if(idx == MAX_TILE_INDEX)
	{
		result.push_back(cur);
		return;
	}

	if(tiles[idx] >= 1)
	{
		if(range(idx, 0, 6) || range(idx, 9, 15) || range(idx, 18, 24))
		{
			if(tiles[idx+1] > 0 || tiles[idx+2] > 0)
			{
				tiles[idx]--;
				tiles[idx+1]--;
				tiles[idx+2]--;
				vector<int> seq;
				seq.push_back(idx);
				seq.push_back(idx+1);
				seq.push_back(idx+2);
				cur.sequence.push_back(seq);

				dfs(cur, result);

				cur.sequence.pop_back();
				tiles[idx]++;
				tiles[idx+1]++;
				tiles[idx+2]++;
			}
		}
	}

	if(tiles[idx] >= 3)
	{
		tiles[idx] -= 3;
		vector<int> seq(3, idx);
		cur.sequence.push_back(seq);

		dfs(cur, result);

		cur.sequence.pop_back();
		tiles[idx] += 3;
	}
}

vector<Hupai> isWin()
{
	vector<Hupai> result;
	int sum = 0;
	
	for(int i=0; i<MAX_TILE_INDEX; i++)
		sum += tiles[i];
	if(sum != 14)
		return result;

	for(int i=0; i<MAX_TILE_INDEX; i++)
	{
		if(tiles[i] >= 2)
		{
			Hupai pai;
			pai.pair = i;

			tiles[i] -= 2;
			dfs(pai, result);
			tiles[i] += 2;
		}
	}
	return result;
}

void print(vector<Hupai> &res)
{
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].sequence.size(); j++)
		{
			cout << "[";
			for(int k=0; k<res[i].sequence[j].size(); k++)
			{
				cout << res[i].sequence[j][k] << ", ";
			}
			cout << "], ";
		}
		cout << res[i].pair << endl;
	}
	cout << endl;
}

int main()
{
	init();
	tiles[0] = 4;
	tiles[1] = 4;
	tiles[2] = 4;
	tiles[3] = 2;

	vector<Hupai> res = isWin();
	print(res);

	init();
	tiles[0] = 3;
	tiles[1] = 3;
	tiles[2] = 3;
	tiles[6] = 3;
	tiles[9] = 2;
	vector<Hupai> res2 = isWin();
	print(res2);

	return 0;
}
