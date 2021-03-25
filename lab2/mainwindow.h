#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "graph_algorithm/edge.h"

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
    bool DialogMessage(const std::string& quest, const std::string instruction);

    void ShowMenu();

    void HideMenu();

    void ShowLineEdit();

    void HideLineEdit();

    void ShowAddEdge();

    void on_IntegerButton_clicked();

    void on_BackButton_clicked();

    void on_DoubleButton_clicked();

    void on_StringButton_clicked();

    void on_ExitButton_clicked();

    void on_EnterStartPoint_textEdited(const QString &arg1);

    void on_EnterFinishPoint_textEdited(const QString &arg1);

    void on_EnterWeightString_textEdited(const QString &arg1);

    void on_EnterWeightDouble_textEdited(const QString &arg1);

    void on_EnterWeightInt_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool start_ok = false;
    bool finish_ok = false;
    bool weight_ok = false;
};
#endif // MAINWINDOW_H
