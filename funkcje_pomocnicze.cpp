#include <iostream>
#include <windows.h>
#include "element_listy.h"

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

bool check_name_and_surname(std::string const name)
{
    const short length_of_name = name.size();
    for (int i = 0; i< length_of_name; i++)
    {
        if (i == 0)
        {
            if (!(name[i]>= 'A' && name[i] <= 'Z'))
            {
                std::cout << "Zaczyna siê z ma³ej litery, podaj jeszcze raz: ";
                return false;
            }
        }
        else
        {
            if (!(name[i]>= 'a' && name[i] <= 'z'))
            {
                std::cout << "W œrodku nie moze byc duzych liter, podaj jeszcze raz: ";
                return false;
            }
        }
    }
    return true;
}
bool check_telephone_and_pesel(std::string const number, short const tel_or_pesel)
{
    if (tel_or_pesel == 9) //this is phone number
    {
        if (number.size() != 9)
        {
            std::cout << "numer telefonu jest zlej dlugosci, wpisz jeszcze raz: ";
            return false;
        }
    }
    else if (tel_or_pesel == 11) //this is pesel
    {
        if (number.size() != 11)
        {
            std::cout << "pesel jest zlej dlugosci, wpisz jeszcze raz: ";
            return false;
        }
    }
    else
    {
        std::cout << "ERROR: blad podczas sprawdzania, nie mozna ukonczyc operacji " << std::endl;
        return false;
    }

    if (atoi(number.c_str()) == 0)
    {
        std::cout << "numer nie moze zawierac znakow inne niz cyfry, wpisz jeszcze raz: ";
        return false;
    }
    return true;
}
bool check_email(std::string const e_mail)
{
    const short length_of_e_mail = e_mail.size();
    std::size_t correct_e_mail = e_mail.find('@');
    if (correct_e_mail == std::string::npos)
    {
        std::cout << "niepoprawny adres e_mail, wpisz jeszcze raz: ";
        return false;
    }
    return true;

}

