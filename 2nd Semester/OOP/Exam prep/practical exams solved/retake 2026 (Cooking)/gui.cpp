//
// Created by Maria on 06/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QPushButton>
#include <QMessageBox>

GUI::GUI(Service& service,const Chef& chef,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},chef{chef} {
    ui->setupUi(this);
    service.registerObserver(this);
    this->setWindowTitle(QString::fromStdString(chef.getName()));
    connectSignalsAndSlots();
    GUI::update();
}

GUI::~GUI() {
    service.unregisterObserver(this);
    delete ui;
}

void GUI::update() {
    populateList();
}

void GUI::connectSignalsAndSlots() {
    connect(ui->checkBox,&QCheckBox::toggled,this,&GUI::populateList);
    connect(ui->addButton,&QPushButton::clicked,this,&GUI::add);
    connect(ui->viewButton,&QPushButton::clicked,this,&GUI::view);
    connect(ui->searchLineEdit,&QLineEdit::textChanged,this,&GUI::filter);
    //connect(ui->recipesListWidget,&QListWidget::currentTextChanged,this,&GUI::populateList);
}

void GUI::populateList() {
    std::vector<Recipe> recipes;
    ui->recipesListWidget->clear();
    if (ui->checkBox->isChecked()) {
        recipes=service.getSpecialisedRecipes(chef.getSpeciality());
    }
    else {
        recipes=service.getRecipesSorted();
    }
    /*
    std::string text=ui->searchLineEdit->text().toStdString();
    if (!text.empty()) {
        recipes=service.filter(text);
    }
    */
    for (const auto& r:recipes) {
        //std::string text=r.getName()+";"+r.getCuisine()+";"+std::to_string(r.getTime())+";";
        ui->recipesListWidget->addItem(QString::fromStdString(r.toString()));
    }
}

void GUI::add() {
    std::string name=ui->nameLineEdit->text().toStdString();
    int time=ui->timeLineEdit->text().toInt();
    std::string ingredients=ui->ingredientsLineEdit->text().toStdString();
    try {
        service.add(name,chef.getSpeciality(),time,ingredients);
        ui->nameLineEdit->clear();
        ui->timeLineEdit->clear();
        ui->ingredientsLineEdit->clear();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this,"ERROR",e.what());
    }
}

void GUI::view() {
    /*
    QWidget* window=new QWidget{};
    window->show();
    */

    /*
    auto window=new All{service,this};
    window->show();
    */

    auto window=new All{service,chef};
    window->show();
}

void GUI::filter() {
    std::string text=ui->searchLineEdit->text().toStdString();
    if (!text.empty()) {
        //ui->recipesListWidget->clear();
        auto filteredRecipes=service.filter(text);
        ui->testLabel->setText(QString::fromStdString("Filter works!"));
        /*
        for (const auto& r:filteredRecipes) {
            ui->recipesListWidget->addItem(QString::fromStdString(r.toString()));
        }
        */
    }
}
