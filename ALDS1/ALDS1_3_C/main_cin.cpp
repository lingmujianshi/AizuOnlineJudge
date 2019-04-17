//ALDS1_3_C Elementary data structures - Doubly Linked List
#include <cstdio>
#include <cstring>
#include <iostream>
class DoublyLinkedList
{
    struct Node
    {
        int key;
        Node *prev, *next;
    };

    Node *nil;

public:
    DoublyLinkedList()
    {
        init();
    }

    ~DoublyLinkedList()
    {
        delete nil;
    }

    void init()
    {
        nil = new Node();
        nil->next = nil;
        nil->prev = nil;
    }

    void insert(int key)
    {
        Node *x = new Node();
        x->key = key;
        // 番兵の直後に要素を追加
        x->next = nil->next;
        nil->next->prev = x;
        nil->next = x;
        x->prev = nil;
    }

    void deleteNode(Node *t)
    {
        if (t == nil)
            return; // tが番兵の場合は処理しない
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
    }

    Node *listSearch(int key)
    {
        Node *cur = nil->next; // 番兵のつぎの要素から辿る
        while (cur != nil && cur->key != key)
        {
            cur = cur->next;
        }
        return cur;
    }

    void deleteFirst()
    {
        deleteNode(nil->next);
    }

    void deleteLast()
    {
        deleteNode(nil->prev);
    }

    void deleteKey(int key)
    {
        // 検索したノードを削除
        deleteNode(listSearch(key));
    }

    void printList()
    {
        Node *cur = nil->next;
        int isf = 0;
        while (1)
        {
            if (cur == nil)
                break;
            if (isf++ > 0)
                printf(" ");
            printf("%d", cur->key);
            cur = cur->next;
        }
        printf("\n");
    }
};


int main()
{
    int key, n, i;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;
    DoublyLinkedList dll;
    //scanf("%d", &n);
    std::cin >> n;
    for (i = 0; i < n; i++)
    {
        //scanf("%s%d", com, &key);
        std::cin >> com >> key;
        if (com[0] == 'i')
        {
            dll.insert(key);
            np++;
            size++;
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                    dll.deleteFirst();
                else if (com[6] == 'L')
                    dll.deleteLast();
            }
            else
            {
                dll.deleteKey(key);
                nd++;
            }
            size--;
        }
    }
    dll.printList();
    return 0;
}