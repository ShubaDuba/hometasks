#pragma once

#include <QMainWindow>
#include <QSignalMapper>

    enum Operation {
       EMPTY,
       PLUS,
       MINUS,
       MULT,
       DIV
    };

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void pressedDigit(int digit);
    void chooseOp(int tmpOperation);
    void pressedEqual();
    void clearAll();

private:
    QSignalMapper *digitMapper;
    QSignalMapper *opMapper;

    void init();

    Operation savedOperation = EMPTY;
    int count(int number_1, int number_2, Operation tmp);
    int savedArgument;
    bool operationPressed = false;
    bool argumentInserted = false;
    Ui::MainWindow *ui;
};
