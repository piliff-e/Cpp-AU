//
// Created by Филипп Евдокимов on 05.04.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "Genetic_main.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(run()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::run() {
    Genetic_main();
}
