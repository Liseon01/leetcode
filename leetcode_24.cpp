class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 기저 조건: 리스트가 비었거나 노드가 1개만 남은 경우
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;

        // 재귀 호출로 다음 쌍을 처리
        first->next = swapPairs(second->next);
        second->next = first;

        // 새로운 헤드 반환
        return second;
    }
};