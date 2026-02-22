#ifndef LASKIN_H
#define LASKIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Laskin; }
QT_END_NAMESPACE

class Laskin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Laskin(QWidget *parent = nullptr);
    ~Laskin();

private:
    enum class Op { None, Add, Sub, Mul, Div };

    Ui::Laskin *ui;

    QString number1;
    QString number2;

    int state = 1;          // 1 = syötetään number1, 2 = syötetään number2
    Op operand = Op::None;

    void numberClickedHandler();
    void addSubMulDivClickHandler();
    void clearAndEnterClickHandler();

    void resetLineEdits();
    void resetAll();

    bool calculate(float &outResult) const;
};

#endif // LASKIN_H
