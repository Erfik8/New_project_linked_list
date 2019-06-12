#include <iostream>
#include <windows.h>
#include "element_listy.h"
#include <conio.h>
//#include <cstdlib>

int main()
{

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
            if (_First_ == NULL)
            {
                std::cout << "LISTA JEST PUSTA, CHCESZ STWORZYC NOWA?" << std::endl;
                std::cout << "WCISNIJ 'T' ABY STWORZYC NOWA LISTE    " << std::endl;
                std::cout << "WCISNIJ DOWOLNY KLAWISZ, ABY KONTYNUOWAC   " << std::endl;
                switch(getch())
                {
                case 'T':
                case 't':
                    {
                        _First_ = new my_new_list;
                        _Last_ = _First_;
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
                        case '4':
                            {
                                my_new_list *Replace = Management;
                                bool accepted = false;

                                do
                                {
                                    std::string search_element = "";
                                    system("cls");
                                    Replace->show(false);
                                    std::cout << std::endl;

                                    std::cout << "wpisz liczbe, aby przeskoczyc do elementu po ID" << std::endl;
                                    std::cout << "wpisz '/SEARCH' aby znalezc element po odpowiednim parametrze" <<  std::endl;
                                    std::cout << "wcisnij i zatwierdz 'A' lub 'D', aby pourszac sie po kolejnych elementach bazy" << std::endl;
                                    std::cout << "wcisnij i zatwierdz 'C' aby anulowac przenoszenie" << std::endl;
                                    std::cout << "wcisnij enter, aby zaakceptowac" << std::endl;
                                    std::getline(std::cin,search_element);

                                    if (search_element == "/SEARCH")
                                    {
                                        // tu metoda do napisania szukania elementu po frazie
                                    }
                                    else if (search_element == "A" || search_element == "a")
                                    {
                                        Replace = Replace->get_previous_element(_First_,_Last_);
                                    }
                                    else if (search_element == "D" || search_element == "d")
                                    {
                                        Replace = Replace->get_next_element(_First_,_Last_);
                                    }
                                    else if (search_element == "C" || search_element == "c")
                                    {
                                        Replace = NULL;
                                        break;
                                    }
                                    else if (search_element == "0")
                                    {
                                        Replace = _First_;
                                    }
                                    else if (atoi(search_element.c_str()) != 0)
                                    {

                                        int return_id = atoi(search_element.c_str());
                                        Replace = Replace->get_element_by_ID(return_id);
                                        if (Replace == NULL)
                                        {
                                            std::cout << "ERROR: nie ma takiego elementu" << std::endl;
                                            Sleep(2000);
                                            Replace = Management;
                                        }
                                    }
                                    else if (search_element == "")
                                    {
                                        if (Management == Replace)
                                        {
                                            std::cout << "ERROR: wybrano ten sam element, ktory ma byc przeniesiony, powrot do menu wyboru" << std::endl;
                                            Sleep(1500);
                                        }
                                        else
                                        {
                                            bool all_OK =true;
                                            std::cout << std::endl;
                                            std::cout << "B - wstaw przed wybranym elementem"<< std::endl;
                                            std::cout << "A - wstaw za wybranym elementem"<< std::endl;
                                            std::cout << "Wcisnij dowolny klawisz, aby anulowac"<< std::endl;
                                            switch (getch())
                                            {
                                            case 'A':
                                            case 'a':
                                                {
                                                    if (Replace == _Last_)
                                                    {
                                                        _Last_ = Management;
                                                    }
                                                    if (Management == _First_)
                                                    {
                                                        _First_ = Management->next;
                                                    }
                                                    all_OK = Management->replace_element(Replace,false);

                                                }break;
                                            case 'B':
                                            case 'b':
                                                {
                                                    if (Replace == _First_)
                                                    {
                                                        _First_ = Management;
                                                    }
                                                    if (Management == _Last_)
                                                    {
                                                        _Last_ = Management->previous;
                                                    }
                                                    all_OK = Management->replace_element(Replace,true);
                                                }
                                            default: break;
                                            }
                                            if (all_OK == false)
                                            {
                                                std::cout << "FATAL ERROR: AWARYJNE WYLACZENIE PROGRAMU" << std::endl;
                                                Management = NULL;
                                                Replace = NULL;
                                                _First_->DELETE_ALL_LIST();
                                                if (_First_ != NULL) delete _First_;
                                                _First_ = NULL;
                                                _Last_ = NULL;
                                                exit(0);
                                            }
                                            accepted = true;
                                        }
                                    }
                                    else
                                    {
                                        std::cout << "wprowadzono nieprawidlowe dane, wpisz jeszcze raz" << std::endl;
                                        Sleep(1500);
                                    }

                                }while(accepted != true);

                                std::cout << "Operacja zakonczona powodzeniem" << std::endl;
                                Sleep(2000);
                                system("cls");
                                Management = _First_;
                                Management->set_new_ID_number(0);
                            }break;
                        case '5':
                            {
                                Management->change();
                            }

                        case 'D':
                        case 'd':
                            {
                                Management = Management->get_next_element(_First_, _Last_);
                            }break;

                        case 'A':
                        case 'a':
                            {
                                Management = Management->get_previous_element(_First_, _Last_);
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

            if (_First_ == NULL)
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
            {
                _First_->DELETE_ALL_LIST();
                _First_ = NULL;
                _Last_ = NULL;
                exit(0);
            }
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
