#include "../ui/ui.h"
#include <iostream>
#include <string>
#include <limits>

UI::UI(const Service& s) : service{s} {}

// admin functionalities
void UI::menu() {
    std::cout << "1. Add new trench coat\n";
    std::cout<< "2. Delete trench coat\n";
    std::cout<< "3. Update info\n";
    std::cout<< "4. Display all coats\n";
    std::cout<< "0. Exit\n";
}

void UI::add_coat_ui() {
    std::string size, colour, photo;
    double price;
    int quantity;

    std::cout << "Size: ";
    std::getline(std::cin, size);
    std::cout << "Colour: ";
    std::getline(std::cin, colour);
    std::cout << "Price: ";
    if(!(std::cin >> price)) {
        std::cout<<"Invalid price\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << "Quantity: ";
    if(!(std::cin >> quantity)) {
        std::cout<<"Invalid quantity\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Photo: ";
    std::getline(std::cin, photo);

    if (Validation::validate_add_input(size, colour,price,quantity,photo)) {
        Coat c{size, colour, price, quantity, photo};
        if(this->service.add_coat(c))
            std::cout << "Coat added successfully\n";
        else
            std::cout << "Coat already exists\n";
    }
    else {
        std::cout<<"Invalid input\n";
    }
}

void UI::delete_coat_ui() {
    std::string size, colour;
    std::cout<<"Size: ";
    std::getline(std::cin, size);
    std::cout<<"Colour: ";
    std::getline(std::cin, colour);

    if(Validation::validate_delete_input(size,colour)==true) {
        if(this->service.delete_coat(size, colour))
            std::cout << "Coat deleted successfully\n";
        else
            std::cout << "Coat does not exist\n";
    }
    else {
        std::cout<<"Invalid input\n";
    }
}

void UI::update_coat_ui() {
    std::string size, colour, new_photo;
    double new_price;
    int new_quantity;

    std::cout << "Size of coat to update: ";
    std::getline(std::cin, size);
    std::cout << "Colour of coat to update: ";
    std::getline(std::cin, colour);

    std::cout << "New price: ";
    if (!(std::cin >> new_price)) {
        std::cout << "Invalid price\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << "New quantity: ";
    if (!(std::cin >> new_quantity)) {
        std::cout << "Invalid quantity\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "New photo: ";
    std::getline(std::cin, new_photo);

    if (Validation::validate_update_input(size,colour,new_price,new_quantity,new_photo)) {
        Coat c{size, colour, new_price, new_quantity, new_photo};
        if(this->service.update_coat(c))
            std::cout << "Coat updated successfully\n";
        else
            std::cout << "Coat does not exist\n";
    }
    else {
        std::cout<<"Invalid input\n";
    }
}

void UI::display_coat_ui() {
    DynamicVector<Coat> allCoats = this->service.get_all();
    for (int i=0; i<allCoats.get_size(); i++) {
        Coat c = allCoats.get_elem(i);
        std::cout << "Size: " << c.get_size()
                  << ", Colour: " << c.get_colour()
                  << ", Price: " << c.get_price()
                  << ", Quantity: " << c.get_quantity()
                  << ", Photo: " << c.get_photo() << "\n";
    }
}


// user functionalities

void UI::user_menu() {
    std::cout<<"1. See coats by size\n";
    std::cout<<"2. See shopping basket\n";
    std::cout<<"0. Exit\n";
}

void UI::see_coats_ui() {
    std::string size;
    std::cout<<"Give size (leave empty for all): ";
    std::getline(std::cin, size);

    DynamicVector<Coat> filtered_coats;

    filtered_coats = this->service.get_coats_by_size(size);
    if (filtered_coats.get_size() == 0)
    {
        std::cout<<"No coats found.\n";
        return;
    }
    int i=0;
    bool first = true;
    while(true)
    {
        Coat c = filtered_coats.get_elem(i);
        // open photo of first coat in browser
        if (first) {
            std::string command = "open \"" + c.get_photo() + "\"";
            system(command.c_str());    
            first = false;
        }
        std::cout<<"\nShowing coat "<<i+1<<" of "<<filtered_coats.get_size()<<"\n";
        std::cout<<"Size: "<<c.get_size()
                 <<" | Colour: "<<c.get_colour()
                 <<" | Price: "<<c.get_price()
                 <<" | Quantity: "<<c.get_quantity()<<"";
        // std::cout<<"Photo: "<<c.get_photo()<<"\n";
        std::cout<<"\n1. Add to basket\n2. Next\n0. Stop browsing\nYour option: ";
        int opt;
        if(!(std::cin>>opt)) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(opt==1)
        {
            this->service.add_to_basket(c);
            std::cout<<"Added! Total: "<< this->service.get_total()<<"\n";
        }
        else if (opt==2)
        {
            i++;
            if(i==filtered_coats.get_size())
                i=0;
        }
        else if (opt==0)
        {
            break;
        }
    }
}

void UI::add_to_basket_ui() {
    DynamicVector<Coat> basket = this->service.get_basket();
    if(basket.get_size()==0)
    {
        std::cout<<"Basket is empty.\n";
        return;
    }
    for(int i=0; i<basket.get_size(); i++)
    {
        Coat c = basket.get_elem(i);
        std::cout<<c.get_size()<<" "<<c.get_colour()<<" - "<<c.get_price()<<"\n";
    }
    std::cout<<"Total: "<< this->service.get_total()<<"\n";
}

void UI::total_ui() {
    std::cout<<"Current total: "<< this->service.get_total() <<"\n";
}

void UI::runApplication() {
    int mode;
    while(true)
    {
        std::cout<<"Admin mode (1) or User mode (2)? ";
        std::cout<<"Your option: ";
        if (!(std::cin >> mode))
        {
            std::cout << "Invalid input! Please enter a number (1 or 2).\n";
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove bad input from buffer
            continue; // Try again
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(mode==1 || mode==2)
        {
            break;
        }
        else
        {
            std::cout<<"Invalid mode! Please choose 1 for Admin or 2 for User. \n";
        }
    }
    if (mode==1)
    {
        int option;
        while(true) 
        {
            std::cout<<"Welcome Admin mode!\n";
            menu();
            std::cout<<"Your option: ";
            if (!(std::cin >> option)) {
                std::cout << "Invalid option\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (option == 0)
                break;
            switch(option) {
                case 1:
                    add_coat_ui();
                    break;
                case 2:
                    delete_coat_ui();
                    break;
                case 3:
                    update_coat_ui();
                    break;
                case 4:
                    display_coat_ui();
                    break;
                default:
                    std::cout<<"Invalid option\n";
                    continue;
            }
        }   
    }
    else if (mode==2)
    {
        int optionn;
        while(true) 
        {
            std::cout<<"Welcome User mode!\n";
            user_menu();
            std::cout<<"Your option: ";
            if (!(std::cin >> optionn)) {
                std::cout << "Invalid option\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (optionn == 0)
                break;
            switch(optionn) {
                case 1:
                    see_coats_ui();
                    break;
                case 2:
                    add_to_basket_ui();
                    break;
                case 3:
                    total_ui();
                    break;
                default:
                    std::cout<<"Invalid option\n";
                    continue;
            }
        }   
    }
    else {
        std::cout<<"Invalid mode.\n";
    }
}