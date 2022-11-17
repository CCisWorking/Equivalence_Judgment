#ifndef RESULTPAGE_H
#define RESULTPAGE_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>

namespace Ui {
class ResultPage;
}

class ResultPage : public QWidget
{
    Q_OBJECT

public:
    explicit ResultPage(QWidget *parent = nullptr);
    ~ResultPage();

private slots:
    void on_CloseBtn_clicked();

private:
    Ui::ResultPage *ui;
};

#endif // RESULTPAGE_H
