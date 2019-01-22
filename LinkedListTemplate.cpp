#include <stdio.h>

class Node
{
  public:
    int value;
    Node* next;

    Node(int valueNode){
        value = valueNode;
        next = NULL;
    }
};

class LinkedList
{  
  public:
    Node* head;
    Node* tail;

    LinkedList()
    {  
        head = NULL;
        tail = NULL;
    }

    void add_in_tail(Node* item)
    {
        if (head == NULL) head = item;
        else tail->next = item;
        tail = item;
        tail->next = NULL;
    }

    Node* find(int val)
    {   
        Node *node = head;
        while (node != NULL) {
            if (node->value == val) return node;
            node = node->next;
        }
        return NULL;
    }

    bool remove(int val)
    {
          Node *node = head;
          Node *prevnode = head;
          while (node != NULL)
          {
               if (node->value == val)
               {    prevnode->next = node->next;
                    if (node == head && node == tail)
                    {
                         head = NULL;
                         tail = NULL;
                         return true;
                    }
                    if (node == head)
                         head = node->next;
                    if (node == tail)
                         tail = prevnode;
                    return true;
               }
               prevnode = node;
               node = node->next;
          }
          return false;
    }

    void remove_all(int val)
    {
        Node *node = head;
        Node *prevnode = head;
        while (node != NULL)
        {   if (node->value == val)
            {   prevnode->next = node->next;
                if (node == head) head = node->next;
                if (node == tail) tail = prevnode;
            }
            if (node->value != val)
                prevnode = node;
            node = node->next;
        }
    }

    void clear()
    {
       Node *node = head;
       Node *prevnode = head ;
       while (node != NULL)
       {   node = node->next;
           delete prevnode;
       }
         delete node;
         head = NULL;
         tail = NULL;
    }

    int size()
    {
        Node *node = head;
        int length = 0;
        while (node != NULL)
        {
            length++;
            node = node->next;
        }
        return length;
    }

    void insert_after(Node* nodeAfter, Node* nodeToInsert)
    {
       if (nodeAfter == NULL && head == NULL)
       {
          add_in_tail(nodeToInsert);
          return;
       }
       nodeToInsert->next = nodeAfter->next;
       nodeAfter->next = nodeToInsert;
       if (nodeAfter == tail)
          tail = nodeToInsert;
    }
};
