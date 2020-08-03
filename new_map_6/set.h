#ifndef SET_H
#define SET_H

#include <QWidget>

namespace Ui {
class Set;
}

class Set : public QWidget
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = 0);
    ~Set();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

signals:
    void sure();

private:
    Ui::Set *ui;
};

#endif // SET_H
