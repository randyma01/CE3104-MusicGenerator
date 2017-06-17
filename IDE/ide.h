#ifndef IDE_H
#define IDE_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFileDialog>
#include <QtGui>
#include <QDockWidget>

#include <QGraphicsPixmapItem>
#include <QImage>
#include <QGraphicsScene>

#include <string>
#include <vector>
#include <iostream>
#include <fstream>


namespace Ui {
class IDE;
}

class IDE : public QMainWindow
{
    Q_OBJECT

public:
    explicit IDE(QWidget *parent = 0);
    ~IDE();
    //void keyPressEvent(QKeyEvent *e);

    bool eventFilter(QObject *watched, QEvent *event);

    void insertKeywords(QString words, QTextCursor cursors, std::string color);



private slots:
    void veryKeywords();
    void on_actionCompile_triggered();

    void on_actionrun_triggered();




    void on_action_Connection_triggered();

    void on_actionView_Console_triggered();

    void on_actionOpen_triggered();

    void on_actionMusic_Sheet_triggered();

    void on_actionSave_File_triggered();

private:
    Ui::IDE *ui;
};


#endif // IDE_H
