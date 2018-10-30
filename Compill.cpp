//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Compill.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

class Node                              // îïðåäåíèå óçëà
   {     public:
          int value                     ;//çíà÷åíèå óçëà
         Node *next                     ;//àäðåñ ñëåä.óçëà

        Node(int valueNode)
        {  value = valueNode            ;
           next = NULL                  ;  }
   };

class LinkedList                        //çàäà¸ò ñâÿçàííûé ñïèñîê óçëîâ
{       public:
          Node *head                    ;//óêàçàòåëü íà óçåë-ãîëîâó ñïèñêà
          Node *tail                    ;//ýòî óêàçàòåëü íà çàâåðøàþùèé óçåë

        LinkedList()
        {  head = NULL                  ;
           tail = NULL                  ; }

    //------------------------------ ÄÎÁÀÂÈÒÜ ÝËÅÌÅÍÒ Â ÊÎÍÅÖ
    void add_in_tail(Node *item)
    {    if (head == NULL) head = item  ;// çàïèñü àäðåñà ïåðâîãî ýëåìåíòà â ñïèñêå
         else tail->next = item         ;// tail õðàíèò àäðåñ ïðåäûäóùåãî ÷ëåíà ñïèñêà,
                                         // ìåíÿåì åãî íà ññûëêó ê ïðèáàâëÿåìîìó óçëó
         tail = item                    ;// çàïèñü àäðåñà ïîñëåäíåãî ýëåìåíòà â ëèñò
    }
    //------------------------------ ÏÅ×ÀÒÜ ÑÏÈÑÊÀ
    void print()
    {
        Node *node = head                                        ;
        AnsiString tmp = ""                                      ;//îáíóëÿåì ñîäåðæèìîå
        Form1->Memo->Lines->Strings[0] = tmp                     ;
        int nextA                                                ;
        int nodeA                                                ;
        while (node != NULL)
        {
          nextA = (int)node->next                                ;
          nodeA = (int)node                                      ;
          Form1->Memo->Lines->Strings[0] = tmp + node->value+ " ";
          tmp = Form1->Memo->Lines->Strings[0]                   ;
          node = node->next                                      ;
        }
    }
    //----------------------------- ÓÄÀËÅÍÈÅ ÈÇ ÑÏÈÑÊÀ ÏÎ ÇÍÀ×ÅÍÈÞ
    void del_val(int val)
     {   Node *node = head                                      ;
         Node *prevnode = head                                  ;
        while (node != NULL)
        {   if (node->value == val)
            {   prevnode->next = node->next;
                if (node == head) head = node->next             ;
                if (node == tail) tail = prevnode               ;
              //  delete node                                   ;
                return                                          ;
            }
            prevnode = node                                     ;
            node = node->next                                   ;
        }
     }
     //---------------------------- ÓÄÀËÅÍÈÅ ÈÇ ÑÏÈÑÊÀ ÏÎ ÇÍÀ×ÅÍÈÞ
    void del_val_all(int val)
    {   Node *node = head                                       ;
        Node *prevnode = head                                   ;
        while (node != NULL)
        {   if (node->value == val)
            {   prevnode->next = node->next                     ;
                if (node == head) head = node->next             ;
                if (node == tail) tail = prevnode               ;
                //delete node;
            }
            if (node->value != val)
                prevnode = node                                 ;
            node = node->next                                   ;
        }
     }
    //---------------------------- îñâîáîæäåíèå ïàìÿòè è ñáðîñ ñïèñêà
    void empty()
    {  Node *node = head                                        ;
       Node *prevnode = head                                    ;
       while (node != NULL)
       {   node = node->next                                    ;
           delete prevnode                                      ;
       }
         delete node                                            ;
         head = NULL                                            ;
         tail = NULL                                            ;
     }
    //----------------------------- Ìàññèâ ññûëîê íàéäåííîãî çíà÷åíèÿ
    LinkedList* ArrayVal(int val)
    {   LinkedList *list = new LinkedList                       ;
        Node *node = head                                       ;
        while (node != NULL)
        {   if (node->value == val)
            {  Node *p = new Node(node->value)                  ;
               list->add_in_tail(p)                             ;
            }
            node = node->next                                   ;
        }
        return(list);
    }
    //---------------------------- ÄËÈÍÀ ÑÏÈÑÊÀ
    int GetLength()
    {  Node *node = head                                        ;
        int length = 0                                          ;
        while (node != NULL)
        {   length++                                            ;
            node = node->next                                   ;
        }
        Form1->Memo->Text  = length                             ;
        return(length)                                          ;
    }
    //---------------------------- ÂÑÒÀÂÊÀ ÓÇËÀ ÏÎÑËÅ ÓÇËÀ Ñ ÎÏÐÅÄÅËÅÍÍÛÌ ÇÍÀ×ÅÍÈÅÌ
    void SetNode(int key_val, int seted_node_val)
    {  Node *node = head                                        ;
        while (node != NULL) 
        {   if (node->value == key_val)
            {   Node *p = new Node(seted_node_val)              ;
                p->next =  node->next                           ;
                node->next = p                                  ;
                if (node == tail) tail = p                      ;
            }
            node = node->next                                   ;
        }
    }
    //---------------------------- ÑÓÌÌÀÒÎÐ ËÈÑÒÎÂ
    LinkedList* SummLists(LinkedList* first, LinkedList* second)
    {   LinkedList* NewList = new LinkedList                    ;
        int length1 = first->GetLength()                        ;
        int length2 = second->GetLength()                       ;
        int summ                                                ;
        if (length1 == length2)
        {  Node *node1 = first->head                            ;
           Node *node2 = second->head                           ;
           while (node1 != NULL)
           {  summ = node1->value +  node2->value               ;
              NewList->add_in_tail(new Node(summ))              ;
              node1 = node1->next                               ;
              node2 = node2->next                               ;
           }
           NewList->print()                                     ;
           return(NewList)                                      ;
        }
        else Form1->Memo->Text  = "Íåðàâíàÿ äëèíà ñïèñêîâ"      ;
        return(NewList)                                         ;
    }

    //----------------------------- Ìàññèâ äàííûõ ñïèñêà(äëÿ òåñòà)
    int** Array(LinkedList* list)
    {   int i = 0                                               ;
        int Arraylength = list->GetLength()                     ;//ðàñ÷åò ñòðîê ìàññèâà
        int *p_darr = new int[Arraylength]                      ;
        int **DataArray                                         ;
        DataArray = new int*[Arraylength]                       ;

        for ( int j = 0; j < Arraylength; j++)
                DataArray[j] = new int[3]                       ;

        Node *node = list->head                                 ;
        while (node != NULL)
        {   DataArray[i][0] =  node->value                      ;//âåëè÷èíà
            DataArray[i][1] = (int) node                        ;//àäðåñ ýëåìåíòà
            DataArray[i][2] = (int) node->next                  ;//àäðåñ ñëåä.ýëåì.
            i++;
            node = node->next                                   ;
        }
        return(DataArray)                                       ;
    }
    //---------------------------- Ñðàâíåíèå ìàññèâîâ(äëÿ òåñòà)
    int compare_arrays(int** mass1, int** mass2)                      
    {   int exit                                                      ;
        for (int i = 0; i<100; i++)
        {   if (mass1[i][0] != mass2[i][0])                return(1)  ;//âåëè÷èíà
            if (mass1[i][2] == 0 && mass2[i][2] == 0)      return(0)  ;//àäðåñ
            else if (mass1[i][2] == 0 || mass2[i][2] == 0) return(1)  ;
        }
        return(1)                                                      ;
    }
    //----------------------------- ÑÎÇÄÀÒÜ ËÈÑÒ (ïåðåãðóç ôóíêöèè)(äëÿ òåñòà)
    void CreateList(int a1)
    {   empty();
        add_in_tail(new Node(a1))                               ;

    }
    void CreateList(int a1, int a2)
    {   empty();
        add_in_tail(new Node(a1))                               ;
        add_in_tail(new Node(a2))                               ;

    }
    void CreateList(int a1, int a2, int a3)
    {   empty();
        add_in_tail(new Node(a1))                               ;
        add_in_tail(new Node(a2))                               ;
        add_in_tail(new Node(a3))                               ;

    }
    void CreateList(int a1, int a2, int a3,int a4)
    {   empty();
        add_in_tail(new Node(a1))                               ;
        add_in_tail(new Node(a2))                               ;
        add_in_tail(new Node(a3))                               ;
        add_in_tail(new Node(a4))                               ;
    }
    //------------------------ Test --------------------------------
    void Test ()
    {   int i = 0                                               ;
        LinkedList* test_list1 = new LinkedList                 ;
        LinkedList* test_list2 = new LinkedList                 ;
        int** Array1                                            ;
        int** Array2                                            ;

        // del_val(int val)--------------------------------------
        test_list1 -> CreateList(1, 2, 3)                       ;//ëèñò ïåðåä ïðèìåíåíèåì ôóíêöèè
        test_list2 -> CreateList(2, 3)                          ;//êàêèì äîëæåí áûòü ðåçóëüòàò ïîñëå
        i += TestSolve (test_list1, test_list2, 0, 1)           ;//ëèñò1,ëèñò2,ôóíêöèÿ,val ôóíêöèè

        test_list1 -> CreateList(1, 2, 3)                       ;
        test_list2 -> CreateList(1, 3)                          ;
        i += TestSolve (test_list1, test_list2, 0, 2)           ;

        test_list1 -> CreateList(1, 2, 3)                       ;
        test_list2 -> CreateList(1, 2)                          ;
        i += TestSolve (test_list1, test_list2, 0, 3)           ;

        // del_val_all(int val)----------------------------------
        test_list1 -> CreateList(1, 1, 3)                       ;
        test_list2 -> CreateList(3)                             ;
        i += TestSolve (test_list1, test_list2, 1, 1)           ;

        test_list1 -> CreateList(1, 3, 3)                       ;
        test_list2 -> CreateList(1)                             ;
        i += TestSolve (test_list1, test_list2, 1, 3)           ;

        test_list1 -> CreateList(2, 1, 2, 1)                    ;
        test_list2 -> CreateList(1, 1)                          ;
        i += TestSolve (test_list1, test_list2, 1, 2)           ;

        // empty-------------------------------------------------
        test_list1 -> CreateList(1, 2, 3, 4)                    ;
        test_list1->empty()                                     ;
        if (test_list1->head != 0 ||
            test_list1->tail != 0)
            i++                                                 ;

        // LinkedList* ArrayVal(int val)-------------------------
        test_list1 -> CreateList(2, 1, 3, 1)                    ;
        test_list1 = test_list1->ArrayVal(1)                    ;
        test_list2 -> CreateList(1, 1)                          ;
        i += TestSolve (test_list1, test_list2, 0, 9)           ;

        test_list1 -> CreateList(4, 2, 3, 4)                    ;
        test_list1 = test_list1->ArrayVal(4)                    ;
        test_list2 -> CreateList(4, 4)                          ;
        i += TestSolve (test_list1, test_list2, 0, 9)           ;

        test_list1 -> CreateList(4, 2, 3, 4)                    ;
        test_list1 = test_list1->ArrayVal(4)                    ;
        test_list2 -> CreateList(4, 4)                          ;
        i += TestSolve (test_list1, test_list2, 0, 9)           ;

        //  int GetLength()--------------------------------------
        test_list1 -> CreateList(4, 2, 3, 4)                    ;
        test_list2 -> CreateList(1)                             ;
        test_list2 -> empty()                                   ;
        if (test_list1->GetLength() != 4 ||
            test_list2->GetLength() != 0)
            i++                                                 ;

        // void SetNode(int key_val, int seted_node_val)---------
        test_list1 -> CreateList(4, 2)                          ;
        test_list1->SetNode(2,5)          ;
        test_list2 -> CreateList(4, 2, 5)                       ;
        i += TestSolve (test_list1, test_list2, 0, 9)           ;
        test_list1->SetNode(4,2)                                ;
        test_list2 -> CreateList(4, 2, 2, 5)                    ;
        i += TestSolve (test_list1, test_list2, 0, 9)           ;



        //  LinkedList* SummLists(LinkedList* first, LinkedList* second)
        test_list1 -> CreateList(4, 2, 5, 1)                          ;
        test_list2 -> CreateList(4, 6, 3, 7)                          ;
        test_list1 = SummLists(test_list1 , test_list2)               ;
        test_list2 -> CreateList(8, 8, 8, 8)                          ;
        i += TestSolve (test_list1, test_list2, 0, 9)                 ;

        test_list1 -> CreateList(4, 2, 5, 1)                          ;
        test_list2 -> CreateList(4, 6)                                ;
        SummLists(test_list1 , test_list2)                            ;
        if (Form1->Memo->Text  != "Íåðàâíàÿ äëèíà ñïèñêîâ") i++       ;

        if (i !=0 ) Form1->Memo->Text  = "Òåñò íå ïðîéäåí"            ;
        else        Form1->Memo->Text  = "Òåñò çàâåðøåí óñïåøíî"      ;

        delete test_list1;
        delete test_list2;
    }

   //------------ ÒÅÑÒ (ñðàâíåíèå ðåçóëüòàòà è îòâåòà) ----------
   int TestSolve (LinkedList* test_list1, LinkedList* test_list2,int fNumFunc, int val)
    {
        int i = 0                                       ;
        int** Array1                                    ;
        int** Array2                                    ;
        typedef void(LinkedList:: *TestFunc)(int)       ;
        enum ListFunc
                { fdel_val                              ,  //0
                  fdel_val_all                          ,  //1
                  fLastFunc    }                        ;

        TestFunc ListTableFunc [ fLastFunc ]=
                { &LinkedList::del_val                  ,  //0
                  &LinkedList::del_val_all  }           ;  //1

        (test_list1->*ListTableFunc[fNumFunc])(val)     ;//ïðîâåðÿåìàÿ ôóíêöèÿ
        Array1 = Array(test_list1)                      ;//îïðåäåëåíèå ïåðâîãî ìàññèâà
        Array2 = Array(test_list2)                      ;//âòîðîé ìàññèâ
        i = compare_arrays(Array1,Array2)               ;//ñðàâíåíèå è ðåçóëüòàò
        return(i)                                       ;
    }

    //------------------------------------------------------------


};
LinkedList* arrayList = new LinkedList;
LinkedList* list      = new LinkedList;
LinkedList* summList  = new LinkedList;


//===========================================================================
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner) {}
//===========================================================================

void __fastcall TForm1::BtnRunClick(TObject *Sender)
{        //-- creation of standart list --   
        test_list1 -> CreateList(16, 32, 128, 256);
        Form1->Memo->Text  = "List created";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnPrintClick(TObject *Sender)
{
        list->print();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnDelClick(TObject *Sender)
{
        list->del_val_all(55);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnArrayClick(TObject *Sender)
{
        arrayList = list->ArrayVal(55);
        arrayList->print();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnLengthClick(TObject *Sender)
{
        list->GetLength();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnSetClick(TObject *Sender)
{
        list->SetNode(12, 55);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnSumClick(TObject *Sender)
{
       summList = list->SummLists(list, arrayList);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnTestClick(TObject *Sender)
{
        list->Test ();
}
//---------------------------------------------------------------------------



