# leetcode 链表刷题笔记

## 经验总结

``` 
1.使用快慢指针来快速找到链表中点；
```

## 21.合并两个排序过的链表

``` c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* newList = malloc(sizeof(struct ListNode));
    newList->next = NULL;
    struct ListNode* rootNode = NULL;
    if (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            newList->val = l1->val;
            l1 = l1->next;
        }
        else {
            newList->val = l2->val;
            l2 = l2->next;
        }
        rootNode = newList;
    }
    else if (l1 == NULL) {
        return l2;
    }
    else {
        return l1;
    }
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            newList->next = l1;
            newList = newList->next;
            l1 = l1->next;
        }
        else {
            newList->next = l2;
            newList = newList->next;
            l2 = l2->next;
        }
    }
    if (l1 == NULL) {
        newList->next = l2;
        newList = newList->next;
    }
    else {
        newList->next = l1;
        newList = newList->next;
    }
    return rootNode;
}

```



## 141 环形链表 (easy)

~~~ c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;
    struct ListNode* fast = head->next;
    struct ListNode* slow = head;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
~~~



### 160 相交链表 (easy)

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if ((headA == NULL) || (headB == NULL))  //test NULL list
        return NULL;
    struct ListNode *testA, *testB; //设置两个指针用来测量两链表深度（防止丢失首指针）
    testA = headA;
    testB = headB;
    int dpthA , dpthB; // 记录两链表深度
    dpthA = dpthB = 0;
    while (testA->next != NULL) {   //计算链表A深度
        testA = testA->next;
        ++dpthA;
    }
    while(testB->next != NULL) {    //计算链表A深度
        testB = testB->next;
        ++dpthB;
    }
    int dist = dpthA - dpthB;  //计算两者深度之差
    testA = headA;  //设置两个指针回到表头
    testB = headB;
    if (dist > 0) {
        while (dist != 0) {
            testA = testA->next;
            --dist;
        }
    }
    else {
        while (dist != 0) {
            testB = testB->next;
            ++dist;
        }
    }
    while (testA != NULL) {
        if (testA == testB)
            return testA;
        else {
            testA = testA->next;
            testB = testB->next;
        }
        
    }
    return NULL;
        
}
```



### 203 移除链表元素 (easy)

~~~ 

删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
~~~

``` c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *p = head, *q = NULL;
    while (p != NULL) {
        if (p->val != val) {
            q = p;
            p = p->next;
            
        }
        else {
            if (q != NULL ) {
                q->next = p->next;  
                free(p);
                p = q->next;
            }
            else {
                if (p->next != NULL) {
                    q = p;
                    free(p);
                    p = q->next;
                    head = p;
                    q = NULL;
                }
                else {
                    free(p);
                    return NULL;
                }
            }
        }
    }
    return head;
}
```

#### 解题思路

1. 用while循环遍历链表直至为空，用一个指针保存上一节点节点信息；
2. if语句检测是否有删除的元素；
3. 如果有，检测是否有前项元素。如果有，前项节点指向后项节点的下一个，free掉当前节点，最后将p设为前项节点的下一个；如果没有前项元素，则该节点为第一个，此时检测下一个节点是否存在，若不存在，直接释放该节点，返回NULL；若存在下一元素，free当前元素，将下一元素置为当前元素，继续。

### 206 反转链表 (easy)

``` c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *l = NULL , *p = NULL;
    while (head) {
        l = p; //记录上一节点
        p = head;//记录反转过程当前节点
        head = head->next;//向后选取反转节点
        p->next = l;//当前节点next为上一节点
    }
    //直到末尾时，返回当前头节点
    return p;
}
```





### 234 回文链表 (easy)

~~~ CC
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 使用快慢指针找到链表中点
//反转链表函数
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *l = NULL , *p = NULL;
    while (head) {
        l = p;
        p = head;
        head = head->next;
        p->next = l;
    }
    return p;
}
bool isPalindrome(struct ListNode* head) {
    if (head == NULL)
        return 1;
    struct ListNode *f, *s;
    f = s = head;
    while (f != NULL && f->next != NULL) {
        f = f->next->next;
        s = s->next;
    }
    if (f != NULL) //若链表长度为偶数，则f应处于NULL上，此时s处于后半段开头；
        s = s->next;//若链表长度为基数，则f处于NULL前一节点，此时s处于奇数个节点数链表的正中间
                    //，此时应向后移动一个节点
    struct ListNode* newLastHalf = reverseList(s);//获取反转后后半段链表表头
    struct ListNode *LastHalf, *FirstHalf;
    FirstHalf = head;
    LastHalf = newLastHalf;
    //直到出现不相同或到达末尾
    while (LastHalf != NULL) {
        if (LastHalf->val != FirstHalf->val )
            return 0;
        LastHalf = LastHalf->next;
        FirstHalf = FirstHalf->next;
    }
    //通过测试，返回true
    return 1;
    
}

~~~

### 237 删除链表中的节点 (easy)

~~~c 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node != NULL) {
        if (node->next != NULL) {
            struct ListNode* p = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            free(p);
        }
        else
            free(node);
    }
    return;
}
~~~

### 707 设计链表 (easy)

``` c
typedef struct LinkedList{
    int val;
    struct LinkedList *next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    //若分配失败则返回NULL
    MyLinkedList* newone = malloc(sizeof(struct LinkedList));
    if (newone == NULL)
        return NULL;
    newone->next = NULL;
    return newone;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index > 1000) // 测试index合法性
        return -1;
    int cnt = -1;
    while(obj != NULL && cnt != index) {
        obj = obj->next;
        ++cnt;
    }
    if (obj != NULL) //保证找到对应节点再进行访问
        return obj->val;
    else
        return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* newnode = malloc(sizeof(struct LinkedList));
    newnode->next = obj->next;
    newnode->val = val;
    obj->next = newnode;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* newnode = malloc(sizeof(struct LinkedList));
    newnode->next = NULL;
    newnode->val = val;
    
    while(obj->next != NULL)
        obj = obj->next;
    obj->next = newnode;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > 1000) // 测试index合法性
        return -1;
    int cnt = 0;
    //找到index前一个节点  index=1 val=2
    while(obj != NULL && cnt != index) {
        obj = obj->next;
        ++cnt;
    }
    //新建节点 初始化val
    MyLinkedList* newnode = malloc(sizeof(struct LinkedList));
    newnode->val = val;
    if (obj != NULL && obj->next != NULL) {//找到index上一节
        newnode->next = obj->next;
        obj->next = newnode;
    }
    else if (obj != NULL){
        newnode->next = NULL;
        obj->next = newnode;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 1 || index > 1000) // 测试index合法性
        return -1;
    int cnt = 0;//找到index前一节点
    while(obj != NULL && cnt != index) {
        obj = obj->next;
        ++cnt;
    }
    //保证找到对应节点再进行访问
    if (obj != NULL && obj->next != NULL) {
        MyLinkedList* save = obj->next;
        obj->next = obj->next->next;
        free(save);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* save;
    while(obj != NULL) {
        save = obj;
        obj = obj->next;
        free(save);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
```

