#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include <QMouseEvent>

class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    MyComboBox(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(bool);
};

#endif // MYCOMBOBOX_H
