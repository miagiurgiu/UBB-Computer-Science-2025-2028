//
// Created by Maria on 07/07/2026.
//

#ifndef PRACTICALEXAM_RETAKE_MIAGIURGIU_ALL_H
#define PRACTICALEXAM_RETAKE_MIAGIURGIU_ALL_H

#include <QWidget>

#include "domain/Observer.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class All; }
QT_END_NAMESPACE

class All : public QWidget,public Observer {
Q_OBJECT

public:
    explicit All(Service& service,const Chef& chef,QWidget *parent = nullptr);
    ~All() override;
    void update() override;
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::All *ui;
    Service& service;
    Chef chef;
};


#endif //PRACTICALEXAM_RETAKE_MIAGIURGIU_ALL_H
