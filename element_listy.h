#include <iostream>
#include <windows.h>
#include <conio.h>

#ifndef LISTA

#define LISTA

class my_new_list
{
    private:
        std::string name;
        std::string surname;
        std::string telephone;
        std::string pesel;
        std::string e_mail;
        int ID;
    public:
        my_new_list *previous;
        my_new_list *next;

        my_new_list();
        my_new_list(my_new_list *_Previous_, bool next_or_previous);
        ~my_new_list();

        void show(bool=true);
        void change();
        void set_new_ID_number(int const number);
        my_new_list *get_element_by_ID(int const id);
};

void Show_Manage_menu();




#endif // LISTA
