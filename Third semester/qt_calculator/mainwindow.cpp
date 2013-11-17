#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pressedDigit(int digit)
{
    if (ui->lineEdit->text() == "0")
    {
        ui->lineEdit->clear();
    }

    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digit));
    argumentInserted = true;
    ui->label->clear();
}

void MainWindow::chooseOp(int tmpOperation)
{
    if (argumentInserted)
    {
        switch (tmpOperation)
        {
        case 1:
            savedOperation = PLUS;
            break;
        case 2:
            savedOperation = MINUS;
            break;
        case 3:
            savedOperation = MULT;
            break;
        case 4:
            savedOperation = DIV;
            break;
        }

        operationPressed = true;
        savedArgument = ui->lineEdit->text().toInt();
        ui->lineEdit->clear();
        ui->label->clear();
        argumentInserted = false;
    }
}

void MainWindow::pressedEqual()
{
    if (operationPressed && argumentInserted)
    {
        ui->lineEdit->setText(QString::number(count(savedArgument,
                                                    ui->lineEdit->text().toInt(),
                                                    savedOperation)));
        savedArgument = 0;
        savedOperation = EMPTY;
        operationPressed = false;
    }
}

void MainWindow::clearAll()
{
    ui->lineEdit->clear();
    savedArgument = 0;
    savedOperation = EMPTY;
    operationPressed = false;
    ui->label->clear();
}

void MainWindow::init()
{
    digitMapper = new QSignalMapper (this);

    connect(ui->toolButton_0, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_0, 0);
    connect(ui->toolButton_1, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_1, 1);
    connect(ui->toolButton_2, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_2, 2);
    connect(ui->toolButton_3, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_3, 3);
    connect(ui->toolButton_4, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_4, 4);
    connect(ui->toolButton_5, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_5, 5);
    connect(ui->toolButton_6, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_6, 6);
    connect(ui->toolButton_7, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_7, 7);
    connect(ui->toolButton_8, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_8, 8);
    connect(ui->toolButton_9, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->toolButton_9, 9);
    connect(digitMapper, SIGNAL(mapped(int)),
            this, SLOT(pressedDigit(int)));

    opMapper = new QSignalMapper (this);

    connect(ui->multiplicate, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->multiplicate, 3);
    connect(ui->divide, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->divide, 4);
    connect(ui->plus, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->plus, 1);
    connect(ui->minus, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->minus, 2);
    connect(opMapper, SIGNAL(mapped(int)),
            this, SLOT(chooseOp(int)));

    connect(ui->C, SIGNAL(clicked()), this, SLOT(clearAll()));
    connect(ui->equal, SIGNAL(clicked()), this ,SLOT(pressedEqual()));
}

int MainWindow::count(int number_1, int number_2, Operation tmp)
{
    switch (tmp)
    {
    case EMPTY:
        return 0;
        break;
    case PLUS:
        return number_1 + number_2;
        break;
    case MINUS:
        return number_1 - number_2;
        break;
    case MULT:
        return number_1 * number_2;
        break;
    case DIV:
        if (number_2 == 0)
        {
            ui->label->setText("Division by zero.");
            return 0;
        }
        else{
            return number_1 / number_2;
        }
        break;
    }
    return 0;
}
