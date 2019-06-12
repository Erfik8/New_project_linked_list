#include <iostream>
#include <windows.h>
#include "element_listy.h"


my_new_list::my_new_list()
: name("")
, surname("")
, telephone("")
, pesel("")
, e_mail("")
, ID(0)
, previous(NULL)
, next(NULL)
{
    std::cout << "########################" << std::endl;
    std::cout << "#  WYPELNIJ FORMULARZ  #" << std::endl;
    std::cout << "########################" << std::endl;

    std::cout << "Podaj swoje imie:";
    std::cin >> name;

    std::cout << "Podaj swoje nazwisko:";
    std::cin >> surname;

    std::cout << "Podaj numer telefony:";
    std::cin >> telephone;

    std::cout << "Podaj swoj pesel:";
    std::cin >> pesel;

    std::cout << "Podaj e-mail:";
    std::cin >> e_mail;



}

my_new_list::my_new_list(my_new_list *_Previous_, bool next_or_previous)
:my_new_list()
{
    if (next_or_previous == false) // ten element ma sie znalezc za elementem _Previous_
    {
        if (_Previous_->previous == NULL)
        {
            this->next = _Previous_;
            _Previous_->previous = this;
        }
        else
        {
            _Previous_->previous->next = this;
            this->next = _Previous_;
            this->previous = _Previous_->previous;
            _Previous_->previous = this;
        }

    }
    else // ten element ma sie znalezc przed elementem _Previous_
    {
        if (_Previous_->next == NULL)
        {
            this->previous = _Previous_;
            _Previous_->next = this;
        }
        else
        {
            _Previous_->next->previous = this;
            this->previous = _Previous_;
            this->next = _Previous_->next;
            _Previous_->next = this;
        }
    }
}

my_new_list::~my_new_list()
{
    std::cout<<"Usuwanie obiektu"<<name<<std::endl;

    if (this->previous == NULL)
    {
        this->next->previous = NULL;
        this->next = NULL;
    }
    else if (this->next == NULL)
    {
        this->previous->next = NULL;
        this->previous = NULL;
    }
    else
    {
        this->previous->next = this->next;
        this->next->previous = this->previous;
        this->previous = NULL;
        this->next = NULL;
    }
}

void my_new_list::show(bool show_all)
{

    std::cout<<"Numer porzadkowy: :"<<ID<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Imie: "<<name<<std::endl;
    std::cout<<"Nazwisko: "<<surname<<std::endl;
    std::cout<<"Numer telefonu: "<<telephone<<std::endl;
    std::cout<<"Numer Pesel: "<<pesel<<std::endl;
    std::cout<<"Adres e-mail: :"<<e_mail<<std::endl;


    if (show_all == false) return;
    if (this->next != NULL)
    {
        this->next->show();
    }

}

void my_new_list::change()
{
    char zmiana;
    system("cls");
    std::cout << "Imie: " << name<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        std::cin >> name;
    }


    system("cls");
    std::cout << "Nazwisko: " << surname<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        std::cin >> surname;
    }


    system("cls");
    std::cout << "Numer telefonu: " << telephone<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        std::cin >> telephone;
    }


    system("cls");
    std::cout << "Numer pesel: " << pesel<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        std::cin >> pesel;
    }


    system("cls");
    std::cout << "adres e-mail: " << e_mail<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        std::cin >> e_mail;
    }
    system("cls");
    std::cout<<"czy pokazane dane sie zgadzaja? "<<std::endl<<std::endl;


    this->show(false);
    std::cout<<std::endl;
    std::cout << "WCISNIJ 'N' ABY ZMIENIC WARTOSCI JESZCZE RAZ"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY ZAAKCEPTOWAC"<<std::endl;

    zmiana = getch();
    if (zmiana == 'n' || zmiana == 'N')
    {
        this->change();
    }
    else   return;

}

void my_new_list::set_new_ID_number(int number)
{
    this->ID = number;
    if (this->next != NULL)
    {
        this->next->set_new_ID_number(++number);
    }
    else return;
}



void Show_Manage_menu()
{
    std::cout << "wybierz jedna z opcji, wciskajac numer na klawiaturze"<<std::endl
                 << "-----------------------------------------------------"<<std::endl
                 << "1. dodaj element przed aktualny"<<std::endl
                 << "2. dodaj element po aktualnym"<<std::endl
                 << "3. usun aktualny element"<<std::endl
                 << "4. przesun dany element"<<std::endl
                 << "5. zmien parametr danego elementu"<<std::endl
                 << "6. szukaj elementu, wybierajac parametr oraz wpisujac fraze"<<std::endl;
            std::cout << "wcisnij dana litere, aby przeniesc sie do innego elementu"<<std::endl
                 << "---------------------------------------------------------"<<std::endl
                 << "A. element wczesniej"<<std::endl
                 << "D. element dalej"<<std::endl
                 << "J. skocz do innego elemntu, wpisujac jego numer"<<std::endl
                 << "S. idz na poczatek"<<std::endl
                 << "F. idz na koniec"<<std::endl
                 << "wcisnij dowolny klawisz, aby wyjsc"<<std::endl;
}

my_new_list *my_new_list::get_element_by_ID(int const id)
{
    if (this->ID < id)
    {
        if (this->next == NULL) return NULL;

        this->next->get_element_by_ID(id);
    }
    else if (this->ID > id)
    {
        if (this->previous == NULL) return NULL;

        this->previous->get_element_by_ID(id);
    }
    else if (this->ID == id) return this;
    else return NULL;
}
