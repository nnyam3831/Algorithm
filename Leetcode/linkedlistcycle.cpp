// space complexity O(1)

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

bool hasCycle(ListNode *head)
{
    ListNode *walker = head;
    ListNode *runner = head;

    while (runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        // runner가 먼저 끝나서 null 되면 사이클 없음
        // 사이클이 있다면 계속 돌 것
        if (runner == walker)
            return true;
    }
    return false;
}