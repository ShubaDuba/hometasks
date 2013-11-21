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
    void pressedSignChange();
    void pressedPoint();
    void pressedEqual();
    void clearAll();

private:
    QSignalMapper *digitMapper;
    QSignalMapper *opMapper;

    void init();

    Operation savedOperation;
    double count(double num_1, double num_2, Operation tmp);
    double savedArgument;
    bool operationPressed;
    bool argumentInserted;
    bool pointPressed;
    bool equalPressed;
    Ui::MainWindow *ui;
};
