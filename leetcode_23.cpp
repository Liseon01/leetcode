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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; // 빈 리스트 처리

        // Divide and Conquer 방식으로 리스트 병합
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(merge(list1, list2));
            }

            lists = mergedLists;
        }

        return lists.front(); // 최종 병합된 리스트 반환
    }
private:
    ListNode* merge(ListNode* &list1, ListNode* &list2){
        ListNode* dummy = new ListNode(0); // 더미 노드 생성
        ListNode* current = dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                current->next = list1;
                list1 = list1->next; 
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if(list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        ListNode* res = dummy->next;
        delete dummy; // 메모리 해제
        return res;
    }
};
