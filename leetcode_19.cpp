class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);  // 가상 노드 추가
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 빠른 포인터를 n + 1 만큼 이동
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // 빠른 포인터가 끝에 도달할 때까지 두 포인터를 함께 이동
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 느린 포인터의 다음 노드를 삭제
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;  // 메모리 해제

        ListNode* newHead = dummy->next;
        delete dummy;  // 가상 노드 해제
        return newHead;
    }
};