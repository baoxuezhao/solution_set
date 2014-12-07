/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool comp(const ListNode *l1, const ListNode *l2)
{
	return l1->val < l2->val;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode*> vec;
        for(int i=0; i<lists.size(); i++)
        	if(lists[i])
        		vec.push_back(lists[i]);

        make_heap(vec);

        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while(vec.size())
        {
        	ListNode* t = pop_heap(vec);
        	cur->next = t;
        	cur = cur->next;
        	if(t->next)
        	{
        		//cout << t->val << "\t" << t->next->val << endl;
        		push_heap(vec, t->next);
        	}
        }
        return dummy.next;
    }

private:
	void make_heap(vector<ListNode*> &lists)
	{
		const int n = lists.size();
		for(int i=n-1; i>=0; i--)
			heapify(lists, i, n);
	}

	void push_heap(vector<ListNode*> &lists, ListNode* node)
	{
		lists.push_back(node);
		int cur = lists.size()-1;
		int parent = (cur-1)/2;
		while(cur >= 1 && !comp(lists[parent], lists[cur]))
		{
			swap(lists[parent], lists[cur]);
			cur = parent;
			parent = (cur-1)/2;
		}
	}

	ListNode* pop_heap(vector<ListNode*> &lists)
	{
		ListNode *res = lists[0];
		lists[0] = lists[lists.size()-1];
		lists.pop_back();
		heapify(lists, 0, lists.size());
		return res;
	}


	void heapify(vector<ListNode*> &lists, int i, int n)
	{
		int left = 2*i + 1, right = 2*i + 2;
		int small = i;

		if(left < n && comp(lists[left], lists[small]))
			small = left;

		if(right < n && comp(lists[right], lists[small]))
			small = right;

		if(small != i)
		{
			swap(lists[small], lists[i]);
			heapify(lists, small, n);
		}
	}
};
