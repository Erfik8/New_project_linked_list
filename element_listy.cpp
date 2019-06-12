#include <iostream>
#include <windows.h>
#include "element_listy.h"

void my_new_list::delete_references()
{

    if (this->previous == NULL && this->next != NULL)
    {
        this->next->previous = NULL;
        this->next = NULL;
    }
    else if (this->next == NULL && this->previous != NULL)
    {
        this->previous->next = NULL;
        this->previous = NULL;
    }
    else if (this->next != NULL && this->previous != NULL)
    {
        this->previous->next = this->next;
        this->next->previous = this->previous;
        this->previous = NULL;
        this->next = NULL;
    }
    else
    {
        this->next = NULL;
        this->previous = NULL;
    }
}


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
    std::string check;
    std::cout << "########################" << std::endl;
    std::cout << "#  WYPELNIJ FORMULARZ  #" << std::endl;
    std::cout << "########################" << std::endl;

    std::cout << "Podaj swoje imie:";

    do
    {
        std::getline(std::cin,check);
    }while(check_name_and_surname(check) == false);
    name = check;

    std::cout << "Podaj swoje nazwisko:";
    do
    {
        std::getline(std::cin,check);
    }while(check_name_and_surname(check) == false);
    surname = check;

    std::cout << "Podaj numer telefony:";
    do
    {
        std::getline(std::cin,check);
    }while(check_telephone_and_pesel(check,9) == false);
    telephone = check;

    std::cout << "Podaj swoj pesel:";
    do
    {
        std::getline(std::cin,check);
    }while(check_telephone_and_pesel(check,11) == false);
    pesel = check;

    std::cout << "Podaj e-mail:";
    do
    {
        std::getline(std::cin,check);
    }while(check_email(check) == false);
    e_mail = check;



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
    this->delete_references();
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


    if (show_all == false)
        return;
    if (this->next != NULL)
    {
        this->next->show();
    }

}

void my_new_list::change()
{
    char zmiana;
    std::string check;

    system("cls");
    std::cout << "Imie: " << name<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        do
        {
            std::getline(std::cin,check);
        }
        while(check_name_and_surname(check) == false);
        name = check;
    }


    system("cls");
    std::cout << "Nazwisko: " << surname<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        do
        {
            std::getline(std::cin,check);
        }
        while(check_name_and_surname(check) == false);
        surname = check;
    }


    system("cls");
    std::cout << "Numer telefonu: " << telephone<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        do
        {
            std::getline(std::cin,check);
        }
        while(check_telephone_and_pesel(check,9) == false);
        telephone = check;
    }


    system("cls");
    std::cout << "Numer pesel: " << pesel<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        do
        {
            std::getline(std::cin,check);
        }
        while(check_telephone_and_pesel(check,11) == false);
        pesel = check;
    }


    system("cls");
    std::cout << "adres e-mail: " << e_mail<<std::endl;
    std::cout << "WCISNIJ 'T' ABY ZMIENINC WARTOSC"<<std::endl;
    std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY POZOSTAWIC BEZ ZMIAN"<<std::endl;
    zmiana = getch();
    if (zmiana == 'T' || zmiana == 't')
    {
        std::cout << "wprowadz nowa wartosc: ";
        do
        {
            std::getline(std::cin,check);
        }
        while(check_email(check) == false);
        e_mail = check;
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
    else
        return;

}

void my_new_list::set_new_ID_number(int number)
{
    this->ID = number;
    if (this->next != NULL)
    {
        this->next->set_new_ID_number(++number);
    }
    else
        return;
}

bool my_new_list::replace_element(my_new_list *friend_element, bool if_before)
{
    if (friend_element == NULL)
    {
        std::cout << "FATAL ERROR: OBIEKT NIE ISTNIEJE" << std::endl<< std::endl;
        std::cout << "ZAMKN¥C PROGRAM, CZY KONTYNUOWAC?" << std::endl;
        std::cout << "WCISNIJ 'Y' ABY WYLACZYC PROGRAM AWARYJNIE"<< std::endl;
        std::cout << "WCISNIJ DOWOLNY KLAWISZ ABY KONTYUOWAC" << std::endl;
        if (getch() == 'y' || getch() == 'Y')
            return false;
        else
            return true;
    }
    else
    {
        this->delete_references();
        if (if_before == true) // in this case, replaced element will be put before friend_element
        {
            if (friend_element->previous == NULL && this->next == NULL)
            {
                friend_element->previous = this;
                this->next = friend_element;
            }
            else if (this->next == NULL)
            {
                friend_element->previous->next = this;
                this->previous = friend_element->previous;
                this->next = friend_element;
                friend_element->previous = this;
            }
            else
            {
                std::cout << "ERROR: niepowodzenie usuwania powiazan, element nie moze byc przeniesiony"<<std::endl;
                return true;
            }
        }
        else
        {
            if (friend_element->next == NULL && this->previous == NULL)
            {
                friend_element->next = this;
                this->previous = friend_element;

            }
            else if (this->previous == NULL)
            {
                friend_element->next->previous = this;
                this->next = friend_element->next;
                this->previous = friend_element;
                friend_element->next = this;
            }
            else
            {
                std::cout << "ERROR: niepowodzenie usuwania powiazan, element nie moze byc przeniesiony"<<std::endl;
                return true;
            }
        }
    }
    return true;
}

void my_new_list::DELETE_ALL_LIST(bool direction, bool first_call)
{
    if (first_call == true)
    {
        if (this->next != NULL)
            this->next->DELETE_ALL_LIST(true, false);
        if (this->previous != NULL)
            this->previous->DELETE_ALL_LIST(false, false);
    }
    else if (direction == true) // in this case, function will find elements by 'next' pointer
    {
        if (this->next != NULL)
            this->next->DELETE_ALL_LIST(true, false);
    }
    else
    {
        if (this->previous != NULL)
            this->previous->DELETE_ALL_LIST(false, false);
    }
    delete this;
}

my_new_list *my_new_list::get_element_by_ID(int const id)
{
    if (this->ID < id)
    {
        if (this->next == NULL)
            return NULL;

        return this->next->get_element_by_ID(id);
    }
    else if (this->ID > id)
    {
        if (this->previous == NULL)
            return NULL;

        return this->previous->get_element_by_ID(id);
    }
    else if (this->ID == id)
        return this;
    else
        return NULL;
}

my_new_list *my_new_list::get_next_element(my_new_list * const First, my_new_list * const Last)
{
    my_new_list *Next_element = NULL;
    if (this->next == NULL && this == Last)
    {
        Next_element = First;
    }
    else if (this->next != NULL)
    {
        Next_element = this->next;
    }
    else
    {
        std::cout << "FATAL ERROR: BLAD ZAPISU OBIEKTOW, WYLACZENIE PROGRAMU";
        this->DELETE_ALL_LIST();
        exit(0);
    }
    return Next_element;
}
my_new_list *my_new_list::get_previous_element(my_new_list *const First,my_new_list *const Last)
{
    my_new_list *Previous_element = NULL;
    if (this->previous == NULL && this == First)
    {
        Previous_element = Last;
    }
    else if (this->previous != NULL)
    {
        Previous_element = this->previous;
    }
    else
    {
        std::cout << "FATAL ERROR: BLAD ZAPISU OBIEKTOW, WYLACZENIE PROGRAMU";
        this->DELETE_ALL_LIST();
        exit(0);
    }
    return Previous_element;
}
