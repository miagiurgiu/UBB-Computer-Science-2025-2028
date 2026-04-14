#pragma once
#include "../service/service.h"
#include "../repo/repo.h"

class UI {
    private:
        Service& service;
        void add_ui();
        void show_ui();
        void show_sorted_ui();
        void menu();
    public:
        UI(Service& s);
        void run();
};