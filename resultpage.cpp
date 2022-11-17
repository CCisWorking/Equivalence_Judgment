#include "resultpage.h"
#include "ui_resultpage.h"

ResultPage::ResultPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultPage)
{
    ui->setupUi(this);
//    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开文件"),
//            "", tr("file(*.csv)"));
    ui->eq->setColumnCount(2);
    ui->eq->setRowCount(100);
    QFile file("/Users/cc/Desktop/equal.csv");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream  in(&file);
    QString line;
    QStringList fields;
    int row  = 0;
    while(!in.atEnd()){
        line = in.readLine();
        fields = line.split(',');
        for(int column = 0; column<fields.size();column++){
            ui->eq->setItem(row, column, new QTableWidgetItem(fields[column]));
        }
        row++;
    }
    QStringList headers;
    headers << QStringLiteral("file1") << QStringLiteral("file2");
    ui->eq->setHorizontalHeaderLabels(headers);
    ui->eq->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->eq->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->eq->resizeColumnToContents(10);
    ui->eq->update();

    ui->neq->setColumnCount(2);
    ui->neq->setRowCount(100);
    QFile file2("/Users/cc/Desktop/inequal.csv");
    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream  in2(&file2);
    QString line2;
    QStringList fields2;
    int row2  = 0;
    while(!in2.atEnd()){
        line2 = in2.readLine();
        fields2 = line2.split(',');
        for(int column = 0; column<fields.size();column++){
            ui->neq->setItem(row2, column, new QTableWidgetItem(fields[column]));
        }
        row2++;
    }
    QStringList headers2;
    headers << QStringLiteral("file1") << QStringLiteral("file2");
    ui->neq->setHorizontalHeaderLabels(headers);
    ui->neq->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->neq->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->neq->resizeColumnToContents(10);
    ui->neq->update();
}

ResultPage::~ResultPage()
{
    delete ui;
}

void ResultPage::on_CloseBtn_clicked()
{
    this->close();
}

