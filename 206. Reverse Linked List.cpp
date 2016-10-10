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
    ListNode* reverseList(ListNode* head) {
        decltype(head) newhead = nullptr;//新的头指针,类似堆栈了，这个是栈底元素
        decltype(head) oldhead(head);
        while(  oldhead )
        {
            ListNode* _thead = oldhead->next;//临时保存目前节点的下个节点
            oldhead->next = newhead;//反转,类似入栈,这个节点的下几个是新的头指针
            newhead = oldhead;//栈指针移动
            oldhead = _thead;//移动老的节点
        }
        return newhead;
    }
};

//还有一种方法就是使用栈进行操作
