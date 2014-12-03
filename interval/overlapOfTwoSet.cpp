//很多区间已知 请求是一系列整数 判断这个整数是否在这些区间里面 问我如何优化对这些请求的处理

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval(int s, int e): start(s), end(e){};
};

Interval overlap(Interval &in1, Interval &in2)
{
	if(in1.start > in2.end || in2.start > in1.end)
		return Interval(-1, -1);
	else
		return Interval(max(in1.start, in2.start), min(in1.end, in2.end));
}

//merge two sorted interval set
vector<Interval> overlapTwoSet(vector<Interval> &set1, vector<Interval> &set2)
{
	vector<Interval> out;
	if(set1.size() == 0 || set2.size() == 0) return out;

	int idx1 = 0, idx2 = 0;
	while(idx1 < set1.size() && idx2 < set2.size())
	{
		Interval cur1 = set1[idx1];
		Interval cur2 = set2[idx2];

		Interval ol = overlap(cur1, cur2);
		if(ol.start != -1 && ol.end != -1)
			out.push_back(ol);
		if(cur1.end < cur2.end)
			idx1++;
		else
			idx2++;
	}
	return out;
}

int main()
{

	vector<Interval> set1;
	vector<Interval> set2;

	set1.push_back(Interval(0, 3));
	set1.push_back(Interval(4, 6));
	set1.push_back(Interval(8, 10));
	set1.push_back(Interval(12, 13));
	set1.push_back(Interval(15, 17));
	set1.push_back(Interval(19, 21));

	set2.push_back(Interval(2, 5));
	set2.push_back(Interval(7, 9));
	set2.push_back(Interval(11, 14));

	vector<Interval> result = overlapTwoSet(set1, set2);

	for(int i=0; i<result.size(); i++)
	{
		cout << result[i].start << "\t" << result[i].end << endl;
	}
	return 0;
}
