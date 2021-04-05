/*!
*@file
*@brief the header file contains a description of the minewind class and the names of its methods
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <vector>
#include <map>
#include "Edge.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/**
 * @brief a class to describe and use the dialog window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT ///<

public:

    /**
     * @brief constructor a class mainwinow constructor
     * @param QWidget *parent = nullptr
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief  destructor a class mainwinow
     * @param QWidget *parent = nullptr
     */
    ~MainWindow();

private slots:

    /**
     * @brief checks if key was added to tree
     * @param key a key to check
     * @return true if key is in tree, else - false
     */
    bool DialogMessage(const std::string& quest, const std::string instruction);

    /**
     * @brief displays a button to select the operation
     */
    void ShowMenu();


    /**
     * @brief hides the buttons in the dialog box
     */
    void HideMenu();

    /**
     * @brief displays buttons and labels on the dialog box to create and edit a graph and run the algorithm visualization
     */
    void ShowLineEdit();

    /**
     * @brief hides buttons and labels on the dialog box to create and edit a graph and run the algorithm visualization
     */
    void HideLineEdit();

    /**
    *@ if two vertices and the length of the edge between them were entered in the labels, the "add edge" button is displayed on the window, otherwise nothing is displayed.
    */
    void ShowAddEdge();


    /**
    *@ displays a warning in the label if the edge of the graph was not entered correctly or it was not entered at all
    */
    void ShowErrors();

    /**
     * @brief hides the main menu and displays the label and line edit for enter for rib input with pattern int
     */
    void on_IntegerButton_clicked();


    /**
     * @brief returns the window to the main menu
     */
    void on_BackButton_clicked();

    /**
     * @brief hides the main menu and displays the label and line edit for enter for rib input with pattern double
     */
    void on_DoubleButton_clicked();


    /**
     * @brief displays a message box that asks if the user wants to exit the program
     */
    void on_ExitButton_clicked();

    /**
     * @brief checks the correctness of the input of the first vertex of the edge of the graph and highlights it in red if it was entered incorrectly
     * @param arg1 - name of first vertex rib
     */
    void on_EnterStartPoint_textEdited(const QString &arg1);

    /**
     * @brief checks the correctness of the input of the second vertex of the edge of the graph and highlights it in red if it was entered incorrectly
     * @param arg1 - name of second vertex rib
     */
    void on_EnterFinishPoint_textEdited(const QString &arg1);


    /**
     * @brief checks the correctness of the input of the edge length of the graph with the pattern double and highlights it in red if it was entered incorrectly
     * @param arg1 - length of rib with pattern double
     */
    void on_EnterWeightDouble_textEdited(const QString &arg1);

    /**
     * @brief checks the correctness of the input of the edge length of the graph with the pattern int and highlights it in red if it was entered incorrectly
     * @param arg1 - length of rib with pattern int
     */
    void on_EnterWeightInt_textEdited(const QString &arg1);

    /**
     * @brief when you press the add edge button, it adds the entered edge to the graph
     */
    void on_ButtonAddEdge_clicked();

    /**
     * @brief when you click on the "show graph" button, if type pattern - int calls the method ShowGraphEdgesInt else alls the method ShowGraphEdgesDouble for visalisation algorithm
     */
    void on_ShowGraphButton_clicked();

private:
    Ui::MainWindow *ui;
    bool start_ok = false;
    bool finish_ok = false;
    bool weight_ok = false;
    QString start_error;
    QString finish_error;
    QString weight_error;
    QString type;

   std::vector<Edge<int>> edge_int;

   std::vector<Edge<double>> edge_double;



};
#endif // MAINWINDOW_H
