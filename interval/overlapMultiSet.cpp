#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

struct Interval
{
    int head,tail;
	int label;
	Interval(int h,int t,int l)
	{
		head=h;
		tail=t;
		label=l;
	}
	Interval(int h,int t){
		head=h;
		tail=t;
		label=0;
	}
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

bool cmp(const Point& a,const Point& b){
	return a.pos<b.pos || (a.pos==b.pos && a.tag>b.tag);
}

vector<Interval> intersect(vector<vector<Interval> > intervals)
{
	vector<Interval> ret;
	vector<Point> points;
	for(int i=0;i<intervals.size();i++)
	{
		for(int j=0;j<intervals[i].size();j++)
		{
			points.push_back(Point(intervals[i][j].head,i+1));
			points.push_back(Point(intervals[i][j].tail,-i-1));
		}
	}
	sort(points.begin(),points.end(),cmp);

	int count[intervals.size()+1]; //flag the entrance and exit point for each interval set
    for(int i=0;i<intervals.size()+1;i++)
        count[i]=0;
	int pre=0;  //flag the last entrance
	int prec=0; //flag the num. of overlaps
	int size=intervals.size();

	for(int i=0;i<points.size();i++)
	{
		if(points[i].tag>0)
		{
			if(count[points[i].tag]==0)
			{
				prec++;
                pre=points[i].pos;
			}
			count[points[i].tag]++;
		}
		else
		{
			count[abs(points[i].tag)]--;
			if(count[abs(points[i].tag)]==0)
			{
			    if(prec==size)
			    {
				    ret.push_back(Interval(pre,points[i].pos));
			    }
				prec--;
			}
		}
      //  cout<<"prec: "<<prec<<endl;
	}
    return ret;
}

void print(vector<Interval> p)
{
	for(int i=0;i<p.size();i++)
		cout<<p[i].head<<" "<<p[i].tail<<endl;
}

int main()
{
	vector<Interval> ia;
	ia.push_back(Interval(1, 5));
	ia.push_back(Interval(7, 12));
	ia.push_back(Interval(13, 20));
	vector<Interval> ib;
    ib.push_back(Interval(4, 9));
    ib.push_back(Interval(10, 15));
	vector<Interval> ic;
	ic.push_back(Interval(3, 9));
	ic.push_back(Interval(8, 11));

	vector<vector<Interval> > data;
	data.push_back(ia);
	data.push_back(ib);
	data.push_back(ic);

	vector<Interval> ret=intersect(data);
	print(ret);

}
