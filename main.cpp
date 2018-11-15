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
void wstawia_elem(int klucz)
{
    srand(time(0));
//alokacja pamieci na nowy wezel listy
        Node *nowy= new Node;
        if(!nowy)
        {
            std::cout<<"Nie udalo sie utworzyc nowego wezla listy!\n Brak pamieci!"<<std::endl;
            //tutaj trzeba dac przerwanie
        }
//inicjalizacja liczbowych zmiennych wezla:
        nowy->klucz=klucz;
        nowy->los=rand()%1000;
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

            //test adresow - pozniej do usuniecia
            //cout<<"Test adresow I-go wezla:"<<endl;
            //cout<<"nowy = "<<nowy<<"    "<<"head = "<<head<<"   "<<"nowy->next = "<<nowy->next<<
           // "   "<<"nowy->prev = "<<nowy->prev<<endl;
        }//OK
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
            //ok
//***************************************************************************************************
            //test adresow - pozniej do usuniecia
            //cout<<"Test adresow II-go wezla klucz<klucz heada:"<<endl;
           // cout<<"nowy = "<<nowy<<"    "<<"head = "<<head<<"   "<<"nowy->next = "<<nowy->next<<
           // "   "<<"nowy->prev = "<<nowy->prev<<endl;

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
        //dotad chyba jest dobrze
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



void wstawia_X_elem(int X)
{
    //gdy powtorki...
    //gdy brak pamieci...S
    srand(time(0));
    int los;
    //gdy powtorki...
    //gdy brak pamieci...S
bool tabl_losowych[99901]{};            //tablica do spkrawdzania powtarzalnosci
//*********************************************************************************************
//odznaczenie w tablicy juz istniejacych w liscie kluczy
if(head)
{
    Node * ptr=head;
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
//***********************************************************************************************
wstawia_elem(los);
}


}

void prezentacja_poczatek(int liczba_wezlow)
{
    //funkcja wypisuje n poczatkowych wezlow od czola listy
    //moze ich tyle nie byc...
    //lista moze byc pusta

}

void prezentacja_koniec(int liczba_wezlow)
{
    //funkcja wypisuje n koncowych wezlow listy
    //moze byc ich mniej ...
    //lista moze byc pusta
}

void szukaj(int klucz)
{
    Node * ptr=head;
    //funkcja wyszukuje wezel o zadanym kluczu i wypisuje go
    //moze go nie znalezc...
    //lizta moze bbyc pusta...
    if(head)
    {
        Node * ptr=head;
        int sukces=0;
        do
        {
            if(ptr->klucz==klucz)
                {
                    sukces++;
                    cout<<"adres wezla "<<ptr<<"   szukany klucz : "<<ptr->klucz<<
                    "   wartosc losowa double: "<<ptr->los<<endl;
                    break;
                }
            ptr=ptr->next;
        }while(ptr!=head);
            if(!sukces)
                cout<<"Niestety nie udalo sie odnalexc szukanej wartosci..."<<endl;
    }
    else
        {
            cout<<"Lista nie zawiera zadnych elementow!"<<endl;
        }



}

void usuwanie_elementu(int klucz)
{
    //funkcja usuwa z listy wezel o zadanym kluczu
    //moze go tam nie byc...
    //lista moze byc pusta...
    if(!head)
        {
            cout<<"Lista nie zawiera zadnych elementow do usuniecia!"<<endl;
            return;
        }

    Node * ptr=head;
    if(head)
    {
        do
        {
            if(ptr->klucz==k)   //znalezienie wezla z szukanym kluczem
            {
                cout<<"znaleziony"<<endl;
                    //gdy X jest headem...
                    if(ptr==head)
                    {
                        cout<<"byl headem"<<endl;
                        //czy X to jedyny element listy?
                        if(ptr->next==ptr)
                        {
                            cout<<"byl jedynym wezlem:"<<endl;
                            //trzeba wyzerowac heaada...
                            delete ptr;
                            head=nullptr;//chyba ok
                            return;
                        }
                        else
                        {
                            cout<<"head, ale nie byl jedyny"<<endl;
                            //trzeba bedzie przestawic heada...
                            head->prev->next=head->next;
                            head->next->prev=head->prev;
                            head=ptr->next;
                            delete ptr;
                            return;
                        }
                    }
                //gdy to nie X, ale nastepny jest headem...
                else if(ptr->next==head)
                {

                }
                else
                {
                    //czyli X jest gdzies w srodku
                    //usuwanie wezla
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                    licznik--;
                    break;  //lub return;

                }
            }
            ptr=ptr->next;
        }while(ptr!=head);  //dotarcie do konca listy
            if(ptr==head) //lub ptr==head  wtedy komunikat
                cout<<"Niestety nie udalo sie odnalexc i usunac wezla o kluczu: "<<k<<endl;
    }
        //ptr=nullptr;
}




int main()
{
//wczytanie z pliku
    int n, klucz1;
    int k1, k2, k3, k4, k5;


    FILE* fp=fopen("lab02.txt", "r");
    if(fp==NULL)
        return -1;
    fscanf(fp, "%d %d %d %d %d %d", &n, &k1, &k2, &k3, &k4, &k5);
    fclose(fp);





//czas start;
clock_t begin, end;
    double time_spent;
    begin = clock();

//zainicjuj listê;

//wyszukanie klucza k1;

//wstawienie X elementów do listy;

//wypisz liczbê wêz³ów w liœcie;
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
//wstaw element o wartoœci klucza k2;
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
//wstaw element o wartoœci klucza k3;
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
//wstaw element o wartoœci klucza k4;
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
//wstaw element o wartoœci klucza k5;
//usuñ element o wartoœci klucza k3;
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
//usuñ element o wartoœci klucza k2;
//prezentacja wartoœci kluczowych pierwszych 20 wêz³ów pocz¹wszy od czo³a listy;
//usuñ element o wartoœci klucza k5;
//wypisz liczbê wêz³ów w liœcie;
//wyszukaj element o wartoœci klucza k5;
//prezentacja wartoœci kluczowych ostatnich 11 wêz³ów;
//usuñ wszystkie elementy listy;
//prezentacja wartoœci kluczowych ostatnich 11 wêz³ów;
//wypisz liczbê wêz³ów w liœcie;

//czas stop;
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//wypisz czas wykonania.
std::cout<<"Czas pracy programu: "<<time_spent<<std::endl;

    return 0;
}
