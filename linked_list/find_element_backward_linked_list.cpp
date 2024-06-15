/*
给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第 cnt 个训练项目编号。

 

示例 1：

输入：head = [2,4,7,8], cnt = 1
输出：8
 

提示：

1 <= head.length <= 100
0 <= head[i] <= 100
1 <= cnt <= head.length

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/7f2ng5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* trainingPlan(ListNode* head, int cnt) {
        auto slow = head;
        auto fast = head;
        for(std::size_t i = 1; i <= cnt; ++i){
            fast = fast->next;
        }
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};