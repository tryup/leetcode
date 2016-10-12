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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if( nullptr == l1)
        {
            return l2;
        }
        if( nullptr == l2 )
        {
            return l1;
        }

        ListNode* root(nullptr);
        ListNode* cur(nullptr);
        ListNode* t(nullptr);
        for( ;; )
        {

            if(nullptr == l1 && l2 == nullptr)
            {
                break;
            }
            if( nullptr == l1)
            {
                cur->next = l2;
                break;
            }
            if( nullptr == l2)
            {
                cur->next = l1;
                break;
            }

            if( l1->val < l2->val )
            {
                t = l1;
                l1=l1->next;
            }
            else
            {
                t = l2;
                l2=l2->next;
            }
            if( nullptr == root )
            {
                root = t;
                cur = t;
            }
            else
            {
                cur->next = t;
                cur = cur->next == nullptr ? cur : cur->next;
            }

        }
        return root;
    }
};
