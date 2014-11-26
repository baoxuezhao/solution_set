//given a set of intervals (unsorted and has overlaps)
//find the set of intervals overlapped at least k times

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

struct Interval
{
	int head;
	int tail;

	Interval(int h, int t): head(h), tail(t){}
};

struct Point
{
	int pos;
	int tag; //tag>0 start point <0 end point
	Point(int p,int t){
		pos=p;
		tag=t;
	}
};

bool cmp(const Point &p1, const Point &p2)
{
	return (p1.pos < p2.pos) ||
		(p1.pos == p2.pos && p1.tag > p2.tag);
}

vector<Interval> getIntervals(vector<Interval> &ins, int min_overlap)
{
	const int n = ins.size();
	vector<Point>  points;
	vector<Interval> result;

	for(int i=0; i<ins.size(); i++)
	{
		points.push_back(Point(ins[i].head, i+1));
		points.push_back(Point(ins[i].tail, -i-1));
	}

	std::sort(points.begin(), points.end(), cmp);

	int overlap = 0;
	int start = -1;
	for(int i=0; i<points.size(); i++)
	{
		if(points[i].tag > 0)
		{
			overlap++;
			if(overlap == min_overlap) start = points[i].pos;
		}
		else
		{
			overlap--;
			if(overlap == min_overlap-1 && start != -1)
			{
				result.push_back(Interval(start, points[i].pos));
			}
		}
	}
	return result;
}


int main()
{
	vector<Interval> ins;
	ins.push_back(Interval(1, 4));
	ins.push_back(Interval(2, 5));
	ins.push_back(Interval(3, 6));
	ins.push_back(Interval(7, 9));
	ins.push_back(Interval(10,12));
	ins.push_back(Interval(11,14));

	vector<Interval> res = getIntervals(ins, 2);

	for(int i=0; i<res.size(); i++)
	{
		cout << "[" << res[i].head << "," << res[i].tail << "]" << endl;
	}
	return 0;
}
