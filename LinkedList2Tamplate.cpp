#include <stdio.h>

class Node
{  
  public:
    int value;
    Node* next;
    Node* prev;

    Node(int valueNode) {
        value = valueNode;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList2
{  
  public:
    Node* head;
    Node* tail;

    LinkedList2()
    {  
        head = NULL;
        tail = NULL;
    }

    void add_in_tail(Node* item)
    {
       if (head == NULL) {
          head = item;
          head->next = NULL;
          head->prev = NULL;
       } else {
          tail->next = item;
          item->prev = tail;
       }
       tail = item;
    }
    
    Node* find(int val)
    {   
        Node* node = head;
        while (node != NULL)
        {   if (node->value == val)
                return (node);
            node = node->next;
        }
        return NULL;
    }

    bool remove(int val)
    {
         Node *node = head  ;
         while (node != NULL)
         {   if (node->value == val)
             {
                if (node == head && node == tail)
                {   head = NULL;
                    tail = NULL;
                    return true;
                }
                if (node == head)
                {   head = node->next ;
                    head->prev = node->prev ;
                    return true;
                }
                if (node == tail)
                {   tail = tail->prev;
                    tail -> next = NULL;
                    return true;
                }
                else
                {   node->prev->next = node->next;
                    node->next->prev = node->prev;
                    return true;
                }
             }
             node = node->next ;
         }
         return false;
    }

    void remove_all(int val)
    {
         Node *node = head  ;
         while (node != NULL)
         {   if (node->value == val)
             {
                if (node == head && node == tail)
                {   head = NULL;
                    tail = NULL;
                }
                else if (node == head)
                {   head = node->next ;
                    head->prev = node->prev ;
                }
                    else if (node == tail)
                    {   tail = node->prev ;
                        node->prev->next = node->next ;
                    }
                         else
                         {   node->prev->next = node->next;
                             node->next->prev = node->prev;
                         }
             }
             node = node->next;
         }
    }

    void clear()
    {
       Node *node = head;
       Node *prevnode = head;
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
        {   length++ ;
            node = node->next;
        }
        return length;
    }

    void insert_after(Node* nodeAfter, Node* nodeToInsert)
    {
          if (nodeAfter == NULL)
          {
               if (head == NULL)
               {
                    add_in_tail(nodeToInsert);
                    return;
               }
               else
               {
                    head->prev = nodeToInsert;
                    nodeToInsert->next = head;
                    head = nodeToInsert;
                    return;
               }
          }
          nodeToInsert->next = nodeAfter -> next ;
          nodeToInsert->prev = nodeAfter ;
          nodeAfter->next = nodeToInsert ;

          if (nodeAfter == tail)
          {   tail = nodeToInsert ;                                                  ;
          }
          else nodeToInsert->next->prev = nodeToInsert ;
    }

};
