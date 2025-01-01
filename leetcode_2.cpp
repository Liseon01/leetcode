/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // 더미 노드 생성
        ListNode* current = dummy; // 결과 리스트를 추적할 포인터
        int carry = 0; // 자리올림값 초기화

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10; // 자리올림값 계산
            current->next = new ListNode(sum % 10); // 현재 자리 값 저장
            current = current->next; // 다음 노드로 이동
        }

        return dummy->next; // 더미 노드의 다음 노드 반환
    }
};