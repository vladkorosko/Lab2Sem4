#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void HideMenu();
    void ShowMenu();
    void on_IntegerButton_clicked();

    void on_BackButton_clicked();

    void on_DoubleButton_clicked();

    void on_StringButton_clicked();

    //void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
