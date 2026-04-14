#pragma once
#include "../service/service.h"
#include "../validation/validation.h"

class UI 
{
    private:
        Service service;
        // admin functionalities
        void menu();
        void add_coat_ui();
        void delete_coat_ui();
        void update_coat_ui();
        void display_coat_ui();
        // user functionalities
        void user_menu();
        void see_coats_ui();
        void add_to_basket_ui();
        void total_ui();

    public:
        UI(const Service& s);
        void runApplication();

};