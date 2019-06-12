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

        void delete_references();
    public:
        my_new_list *previous;
        my_new_list *next;

        my_new_list();
        my_new_list(my_new_list *_Previous_, bool next_or_previous);
        ~my_new_list();

        void show(bool=true);
        void change();
        void set_new_ID_number(int const number);
        void DELETE_ALL_LIST(bool = true, bool = true);

        bool replace_element(my_new_list *friend_element, bool if_before);

        my_new_list *get_element_by_ID(int const id);
        my_new_list *get_next_element(my_new_list * const First, my_new_list * const Last);
        my_new_list *get_previous_element(my_new_list * const First, my_new_list * const Last);
};

void Show_Manage_menu();

bool check_name_and_surname(std::string const name);
bool check_telephone_and_pesel(std::string const number, short const tel_or_pesel);
bool check_email(std::string const e_mail);




#endif // LISTA
