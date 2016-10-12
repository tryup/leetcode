/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if( lists.size() ==0 )
        {
            return nullptr;
        }
        ListNode* root = nullptr;
        ListNode* cur = nullptr;
        ListNode* t = nullptr;
        root = GetNext(lists);
        cur = root;
        if(nullptr == root )
        {
            return root;
        }
        while(true)
        {
            cur->next = GetNext(lists);
            if( nullptr == cur->next )
                break;
            cur = cur->next;
        }
        return  root;
    }

    ListNode* GetNext(vector<ListNode*>& lists)
    {
        ListNode* min = lists[0];
        int minind = 0;
        int ind = 0;
        for( auto &i : lists)
        {
            if(nullptr != i )
            {
                if( (nullptr == min) ||  (min->val > i->val))
                {
                    min = i;
                    minind = ind;
                }
            }
            ind++;
        }
        if(  nullptr != min)
        {
            lists[minind] = lists[minind]->next;
        }
        return min;
    }
};
