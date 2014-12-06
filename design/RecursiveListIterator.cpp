#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class ListElement
{
public:
	virtual bool hasNext() {};
	virtual int next() {};
};

class List: public ListElement
{
public:
	List()
	{
		init = false;
	}

	virtual bool hasNext()
	{
		if(!init)
		{
			iter = list.begin();
			init = true;
		}
		if(iter == list.end()) return false;
		while(iter != list.end() && (*iter)->hasNext() == false)
		{
			iter++;
		}
		return iter != list.end();
	}

	virtual int next()
	{
		if(iter == list.end()) return INT_MIN;
		while(iter != list.end() && !(*iter)->hasNext())
		{
			iter++;
		}
		if(iter == list.end())
			return INT_MIN;
		return (*iter)->next();
	}

	void push_back(ListElement* element)
	{
		list.push_back(element);
	}

private:
	vector<ListElement*> list;
	vector<ListElement*>::iterator iter;
	bool init;
};


class SingleElement: public ListElement
{
public:
	SingleElement()
	{
		visit = false;
	}

	void set(int t)
	{
		element = t;
	}

	virtual bool hasNext()
	{
		return !visit;
	}

	virtual int next()
	{
		visit = true;
		return element;
	}
private:
	int element;
	bool visit;
};

int main()
{
	SingleElement single[21];
	for(int i=1; i<21; i++)
	{
		single[i].set(i);
	}

	List list;
	List list1;
	List list2;
	List list3;
	List list4;
	List list5;
	List list6;
	List list7, list8;

	for(int i=1; i<=5; i++)
		list1.push_back(&single[i]);

	list3.push_back(&single[6]);
	list4.push_back(&single[7]);

	for(int i=9; i<=11; i++)
		list5.push_back(&single[i]);

	for(int i=12; i<=14; i++)
		list7.push_back(&single[i]);
	list5.push_back(&list7);

	for(int i=15; i<=16; i++)
		list5.push_back(&single[i]);

	list6.push_back(&single[17]);
	list6.push_back(&single[18]);
	list6.push_back(&list8);
	list6.push_back(&single[19]);
	list6.push_back(&single[20]);

	list.push_back(&list1);
	list.push_back(&list2);
	list.push_back(&list3);
	list.push_back(&list4);
	list.push_back(&single[8]);
	list.push_back(&list5);
	list.push_back(&list6);

	while(list.hasNext())
		cout << list.next() << endl;

	return 0;
}
