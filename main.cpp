#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;


struct slistEl
{
    slistEl* next;
    int data;
};

// Definicja typu obiektowego slist
//---------------------------------
class slist
{
public:
    slistEl* head;

    slist();  // konstruktor
    ~slist(); // destruktor
    unsigned size();
    void printl();
    void push_front(int v);
    void push_back(int v);
    void insert_before(slistEl* e, int v);
    void insert_after(slistEl* e, int v);
    void pop_front();
    void pop_back();
    void remove(slistEl* e);
};

// Konstruktor listy
//------------------
slist::slist()
{
    head = NULL;
}

// Destruktor listy
//-----------------
slist::~slist()
{
    while (head) pop_front();
}

// Funkcja oblicza liczbê elementów listy
//---------------------------------------
unsigned slist::size()
{
    unsigned c = 0;
    slistEl* p = head;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

// Procedura wyœwietla zawartoœæ elementów listy
//----------------------------------------------
void slist::printl()
{
    unsigned i;
    slistEl* p = head;

    //cout << "Number of elements : " << size() << endl;
    for (i = 1; p; p = p->next) cout << "Element #" << i++ << "  data = " << p->data << endl;
    cout << endl;
}

// Procedura do³¹czania na pocz¹tek listy
//---------------------------------------
void slist::push_front(int v)
{
    slistEl* p;

    p = new slistEl;
    p->next = head;
    p->data = v;
    head = p;
}

// Procedura do³¹czania na koniec listy
//---------------------------------------
void slist::push_back(int v)
{
    slistEl* p, * e;

    e = new slistEl;  // tworzymy nowy element
    e->next = NULL;   // inicjujemy element
    e->data = v;
    p = head;
    if (p)
    {
        while (p->next) p = p->next;
        p->next = e;
    }
    else head = e;
}

// Procedura do³¹czania przed elementem e
//---------------------------------------
void slist::insert_before(slistEl* e, int v)
{
    slistEl* p = head;

    if (p == e) push_front(v);
    else
    {
        while (p->next != e) p = p->next;
        p->next = new slistEl;
        p->next->next = e;
        p->next->data = v;
    }
}

// Procedura do³¹czania za elementem e
//------------------------------------
void slist::insert_after(slistEl* e, int v)
{
    slistEl* p = new slistEl;

    p->next = e->next;
    p->data = v;
    e->next = p;
}

// Procedura usuwa pierwszy element
//---------------------------------
void slist::pop_front()
{
    slistEl* p = head; // zapamiêtujemy pocz¹tek

    if (p)
    {
        head = p->next;   // nowy pocz¹tek
        delete p;         // usuñ element z pamiêci
    }
}

// Procedura usuwa ostatni element
//---------------------------------
void slist::pop_back()
{
    slistEl* p = head; // zapamiêtujemy pocz¹tek

    if (p)
    {
        if (p->next)
        {
            while (p->next->next) p = p->next;
            delete p->next;
            p->next = NULL;
        }
        else
        {
            delete p;
            head = NULL;
        }
    }
}

// Procedura usuwa wybrany element
//--------------------------------
void slist::remove(slistEl* e)
{
    slistEl* p;

    if (head == e) pop_front();
    else
    {
        p = head;
        while (p->next != e) p = p->next;
        p->next = e->next;
        delete e;
    }
}


int main( )
{
     int wybor, w;
     // inicjalizacja z 1 elementem na start
     slistEl* e; // do wskazywania elementów listy
     slist L = slist();
     L.push_front(21);
     L.push_front(20);
     L.push_front(19);
     L.push_front(18);


    do
    {
        L.printl();

      cout<<"1.  Dodanie liczby na poczatek "<<endl;
      cout<<"2.  Dodanie liczby na koniec "<<endl;
      cout<<"3.  Zlicz elementy listy "<<endl;
      cout<<"4.  Usuniecie liczby z poczatku "<<endl;
      cout<<"5.  Usuniecie liczby z konca "<<endl;
      cout<<"6.  Dodaj za elementem " << endl;
      cout<<"7.  Dodaj przed elementem " << endl;
      cout<<"8.  Usun wybrany element " << endl;
      cout<<"9.  Wyjscie  "<<endl;
      cin>>w;

    switch(w)
      {
          case 1: // dodanie przod
              { cout<<"Jaka liczbe chcesz dodac: "<<endl;
              cin>>w;
              L.push_front(w);
                break;
              }
          case 2: // dodanie tyl
            {
                cout<<"Jaka liczbe chcesz dodac: "<<endl;
                cin>>w;
                cout << endl;
                L.push_back(w);
                break;
            }
            case 3: // rozmiar
                {
                    cout << endl;
                    cout << "Lista posiada " << L.size() << " elementow" << endl;
                    break;
                }
            case 4: // usuwanie przod
                {
                L.pop_front();
                break;
                }
            case 5:// usuwanie tyl
                {
                L.pop_back();
                break;
                }
            case 6: // dodaj za wybranym
                e = L.head;
                cout << "Jaka liczbe chcesz dodac: " << endl;
                cin >> w;
                cout << endl;
                cout << "Za którym elementem: " << endl;
                cin >> wybor;
                // przesuniêcie e do wybranego miejsca
                for (int i = 0; i < wybor-1; i++)
                {
                    e = e->next;
                }
                L.insert_after(e, w);
                break;
            case 7: // dodaj przed wybranym
                e = L.head;
                cout << "Jaka liczbe chcesz dodac: " << endl;
                cin >> w;
                cout << endl;
                cout << "Przed ktorym elementem: " << endl;
                cin >> wybor;
                // przesuniêcie e do wybranego miejsca
                for (int i = 0; i < wybor - 1; i++)
                {
                    e = e->next;
                }
                L.insert_before(e, w);
                break;
            case 8: // usuñ wybrany
                e = L.head;
                cout << "Ktory element chcesz usunac: " << endl;
                cin >> wybor;
                for (int i = 0; i < wybor - 1; i++)
                {
                    e = e->next;
                }
                L.remove(e);
                break;
            case 9:
                cout << "Koniec programu" << endl;
                break;
            default:
                cout << "Nie ma takiej akcji!" << endl;
                break;

      }

    }
    while(w!=9);

  return 0;
}
