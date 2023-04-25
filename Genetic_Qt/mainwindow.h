//
// Created by Филипп Евдокимов on 05.04.2023.
//

#ifndef GENETIC_QT__MAINWINDOW_H_
#define GENETIC_QT__MAINWINDOW_H_

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    private slots:
    void run();

 private:
    Ui::MainWindow *ui;
};

#endif //GENETIC_QT__MAINWINDOW_H_
