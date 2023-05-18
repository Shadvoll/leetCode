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
    ListNode *swapPairs(ListNode *head)
    {
        if (head==nullptr || head->next==nullptr) return head;
        ListNode *currentNode = head->next;
        ListNode *nextNode = currentNode->next;
        currentNode->next = head;
        head->next = swapPairs(nextNode);
        return currentNode;
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