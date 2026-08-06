//
// Created by Maria on 07/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_All.h" resolved

#include "all.h"
#include "ui_All.h"
#include <QPainter>

All::All(Service& service,const Chef& chef,QWidget *parent) :
    QWidget(parent), ui(new Ui::All),service{service},chef{chef} {
    ui->setupUi(this);
    service.registerObserver(this);
    All::update();
}

All::~All() {
    service.unregisterObserver(this);
    delete ui;
}

void All::update() {
    repaint();
}

void All::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    int x=30;
    int y=30;
    auto recipes=service.getRecipesInCuisine(chef);
    for (const auto& r:recipes) {
        int time=r.getTime();
        if (time>100)
            painter.setBrush(Qt::red);
        painter.drawText(x,y,QString::fromStdString(r.getName()));
        painter.drawRect(x+150,y-15,2*time,20);
        y +=30;
    }
}
