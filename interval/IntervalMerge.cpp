//merge of intervals with discrete points.

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_NUM 12

int map[MAX_NUM];

struct Interval
{
	int start;
	int end;
	Interval(int s, int e): start(s), end(e){};
};

void mergeDiscrete(vector<Interval> &intervals)
{
	memset(map, -1, sizeof(map));
	for(int i=0; i<intervals.size(); i++)
	{
		if(intervals[i].end > map[intervals[i].start])
			map[intervals[i].start] = intervals[i].end;
	}

	int curmax = -1;
	for(int i=0; i<MAX_NUM; i++)
	{
		if(map[i] > 0)
			curmax = max(curmax, map[i]);
		else
		{
			if(i <= curmax)
				map[i] = 1;
			else
				curmax = -1;
		}
	}

	intervals.clear();

	int start = -1;
	for(int i=0; i<MAX_NUM; i++)
	{
		if(start == -1 && map[i] > 0)
			start = i;
		if(start >= 0 && map[i] < 0)
		{
			Interval in(start, i-1);
			intervals.push_back(in);
			start = -1;
		}
	}

	if(start > 0)
	{
		Interval in(start, MAX_NUM-1);
		intervals.push_back(in);
	}
}

int main()
{
	Interval in1(0, 3);
	Interval in2(6, 9);
	Interval in3(8, 10);

	vector<Interval> intervals;
	intervals.push_back(in1);
	intervals.push_back(in2);
	intervals.push_back(in3);

	mergeDiscrete(intervals);
	for(int i=0; i<intervals.size(); i++)
	{
		cout << intervals[i].start << "\t" << intervals[i].end << endl;
	}
	return 0;
}
