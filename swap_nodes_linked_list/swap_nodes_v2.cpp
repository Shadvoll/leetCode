#include <iostream>
#include <utility>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    void swapPair(ListNode *node)
    {
        ListNode *currentNode = node;
        ListNode *nextNode = node->next;
        std::swap(currentNode->val, nextNode->val);
    }
    ListNode *swapPairs(ListNode *head)
    {
        if (head==nullptr || head->next==nullptr) return head;
        swapPair(head);
        head->next->next = swapPairs(head->next->next);
        return head;
    }
    void showList(ListNode *head)
    {
        std::cout << head->val << ' ';
        while (head->next != nullptr)
        {
            head = head->next;
            std::cout << head->val << ' ';
        }
        std::cout << std::endl;
    }
};

int main()
{
    ListNode linkedList = ListNode(10, new ListNode(5, new ListNode(4, new ListNode(1))));
    Solution().showList(&linkedList);
    ListNode* answerList = Solution().swapPairs(&linkedList);
    Solution().showList(answerList);

    return 0;
}