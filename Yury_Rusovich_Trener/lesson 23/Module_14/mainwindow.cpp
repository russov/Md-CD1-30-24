#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_8_clicked()
{
    // QLabel label;
    // label.setText("Test");
    // label.show();


    QLabel *label = new QLabel("Test");
    label->setAttribute(Qt::WA_DeleteOnClose);
    label->show();




    // Создаем новое окно
    // QWidget *newWindow = new QWidget();

    // // Устанавливаем заголовок окна
    // newWindow->setWindowTitle("New Window");

    // // Устанавливаем флаг для автоматического удаления при закрытии
    // newWindow->setAttribute(Qt::WA_DeleteOnClose);

    // // Создаем метку и устанавливаем её как дочерний элемент для нового окна
    // QLabel *label = new QLabel("Test", newWindow);

    // // Создаем макет для нового окна и добавляем в него метку
    // QVBoxLayout *layout = new QVBoxLayout();
    // layout->addWidget(label);
    // newWindow->setLayout(layout);

    // // Отображаем новое окно
    // newWindow->show();
}

