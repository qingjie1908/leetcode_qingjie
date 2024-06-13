//insertion sort
/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
*/


//Definition for singly-linked list.
#include <iostream>
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
    ListNode* insertionSortList(ListNode* head) {

        if(head->next == nullptr){
            return head;
        }

        //sort first two element
        if(head->val > head->next->val){
            auto temp = head->next;
            head->next = head->next->next;
            temp->next = head;
            head = temp;
        }

        ListNode* curr = head->next->next; //start from third element
        ListNode* prev = head->next;

        ListNode* new_curr = head;
        ListNode* new_prev = head;
        new_curr->next = nullptr;

        while(curr != nullptr){
            for(new_curr = head, new_prev = head; new_curr != nullptr;){
                if(curr->val > new_curr->val){
                    new_prev = new_curr;
                    new_curr = new_curr->next;
                } else { //curr need to insert before new_curr;
                    //first update orig list
                    prev->next = curr->next;
                    curr->next = nullptr; // take only curr out of orig list
                    if(new_prev != new_curr){ //curr > new list head, cause previous condition at least is true for 1x time
                        new_prev->next = curr;
                        curr->next = new_curr;
                    } else { //curr < new list head
                        curr->next = new_curr;
                        head = curr;
                    }
                    
                    break;
                }
            }

            if(new_curr == nullptr){ //curr->value is larger than the last node in new list, now new_prev is last node in new_list
                prev->next = curr->next;
                curr->next = nullptr; // take only curr out of orig list
                new_prev->next = curr;
            }

            curr = prev->next;
        }

        //note prev is the last element not inserted into new list
        for(new_curr = head, new_prev = head; new_curr != nullptr;){
            if(prev->val > new_curr->val){
                new_prev = new_curr;
                new_curr = new_curr->next;
            } else { //insesrt prev
                if(new_prev == new_curr){
                    prev->next = new_prev;
                    head = prev;
                    break;
                }
                prev->next = new_curr;
                new_prev->next = prev;
                break;
            }
        }

        if(new_curr == nullptr){ //remaining prev is larger than all nodes in new list
            new_prev->next = prev;
        }


        return head;
    }

};

int main()
{
    ListNode n0(1), n1(1), n2(3), n3(1);
    n0.next = &n1;
    // n1.next = &n2;
    // n2.next = &n3;

    Solution S1;
    ListNode* sorted_list = S1.insertionSortList(&n0);
    std::cout << "finish" << std::endl;
}

