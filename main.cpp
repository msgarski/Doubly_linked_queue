#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

struct Node
{
    int klucz;
    double los;
    char ch;
    Node *next;
    Node *prev;
};
Node *head=nullptr;
int licznik=0;
//********************************************************************************8
void wstawia_elem(int klucz)//gotowe
{
    double los=rand()%1000;
//alokacja pamieci na nowy wezel listy
        Node *nowy= new Node;
        if(!nowy)
        {
            std::cout<<"Nie udalo sie utworzyc nowego wezla listy!\n Brak pamieci!"<<std::endl;
            return;
        }
//inicjalizacja liczbowych zmiennych wezla:
        nowy->klucz=klucz;
        nowy->los=los;
        nowy->ch='T';
//wstawianie wezla do listy:
//***********************************************************************************************
//Gdy lista jest pusta:
//*************************************************************************************************
    Node * ptr=head;        //pomocniczt wskaznik wedrujacy
//**************************************************************************************************8
        if(head==nullptr)
        {
            head=nowy;
            nowy->next=nowy;
            nowy->prev=nowy;
            licznik++;
        }
//***************************************************************************************************
//Wstawianie z szukaniem miejsca do niepustej listy:
        //Gdy wstawiamy przed HEADa:
        else if((nowy->klucz)<(ptr->klucz))
        {
            nowy->next=head;//ok
            nowy->prev=head->prev;
            head->prev=nowy;
            head=nowy;
            head->prev->next=head;  //wazne odnowienie polaczenia z koncem listy
            licznik++;
        }
//****************************************************************************************************
            else
            {//gdy wstawiamy gdzies w srodku, lub na koncu:
        do
        {   //sprawdzamy, czy to nie duplikat:
            if(nowy->klucz==ptr->klucz)
            {
                std::cout<<"Powtorzona kluczowa wartosc! "<<nowy->klucz<<" = "<<ptr->klucz<<std::endl;
                break;
            }
            if(nowy->klucz<ptr->klucz)//wstawienie przed
            {
                nowy->next=ptr;
                nowy->prev=ptr->prev;
                ptr->prev->next=nowy;
                ptr->prev=nowy;
                licznik++;
                break;
            }
            else if(ptr->next==head)//wstawienie za ostatnim elementem listy
            {
                nowy->next=head;
                nowy->prev=ptr;
                head->prev=nowy;
                ptr->next=nowy;
                licznik++;
                break;
            }
                ptr=ptr->next;  //przesuwamy sie o 1 wezel do przodu
        }
        while(ptr!=head);
 //   koniec tworzenia wezla listy
            }
}
//*************************************************************************************************************
//hurtowe wstawianie wezlow do listy
void wstawia_X_elem(int X)//gotowe
{
    //srand(time(0));
    int los;
    //gdy powtorki...
    //gdy brak pamieci...S
bool tabl_losowych[99901]{};            //tablica do spkrawdzania powtarzalnosci
//*********************************************************************************************
//odznaczenie w tablicy juz istniejacych w liscie kluczy
if(head)
{
    Node * ptr=head;
    //przejscie przez liste aby zaktualizowac tablice wystepujacych juz w liscie kluczzy
    do
    {
        if(ptr->klucz>=99&&ptr->klucz<=99999)
            tabl_losowych[ptr->klucz]=true;
        ptr=ptr->next;
    }while(ptr!=head);
    ptr=nullptr; //oslepienie wskaznika
}
//**************************************************************************************************
for(int i=0; i<X; i++)
{
    //losowanie unikalnej liczby i przes³anie jej do wezla listy
    do
        {
            los=(rand()%99901);
        }
        while(tabl_losowych[los]);
        tabl_losowych[los]=true;        //zapamietanie wylosowania danej liczb
        los+=99;
    //wywolanie funkcji wstawiajacej dla wylosowanego klucza
        wstawia_elem(los);
}
}
//*********************************************************************************************************
void prezentacja_poczatek(int liczba_wezlow)
{//funkcja wypisuje n poczatkowych wezlow od czola listy
    Node * ptr=head;
        cout<<"Wyswietlenie "<<liczba_wezlow<<" poczatkowych wezlow listy:"<<endl;
    if(!head)
    {
        cout<<"Blad!! Lista jest pusta. Nie mozna nic wyswietlic."<<endl;
        return;
    }
    else if(licznik<liczba_wezlow)
    {
        cout<<"Nie ma tylu wezlow w liscie"<<endl;
        cout<<"Wyswietlimy tylko "<<licznik<<" wezlow"<<endl;
    }
    //ptr=ptr->prev;
cout<<"zawartosc head: "<<ptr->klucz<<endl;
    for(int i=0; i<liczba_wezlow; i++)
    {
        cout<<"Klucz: "<<ptr->klucz<<"  "<<ptr->los<<"  "<<ptr->ch<<endl;
        ptr=ptr->next;
        if(ptr==head)
            return;
    }
    delete ptr;
}

//**************************************************************************************************888
void prezentacja_koniec(int liczba_wezlow)
{//funkcja wypisuje n koncowych wezlow listy

    cout<<"Wyswietlenie "<<liczba_wezlow<<" wezlow listy:"<<endl;
    if(!head)
    {
        cout<<"Blad!! Listaa jest pusta. Nie mozna nic wyswietlic."<<endl;
        return;
    }
    else if(licznik<liczba_wezlow)
    {
        cout<<"Nie ma tylu wezlow w liscie"<<endl;
        cout<<"Wyswietlimy tylko "<<licznik<<" wezlow"<<endl;
        liczba_wezlow=licznik;
    }
    Node * ptr=head;
    ptr=ptr->prev;
    for(int i=0; i<liczba_wezlow; i++)
    {
        cout<<"Klucz: "<<ptr->klucz<<"  "<<ptr->los<<"  "<<ptr->ch<<endl;
        ptr=ptr->prev;
    }
    delete ptr;
}
//*******************************************************************************************************
void szukaj(int klucz)//gotowe
{
    //funkcja wyszukuje wezel o zadanym kluczu i wypisuje go
    Node * ptr=head;
    if(head)//lizta moze byc pusta...
    {
        //Node * ptr=head;
        do
        {
            if(ptr->klucz==klucz)
                {
                    cout<<"adres wezla "<<ptr<<"   szukany klucz : "<<ptr->klucz<<
                    "   wartosc losowa double: "<<ptr->los<<endl;
                    break;
                }
            ptr=ptr->next;
        }while(ptr!=head);
            if(ptr==head)//(!sukces)
                cout<<"Niestety nie udalo sie odnalexc szukanej wartosci..."<<endl;
    }
    else
        {
            cout<<"Lista nie zawiera zadnych elementow!"<<endl;
        }
        ptr=nullptr;
}
//*********************************************************************************************************
void usuwanie_elementu(int k)//gotowe
{//funkcja usuwa z listy wezel o zadanym kluczu
    if(!head)//gdy lista jest pusta
        {
            cout<<"Lista jest pusta i nie zawiera zadnych elementow do usuniecia!"<<endl;
            return;
        }
    Node * ptr=head;
    //lista moze byc pusta ,,, po usunieciu
    if(head)
    {
        do
        {
            if(ptr->klucz==k)   //znalezienie wezla z szukanym kluczem
            {
                cout<<"wezel o kluczu "<<k<<" znaleziony..."<<endl;

                    if(ptr==head)//gdy X jest headem...
                    {
                        cout<<"byl headem ";
                        if(ptr->next==ptr)//czy X to jedyny element listy?
                        {
                            cout<<"i w dodatku jedynym wezlem "<<endl;

                            head=nullptr;//wiec trzeba wyzerowac heaada...
                            delete ptr;
                            licznik--;
                            cout<<"...juz go nie ma wsrod nas."<<endl;
                            return;
                        }
                        else
                        {
                            cout<<", ale nie byl jedyny"<<endl;
                            //trzeba bedzie przestawic heada...
                            head->prev->next=head->next;
                            head->next->prev=head->prev;
                            head=ptr->next;
                            delete ptr;
                            licznik--;
                            cout<<"Juz po nim... "<<endl;
                            return;
                        }
                    }
                //gdy to nastepny po X jest headem...
                else //if(ptr!=head)//else if(ptr->next==head)
                {
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                    licznik--;
                    delete ptr;
                    cout<<"Byl gdzies w srodku listy. "<<endl;
                    return;
                }
            }
            ptr=ptr->next;
        }while(ptr!=head);  //dotarcie do konca listy

        if(ptr==head) //lub ptr==head  wtedy komunikat
                cout<<"Niestety nie udalo sie odnalexc i usunac wezla o kluczu: "<<k<<endl;
    }
        ptr=nullptr;
}
//************************************************************************************************************88
void usuwanie_calej_listy()//gotowe
{
    if(!licznik)//gdy lista jest pusta
        {
            cout<<"Lista jest pusta i nie zawiera zadnych elementow do usuniecia!"<<endl;
            return;
        }
    while(head)
    {
                Node * ptr=head;
                        //cout<<"byl headem ";

                        if(ptr->next==ptr)//czy X to jedyny element listy?
                        {
                            //cout<<"i w dodatku jedynym wezlem "<<endl;

                            head=nullptr;//wiec trzeba wyzerowac heaada...
                            delete ptr;
                            licznik--;
                            //cout<<"...juz go nie ma wsrod nas."<<endl;
                            //return;
                        }
                        else
                        {
                            //cout<<", ale nie byl jedyny"<<endl;
                            //trzeba bedzie przestawic heada...
                            head->prev->next=head->next;
                            head->next->prev=head->prev;
                            head=ptr->next;
                            //delete ptr;
                            licznik--;
                            //cout<<"Juz po nim... "<<endl;
                        }
                        //cout<<"Licznik w funkcji: "<<licznik<<endl;
    }
            if((!head)||(!licznik))
            {
                cout<<"Lista usunieta..."<<endl;
                return;
            }
}

int main()
{
    srand(time(0));
//wczytanie z pliku************************************************************************8
    int n, klucz1;
    int k1, k2, k3, k4, k5;

    FILE* fp=fopen("lab2.txt", "r");
    if(fp==NULL)
        return -1;
    fscanf(fp, "%d %d %d %d %d %d", &n, &k1, &k2, &k3, &k4, &k5);
    fclose(fp);
//czas start;*************************************************************************************8
clock_t begin, end;
    double time_spent;
    begin = clock();
//zainicjuj listê;

//wyszukanie klucza k1;
szukaj(k1);
//wstawienie X elementów do listy;
wstawia_X_elem(n);
//wypisz liczbê wêz³ów w liœcie;
cout<<"liczba wezlow: "<<licznik<<endl;
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
prezentacja_poczatek(20);
//wstaw element o wartoœci klucza k2;
wstawia_elem(k2);
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
prezentacja_poczatek(20);
//wstaw element o wartoœci klucza k3;
wstawia_elem(k3);
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
prezentacja_poczatek(20);
//wstaw element o wartoœci klucza k4;
wstawia_elem(k4);
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
prezentacja_poczatek(20);
//wstaw element o wartoœci klucza k5;
wstawia_elem(k5);
//usuñ element o wartoœci klucza k3;
usuwanie_elementu(k3);
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
prezentacja_poczatek(20);
//usuñ element o wartoœci klucza k2;
usuwanie_elementu(k2);
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
prezentacja_poczatek(20);
//usuñ element o wartoœci klucza k5;
usuwanie_elementu(k5);
//wypisz liczbê wêz³ów w liœcie;
cout<<"liczba wezlow: "<<licznik<<endl;
//wyszukaj element o wartoœci klucza k5;
szukaj(k5);
//prezentacja wartoœci kluczowych ostatnich 11 wêz³ów;
prezentacja_koniec(11);
//usuñ wszystkie elementy listy;
usuwanie_calej_listy();
//prezentacja wartoœci kluczowych ostatnich 11 wêz³ów;
prezentacja_koniec(11);
//wypisz liczbê wêz³ów w liœcie;
cout<<"liczba wezlow: "<<licznik<<endl;
//czas stop;
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//wypisz czas wykonania.
std::cout<<"Czas pracy programu: "<<time_spent<<std::endl;

    return 0;
}
