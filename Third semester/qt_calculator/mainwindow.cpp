#include "mainwindow.h"
#include "ui_mainwindow.h"

const int ZERO = 0;
const double REVERSE = -1;
const int MYPREC = 17;

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
        savedArgument = ui->lineEdit->text().toDouble();
        ui->lineEdit->clear();
        ui->label->clear();
        argumentInserted = false;
    }
}

void MainWindow::pressedSignChange()
{
    ui->lineEdit->setText(QString::number(REVERSE * ui->lineEdit->text().toDouble(), 'g', MYPREC));
}

void MainWindow::pressedPoint()
{
    if (equalPressed)
    {
        clearAll();
    }

    if (!pointPressed)
    {
        if (ui->lineEdit->text() == '\0')
        {
            ui->lineEdit->setText("0");
        }
        ui->lineEdit->setText(ui->lineEdit->text() + '.');
        pointPressed = true;
    }
}

void MainWindow::pressedEqual()
{
    if (operationPressed && argumentInserted)
    {
        ui->lineEdit->setText(QString::number(count(savedArgument,
                                                    ui->lineEdit->text().toDouble(),
                                                    savedOperation),
                                              'g',
                                              MYPREC));
        savedArgument = ZERO;
        savedOperation = EMPTY;
        operationPressed = false;
        pointPressed = false;
        equalPressed = true;
    }
}

void MainWindow::clearAll()
{
    ui->lineEdit->clear();
    savedArgument = ZERO;
    savedOperation = EMPTY;
    operationPressed = false;
    pointPressed = false;
    equalPressed = true;
    ui->label->clear();
}

void MainWindow::init()
{
    savedOperation = EMPTY;
    operationPressed = false;
    argumentInserted = false;
    pointPressed = false;
    equalPressed = false;
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
    connect(ui->equal, SIGNAL(clicked()), this , SLOT(pressedEqual()));
    connect(ui->signChange, SIGNAL(clicked()), this, SLOT(pressedSignChange()));
    connect(ui->pointAdd, SIGNAL(clicked()), this, SLOT(pressedPoint()));
}

double MainWindow::count(double num_1, double num_2, Operation tmp)
{
    switch (tmp)
    {
    case EMPTY:
        return ZERO;
        break;
    case PLUS:
        return num_1 + num_2;
        break;
    case MINUS:
        return num_1 - num_2;
        break;
    case MULT:
        return num_1 * num_2;
        break;
    case DIV:
        if (num_2 == ZERO)
        {
            ui->label->setText("Division by zero.");
            return ZERO;
        }
        else{
            return num_1 / num_2;
        }
        break;
    }
    return ZERO;
}
