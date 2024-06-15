/*
给定两个以 有序链表 形式记录的训练计划 l1、l2，分别记录了两套核心肌群训练项目编号，请合并这两个训练计划，按训练项目编号 升序 记录于链表并返回。

注意：新链表是通过拼接给定的两个链表的所有节点组成的。

 

示例 1：

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

0 <= 链表长度 <= 1000

 

注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/7fnm66/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode *curr1, *prev1, *curr2, *prev2;
        curr1 = l1; 
        prev1 = l1;
        curr2 = l2; 
        prev2 = l2;
        if(curr1 == nullptr){
            return l2;
        }

        if(curr2 == nullptr){
            return l1;
        }

        if(curr2->val >= curr1->val){ //l2 has larger begin, insert all curr2 into curr1, return l1
            while(curr2 != nullptr){
                while(curr1 != nullptr){
                    if(curr2->val >= curr1->val){
                        prev1 = curr1;
                        curr1 = curr1->next;
                    } else { //curr2 > curr1, insert curr2 before curr1
                        auto temp2 = curr2->next;
                        curr2->next = nullptr; //take curr2 out of l2

                        prev1->next = curr2;
                        curr2->next = curr1;

                        prev1 = curr2;
                        curr2 = temp2;
                        break;
                    }
                }
                if(curr1 == nullptr){ //insert remaining l2 into l1
                    prev1->next = curr2;
                    return l1;
                }
            }
            //exit while loop, then curr1 != nullptr, and curr2 == nullptr
            return l1;
        } else { //insert all curr1 into curr2, return l2
            while(curr1 != nullptr){
                while(curr2 != nullptr){
                    if(curr1->val >= curr2->val){
                        prev2 = curr2;
                        curr2 = curr2->next;
                    } else { //curr2 > curr1, insert curr2 before curr1
                        auto temp1 = curr1->next;
                        curr1->next = nullptr; //take curr1 out of l1

                        prev2->next = curr1;
                        curr1->next = curr2;

                        prev2 = curr1;
                        curr1 = temp1;
                        break;
                    }
                }
                if(curr2 == nullptr){ //insert remaining l1 into l2
                    prev2->next = curr1;
                    return l2;
                }
            }
            //exit while loop, then curr2 != nullptr, and curr1 == nullptr
            return l2;
        }
    }
};