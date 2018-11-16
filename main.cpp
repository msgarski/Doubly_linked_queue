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
//zmienna globalna do zlicznia wezlow listy:
int licznik=0;
//********************************************************************************8
void wstawia_elem(Node ** head, int klucz)//gotowe
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
//Gdy lista jest pusta:
        if(*head==nullptr)
        {
            *head=nowy;
            nowy->next=nowy;
            nowy->prev=nowy;
            licznik++;
        }//OK
//***************************************************************************************************
//Wstawianie z szukaniem miejsca do niepustej listy:

        //Gdy wstawiamy przed HEADa:
        else if((nowy->klucz)<((*head)->klucz))
        {
            nowy->next=*head;
            nowy->prev=(*head)->prev;
            (*head)->prev=nowy;
            *head=nowy;
            (*head)->prev->next=*head;  //wazne odnowienie polaczenia z koncem listy
            licznik++;
        }

        else
        {//gdy wstawiamy gdzies w srodku, lub na koncu:
                Node *ptr=*head;   //pomocniczt wskaznik wedrujacy
            do
                {   //sprawdzamy, czy to nie duplikat:
                    if(nowy->klucz==ptr->klucz)
                    {
                        std::cout<<"Powtorzona wartosc klucza! "<<nowy->klucz<<" = "<<ptr->klucz<<std::endl;
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
                    else if(ptr->next==*head)//wstawienie za ostatnim elementem listy
                    {
                        nowy->next=*head;
                        nowy->prev=ptr;
                        (*head)->prev=nowy;
                        ptr->next=nowy;
                        licznik++;
                        break;
                    }
                        ptr=ptr->next;  //przesuwamy sie o 1 wezel do przodu
                }
            while(ptr!=*head);
            ptr=nullptr;
            }
}

//*************************************************************************************************************
//hurtowe wstawianie wezlow do listy
void wstawia_X_elem(Node ** head, int X)//gotowe
{
    Node *ptr=*head;
    int los;
bool tabl_losowych[99901]{};            //tablica do spkrawdzania powtarzalnosci
//*********************************************************************************************
//odznaczenie w tablicy juz istniejacych w liscie kluczy
if(*head)
{
    //przejscie przez liste aby zaktualizowac tablice wystepujacych juz w liscie kluczzy
    do
    {
        if(ptr->klucz>=99&&ptr->klucz<=99999)
            tabl_losowych[ptr->klucz]=true;
        ptr=ptr->next;
    }while(ptr!=*head);
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
                wstawia_elem(head, los);
        }
    ptr=nullptr; //oslepienie wskaznika
        cout<<"Hurtowe wstawianie "<<X<<" wezlow do listy"<<endl<<endl;
}

void prezentacja_poczatek(Node *head, int liczba_wezlow)//przeniesione
{//funkcja wypisuje n poczatkowych wezlow od czola listy

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
    Node * ptr=head;
//cout<<"zawartosc head: "<<ptr->klucz<<endl;
    for(int i=0; i<liczba_wezlow; i++)//tu przestawilem - trzeva przywrocic!!!
    {
        cout<<"Klucz: "<<ptr->klucz<<"  "<<ptr->los<<"  "<<ptr->ch<<endl;
        ptr=ptr->next;
        if(ptr==head)
            break;
    }
    ptr=nullptr;

}

//**************************************************************************************************888
void prezentacja_koniec(Node * head, int liczba_wezlow) //przeniesione ale jest nowa poprawka
{//funkcja wypisuje n koncowych wezlow listy

    cout<<"Wyswietlenie wsteczne "<<liczba_wezlow<<" wezlow listy:"<<endl;
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
    Node * ptr=head->prev;

    int licznik_temp=licznik;
    for(int i=0; i<liczba_wezlow&&licznik_temp>0; i++, licznik_temp--)
    {
        cout<<"Klucz: "<<ptr->klucz<<"  "<<ptr->los<<"  "<<ptr->ch<<endl;
        ptr=ptr->prev;
    }
    ptr=nullptr;
}

//*******************************************************************************************************
void szukaj(Node *head, int klucz)//gotowe i przeniesione
{
    //funkcja wyszukuje wezel o zadanym kluczu i wypisuje go
    cout<<"Szukamy wezla o kluczu: "<<klucz<<endl;
    Node * ptr=head;
    if(head)//lizta moze byc pusta...
    {
        do
        {
            if(ptr->klucz==klucz)
                {
                    cout<<"Znaleziony klucz : "<<ptr->klucz<<
                    "   ma wartosc losowa double: "<<ptr->los<<endl;
                    return;
                }
            ptr=ptr->next;
        }while(ptr!=head);
            if(ptr==head)
                cout<<"Niestety nie udalo sie odnalezc w liscie wartosci "<<klucz<<endl<<endl;
    }
    else
        {
            cout<<"Klucz "<<klucz<<" nie zostal znaleziony, poniewaz"<<endl<<"lista nie zawiera zadnych elementow!"<<endl<<endl;
        }
        ptr=nullptr;
}

//*********************************************************************************************************
void usuwanie_elementu(Node ** head, int k)//gotowe
{//funkcja usuwa z listy wezel o zadanym kluczu
    cout<<"Usuwamy wezel o kluczu: "<<k<<endl<<endl;
    if(!*head)//gdy lista jest pusta
        {
            cout<<"Lista jest pusta i nie zawiera zadnych elementow do usuniecia!"<<endl<<endl;
            return;
        }
    Node * ptr=*head;
    //lista moze byc pusta ,,, po usunieciu
    if(*head)
    {
        do
        {
            if(ptr->klucz==k)   //znalezienie wezla z szukanym kluczem
            {
                cout<<"wezel o kluczu "<<k<<" znaleziony..."<<endl;

                    if(ptr==*head)//gdy X jest headem...
                    {
                        cout<<"byl to head ";

                        if(ptr->next==ptr)//czy X to jedyny element listy?
                        {
                            cout<<"i w dodatku ostatni wezel "<<endl;
                            *head=nullptr;//wiec trzeba wyzerowac heaada...
                            delete ptr;
                            licznik--;
                            cout<<"...juz go nie ma wsrod nas."<<endl<<endl;
                            return;
                        }
                        else
                        {
                            cout<<"i zostal usuniety"<<endl<<endl;
                            //trzeba bedzie przestawic heada...
                            (*head)->prev->next=(*head)->next;
                            (*head)->next->prev=(*head)->prev;
                            *head=ptr->next;
                            delete ptr;
                            licznik--;
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
                    cout<<"Byl gdzies w srodku listy. Usuniety..."<<endl<<endl;
                    return;
                }
            }
            ptr=ptr->next;
        }while(ptr!=*head);  //dotarcie do konca listy

        if(ptr==*head) //lub wekasowac
                cout<<"Niestety nie udalo sie odnalezc i usunac wezla o kluczu: "<<k<<endl<<endl;
    }
        ptr=nullptr;
}

//************************************************************************************************************88
void usuwanie_calej_listy(Node **head)//gotowe
{
    //zprawdzenie globalnego licznika, w razie czego...
    int dl_kolejki=0;
    if(!*head)
        {
            cout<<"Lista jest pusta i nie zawiera zadnych elementow do usuniecia!"<<endl;
            return;
        }
    else
        {
            Node *ptr=*head;
            do
            {
                dl_kolejki++;
                ptr=ptr->next;
            }while(ptr!=*head);
            cout<<"porownanie obu licznikow: "<<dl_kolejki<<" = "<<licznik<<endl<<"Mozna usuwac..."<<endl<<endl;

            //zaczynamy usuwanie
            cout<<"Usuwanie wszystkich wezlow listy... calutkiej listy!"<<endl<<endl;

            while(*head)
                {
                ptr=*head;
                //cout<<"na razie dobrze"<<endl;
                    if(ptr->next==ptr)//czy X to jedyny element listy?
                        {
                            *head=nullptr;//wiec trzeba wyzerowac heaada...
                            delete ptr;
                            licznik--;
                            cout<<"...juz ich nie ma wsrod nas. licznik = "<<licznik<<endl<<endl;
                            return;
                        }
                        else
                        {
                            //trzeba bedzie przestawic heada...
                            (*head)->prev->next=(*head)->next;
                            (*head)->next->prev=(*head)->prev;
                            *head=ptr->next;
                            licznik--;
                        }
                    }
                ptr=nullptr;
        }
}
//************************************************************************************************************88

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
    struct Node *head=nullptr;

//wyszukanie klucza k1;
    szukaj(head, k1);

//wstawienie X elementów do listy;
    wstawia_X_elem(&head, n);

//wypisz liczbê wêz³ów w liœcie;
    cout<<"liczba wezlow: "<<licznik<<endl;

//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
    prezentacja_poczatek(head, 20);

//wstaw element o wartoœci klucza k2;
cout<<"Wstawiamy element "<<k2<<endl;
    wstawia_elem(&head, k2);

//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
    prezentacja_poczatek(head, 20);

//wstaw element o wartoœci klucza k3;
cout<<"Wstawiamy element "<<k3<<endl;
    wstawia_elem(&head, k3);

//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
    prezentacja_poczatek(head, 20);

//wstaw element o wartoœci klucza k4;
cout<<"Wstawiamy element "<<k4<<endl;
    wstawia_elem(&head, k4);

//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
    prezentacja_poczatek(head, 20);

//wstaw element o wartoœci klucza k5;
cout<<"Wstawiamy element "<<k5<<endl;
    wstawia_elem(&head, k5);

//usuñ element o wartoœci klucza k3;
    usuwanie_elementu(&head, k3);

//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
    prezentacja_poczatek(head, 20);

//usuñ element o wartoœci klucza k2;
    usuwanie_elementu(&head, k2);

//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
    //prezentacja_poczatek(head, 20);

//usuñ element o wartoœci klucza k5;
    usuwanie_elementu(&head, k5);

//wypisz liczbê wêz³ów w liœcie;
    cout<<"liczba wezlow: "<<licznik<<endl<<endl;

//wyszukaj element o wartoœci klucza k5;
    szukaj(head, k5);

//prezentacja wartoœci kluczowych ostatnich 11 wêz³ów;
    //prezentacja_koniec(head, 11);

//usuñ wszystkie elementy listy;
    usuwanie_calej_listy(&head);

//prezentacja wartoœci kluczowych ostatnich 11 wêz³ów;
    prezentacja_koniec(head, 11);

//wypisz liczbê wêz³ów w liœcie;
    cout<<"liczba wezlow: "<<licznik<<endl<<endl;

//czas stop;
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

//wypisz czas wykonania.
    std::cout<<"Czas pracy programu: "<<time_spent<<std::endl;

    return 0;
}
