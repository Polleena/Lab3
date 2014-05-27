#include <iostream>
#include <windows.h>
using namespace std;
 
/// \file Stek.cpp

///Struktura steka
struct Node
{
    int number;
    Node* last;
};

 /// \fn Osnovnaya functiya

void main()
{
    Node* ptrLast = NULL; 
    Node* top = NULL;
    short action = -1;
  setlocale(LC_ALL,"rus");  /// Delaem vozmojnim vvod po russki
    while (1)   
    {
        cout<<"1. Çàòîëêíóòü Â Ñòåê\n";      /// Menu
        cout<<"2. Âûòîëêíóòü Èç Ñòåêà\n";
        cout<<"3. Âåðøèíà Ñòåêà\n";
        cout<<"4. Ñîäåðæèìîå Ñòåêà\n";
        cout<<"0. Âûõîä\n\n";
        cout<<"Âàø Âûáîð: ";
        cin>>action;        
 
        if (action == 0)  ///Vixod iz programm
        {
            system("CLS");
            break;
        }
 
        if (action == 1) ///Dobavlaem chislo v stek
        {
            system("CLS");
            int numb = -1;          
            cout<<"Ââåäèòå ×èñëî: ";
            cin>>numb;
            Node* ptr = new Node;
            ptr->number = numb;         
            if (top == NULL)
            {
                ptr->last = NULL;
                top = ptr;
                ptrLast = ptr;
                system("CLS");
                continue;
            }
            top = ptr;
            ptr->last = ptrLast;
            ptrLast = ptr;
            system("CLS");
            continue;
        }
 
        if (action == 2)  ///Udalaem iz steka
        {
            system("CLS");
            Node* ptrDelete = NULL;
            if (top == NULL)
            {
                cout<<"\t!!! ÑÒÅÊ ÏÓÑÒ !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }           
            ptrDelete = top;
            if (ptrDelete->last == NULL)
            {
                top = NULL;
                delete ptrDelete;
                system("CLS");
                continue;
            }
            top = ptrDelete->last;
            ptrLast = top;
            delete ptrDelete;
            continue;
        }
 
        if (action == 3)  /// Vershina steka
        {
            system("CLS");
            if (top == NULL)
            {
                cout<<"\t!!! ÑÒÅÊ ÏÓÑÒ !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"Âåðøèíà Ñòåêà: ";
            cout<<top->number<<"\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
 
        if (action == 4) /// Smotrim stek
        {
            system("CLS");
            Node* ptr = NULL;
            if (top == NULL)
            {
                cout<<"\t!!! ÑÒÅÊ ÏÓÑÒ !!!\n\n";
                system("PAUSE");
                system("CLS");
                continue;
            }
            cout<<"* * * * * ÑÎÄÅÐÆÈÌÎÅ ÑÒÅÊÀ * * * * *\n\n";
            ptr = top;
            while (1)
            {
                cout<<ptr->number<<endl;
                if (ptr->last == NULL)
                {
                    system("PAUSE");
                    system("CLS");
                    break;
                }
                ptr = ptr->last;
            }
        }
 
        if (action > 4)   /// if vibrali punct ne iz menu
        { 
            system("CLS");
            cout<<"\t!!! ÍÅÂÅÐÍÛÉ ÂÛÁÎÐ. ÏÎÂÒÎÐÈÒÅ ÂÂÎÄ !!!\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
 
    }
}
 
