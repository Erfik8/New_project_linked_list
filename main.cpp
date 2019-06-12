#include <iostream>
#include <windows.h>
#include "element_listy.h"
#include <conio.h>

int main()
{

    my_new_list *New_list = NULL;
    my_new_list *_First_ = NULL;
    my_new_list *_Last_ = NULL;
    for(;;)
    {

        system("cls");

        std::cout << "prezentacja listy powiazanej"<<std::endl
                  << "----------------------------"<<std::endl;
        std::cout << "dostepne opcje: "<<std::endl
                  << "1. zarzadzanie lista"<<std::endl
                  << "2. wyswietlenie listy"<<std::endl
                  << "3. zapis listy do pliku tekstowego"<<std::endl
                  << "4. wczytanie listy z pliku"<<std::endl
                  << "5. zamkniecie programu oraz usuniecie niezapisanego postepu"<<std::endl;
        // << "6. instrukcja obslugi i nawigacja po programie"<<std::endl;


        switch (getch())
        {
        case '1':
        {
            if (New_list == NULL)
            {
                std::cout << "LISTA JEST PUSTA, CHCESZ STWORZYC NOWA?" << std::endl;
                std::cout << "WCISNIJ 'T' ABY STWORZYC NOWA LISTE    " << std::endl;
                std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY KONTYNUOWAC   " << std::endl;
                switch(getch())
                {
                case 'T':
                case 't':
                    {
                         New_list = new my_new_list;
                        _First_ = New_list;
                        _Last_ = New_list;
                    }break;
                default:    Sleep(2000);    break;
                }
            }
            else
            {
                    system("cls");
                    my_new_list *Management = _First_;
                    bool Escape = false;
                    do
                    {
                        system("cls");
                        std::cout << "#######################################" << std::endl;
                        std::cout << "#      ZARZADZANIE LISTA POWIZANA     #" << std::endl;
                        std::cout << "#######################################" << std::endl;
                        std::cout << std::endl;
                        Management->show(false);
                        std::cout << std::endl;
                        Show_Manage_menu();

                        switch(getch())
                        {
                        case '1':
                            {
                                    my_new_list *New_previous = new my_new_list(Management, false);
                                    if (New_previous->previous == NULL)
                                    {
                                        _First_ = New_previous;
                                    }
                                    New_previous = NULL;
                                    _First_->set_new_ID_number(0);

                            }break;
                        case '2':
                            {
                                    my_new_list *New_next = new my_new_list(Management, true);
                                    if (New_next->next == NULL)
                                    {
                                        _Last_ = New_next;
                                    }
                                    New_next = NULL;
                                    _First_->set_new_ID_number(0);
                            }break;
                        case '3':
                            {
                                if (Management == _First_ && Management == _Last_) // jest tylko jeden obiekt w bazie
                                {
                                    _First_ = NULL;
                                    _Last_ = NULL;
                                    Escape = true;
                                }
                                else if (Management->previous == NULL&& Management == _First_)
                                {
                                    _First_ = Management->next;
                                }
                                else if (Management->next == NULL && Management == _Last_)
                                {
                                    _Last_ = Management->previous;
                                }
                                else if (Management->next != NULL && Management->previous != NULL){}
                                else
                                {
                                    std::cout << "FATAL ERROR: BLAD ZAPISU OBIEKTOW, WYLACZENIE PROGRAMU";
                                    exit(0);
                                }
                                delete Management;
                                Management = _First_;
                                _First_->set_new_ID_number(0);

                            }break;
                        case '5':
                            {
                                Management->change();
                            }

                        case 'D':
                        case 'd':
                            {
                                if (Management->next == NULL && Management == _Last_)
                                {
                                    Management = _First_;
                                }
                                else if (Management->next != NULL)
                                {
                                    Management = Management->next;
                                }
                                else
                                {
                                    std::cout << "FATAL ERROR: BLAD ZAPISU OBIEKTOW, WYLACZENIE PROGRAMU";
                                    exit(0);
                                }
                            }break;

                        case 'A':
                        case 'a':
                            {
                                if (Management->previous == NULL && Management == _First_)
                                {
                                    Management = _Last_;
                                }
                                else if (Management->previous != NULL)
                                {
                                    Management = Management->previous;
                                }
                                else
                                {
                                    std::cout << "FATAL ERROR: BLAD ZAPISU OBIEKTOW, WYLACZENIE PROGRAMU";
                                    exit(0);
                                }
                            }break;
                        case 'J':
                        case 'j':
                            {
                                std::cout << "wpisz numer elementu: ";
                                int search_id;
                                std::cin>>search_id;
                                my_new_list *search_element = Management->get_element_by_ID(search_id);
                                if (search_element == NULL)
                                {
                                    std::cout << "ERROR: podano zly parametr";
                                    break;
                                }
                                Management = search_element;
                            }break;



                        default:    Escape = true;   break;


                        }
                    }while(Escape == false);
            }

        }break;
        case '2':
        {

            if (New_list == NULL)
            {
                std::cout << "# NIE STWORZONO ZADNEJ LISTY #" <<std::endl;
                Sleep(2000);
            }
            else
            {
                _First_->show();
                Sleep(3000);
            }
        } break;

        case '3':
        {
        } break;
        case '4':
        {
        } break;
        case '5':
        {
            std::cout << "UWAGA. PO ZAMKNIECIU PROGRAMU CALA LISTA ZOSTANIE ZNISZCZONA"<<std::endl
                      << "PRZED ZAMKNIECIEM PROGRAMU ZAPISZ LISTE, JESLI JESZCZE TEGO"<<std::endl
                      << "NIE ZROBILES. CZY MIMO TO CHCESZ ZAMKNAC PROGRAM? <Y OR N>"<<std::endl;
            if (getch()=='y'||getch()=='Y')
                exit(0);
        }
        break;
        case '6':
        {

        } break;
        default:
        {
            std::cout << "nie ma takiej opcji na liscie"<<std::endl;
            Sleep(500);
        }
        break;
        }
    }

}
