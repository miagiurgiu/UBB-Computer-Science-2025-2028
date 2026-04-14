#include "../ui/ui.h"
#include <iostream>

UI::UI(Service& s): service{s} {}

void UI::menu() {
    std::cout<<"1. Add protein.\n";
    std::cout<<"2. Show all proteins with their info.\n";
    std::cout<<"3. Show all proteins with given name sorted by organism.\n";
    //std::cout<<"4. Add protein.\n";
    std::cout<<"0. Exit.\n";
}

void UI::add_ui() {
    std::string organism, name, sequence;

    std::cout<<"Oranism: ";
    std::getline(std::cin, organism);

    std::cout<<"Name: ";
    std::getline(std::cin, name);

    std::cout<<"Sequence: ";
    std::getline(std::cin,sequence);


    Protein p{organism, name, sequence};

    if (this->service.add_protein(p))
        std::cout<<"Protein added.\n";
    else
        std::cout<<"Protein already exists.\n";
}

void UI::show_ui() {
    DynamicArray proteins = this->service.show_all_proteins();
    for(int i=0; i<proteins.get_size(); i++)
    {
        Protein p=proteins.get_elem(i);
        std::cout <<p.get_organism()<<" | "<<p.get_name()<<" | "<< p.get_sequence()<<"\n";
    }
}

void UI::show_sorted_ui() {
    std::string name;

    std::cout<<"Name: ";
    std::getline(std::cin, name);

    DynamicArray proteins = this->service.show_proteins_sorted(name);
    for(int i=0; i<proteins.get_size(); i++)
    {
        Protein p=proteins.get_elem(i);
        std::cout <<p.get_organism()<<" | "<<p.get_name()<<" | "<< p.get_sequence()<<"\n";
    }

}

void UI::run() {
    std::string line;
    int option;
    while(true) {
        menu();
        std::cout<<"Option: ";
        if (!(std::cin>>option)) {
            std::cout<<"Invalid option\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(option==0)
            break;
        switch(option) {
            case 1:
                add_ui();
                break;
            case 2:
                show_ui();
                break;
            case 3:
                show_sorted_ui();
                break;
            default:
                std::cout<<"Invalid option\n";
        }
    }
}