//
// Created by Maria on 06/07/2026.
//

#include <QApplication>

#include "gui/gui.h"
#include "repo/Repository.h"
#include "service/Service.h"

int main(int argc,char* argv[]) {
    QApplication app(argc,argv);
    Repository repo{"../chefs.txt","../recipes.txt"};
    Service service{repo};
    std::vector<GUI*> windows;
    for (const auto& c:service.getChefs()) {
        GUI* gui=new GUI{service,c};
        gui->show();
        windows.push_back(gui);
    }
    repo.save();
    return app.exec();
}
