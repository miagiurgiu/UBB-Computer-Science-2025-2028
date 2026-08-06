//
// Created by Maria on 06/07/2026.
//

#ifndef PRACTICALEXAM_RETAKE_MIAGIURGIU_GUI_H
#define PRACTICALEXAM_RETAKE_MIAGIURGIU_GUI_H

#include <QWidget>

#include "all.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget,public Observer {
Q_OBJECT

public:
    explicit GUI(Service& service,const Chef& chef,QWidget *parent = nullptr);
    ~GUI() override;
    void update() override;

private:
    Ui::GUI *ui;
    Service& service;
    Chef chef;
    //All* window;
    void connectSignalsAndSlots();
    void populateList();
    void add();
    void view();
    void filter();
};


#endif //PRACTICALEXAM_RETAKE_MIAGIURGIU_GUI_H
