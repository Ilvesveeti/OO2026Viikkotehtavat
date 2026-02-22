#include "laskin.h"
#include "ui_laskin.h"

#include <QPushButton>
#include <QDebug>

Laskin::Laskin(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::Laskin)
{
    ui->setupUi(this);
    resetAll();

    for (int i = 0; i <= 9; ++i) {
        const QString name = "N" + QString::number(i);
        if (auto *btn = findChild<QPushButton*>(name)) {
            connect(btn, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
        } else {
            qDebug() << "Missing button:" << name;
        }
    }

    
    connect(ui->add, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);

    
    connect(ui->clear, &QPushButton::clicked, this, &Laskin::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &Laskin::clearAndEnterClickHandler);
}

Laskin::~Laskin()
{
    delete ui;
}

void Laskin::resetLineEdits()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}

void Laskin::resetAll()
{
    number1.clear();
    number2.clear();
    state = 1;
    operand = Op::None;
    resetLineEdits();
}

void Laskin::numberClickedHandler()
{
    auto *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    const QString digit = button->text(); 

    if (state == 1) {
        number1 += digit;
        ui->num1->setText(number1);
    } else { 
        number2 += digit;
        ui->num2->setText(number2);
    }

    qDebug() << "num1:" << number1 << "num2:" << number2;
}

void Laskin::addSubMulDivClickHandler()
{
    auto *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    
    if (number1.isEmpty()) return;

    if (button == ui->add) operand = Op::Add;
    else if (button == ui->sub) operand = Op::Sub;
    else if (button == ui->mul) operand = Op::Mul;
    else if (button == ui->div) operand = Op::Div;
    else operand = Op::None;

    state = 2;
}

bool Laskin::calculate(float &outResult) const
{
    if (operand == Op::None) return false;
    if (number1.isEmpty() || number2.isEmpty()) return false;

    bool ok1 = false, ok2 = false;
    const float n1 = number1.toFloat(&ok1);
    const float n2 = number2.toFloat(&ok2);
    if (!ok1 || !ok2) return false;

    switch (operand) {
    case Op::Add: outResult = n1 + n2; return true;
    case Op::Sub: outResult = n1 - n2; return true;
    case Op::Mul: outResult = n1 * n2; return true;
    case Op::Div:
        if (n2 == 0.0f) return false;
        outResult = n1 / n2;
        return true;
    default:
        return false;
    }
}

void Laskin::clearAndEnterClickHandler()
{
    auto *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (button == ui->clear) {
        resetAll();
        return;
    }

 
    float res = 0.0f;
    const bool ok = calculate(res);

    if (!ok) {ä
        ui->result->setText("Error");
        return;
    }

    ui->result->setText(QString::number(res));

    number1 = QString::number(res);
    number2.clear();
    ui->num1->setText(number1);
    ui->num2->clear();

    operand = Op::None;
    state = 2; 

