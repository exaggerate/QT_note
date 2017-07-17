#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDir>
#include <QColor>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QDateTime>
#include <QPlainTextEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString saveName;
private slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void saveAsFileSlot();
    void printfFileSlot();
    void setFontSlot();
    void setColorSlot();
    void getTimeSlot();
};

#endif // MAINWINDOW_H
