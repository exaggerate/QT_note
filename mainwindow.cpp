#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("new.txt ---------------------------weti");
    QObject::connect(ui->newAction,SIGNAL(triggered()),this,SLOT(newFileSlot()));
    QObject::connect(ui->openAction,SIGNAL(triggered()),this,SLOT(openFileSlot()));
    QObject::connect(ui->saveAction,SIGNAL(triggered()),this,SLOT(saveFileSlot()));
    QObject::connect(ui->anthorAction,SIGNAL(triggered()),this,SLOT(saveAsFileSlot()));
    QObject::connect(ui->fontAction,SIGNAL(triggered()),this,SLOT(setFontSlot()));
    QObject::connect(ui->colorAction,SIGNAL(triggered()),this,SLOT(setColorSlot()));
    QObject::connect(ui->datatimeAction,SIGNAL(triggered()),this,SLOT(getTimeSlot()));

    //function
    QObject::connect(ui->exitAction,SIGNAL(triggered()),ui->textEdit,SLOT(close()));
    QObject::connect(ui->undoACtion,SIGNAL(triggered()),ui->textEdit,SLOT(undo()));
    QObject::connect(ui->pasteAction,SIGNAL(triggered()),ui->textEdit,SLOT(paste()));
    QObject::connect(ui->redoAction,SIGNAL(triggered()),ui->textEdit,SLOT(redo()));
    QObject::connect(ui->cutAction,SIGNAL(triggered()),ui->textEdit,SLOT(cut()));
    QObject::connect(ui->selectAction,SIGNAL(triggered()),ui->textEdit,SLOT(selectAll()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newFileSlot()
{

    if(ui->textEdit->document()->isModified()){
        //qDebug()<<"current file changed";
       // QMessageBox::information(this,"information","GG");
        this->setWindowTitle("Untitled.txt ----------------------weti");
    }
    else
    {
        //qDebug()<<"no modefilited";
        ui->textEdit->clear();
    }
}
void MainWindow::openFileSlot(){
    saveName=QFileDialog::getOpenFileName(this,"Open File",QDir::currentPath());
 //   qDebug()<<"name:"<<saveName;
//    if(filename.isEmpty()){
//        QMessageBox::information(this,"Error Message","the filename is empty!!");
//        return;
//    }
    this->setWindowTitle(saveName+" -------weti");
    QFile *file=new QFile;
    file->setFileName(saveName);
    bool ok=file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);
        ui->textEdit->setText(in.readAll());
        file->close();
        delete file;
    }
    else{
        QMessageBox::information(this,"Error Message","the filename is empty!!");
        return;
    }
}

void MainWindow::saveFileSlot()
{
  if(saveName.isEmpty())
  {
      this->saveAsFileSlot();
  }
  else
  {
      QFile *file=new QFile;
      file->setFileName(saveName);
      bool ok=file->open(QIODevice::WriteOnly);
      if(ok)
      {
         QTextStream out(file);
         out<<ui->textEdit->toPlainText();
         file->close();
         delete file;
      }
      else{
          QMessageBox::information(this,"Error Message","the filename is empty!!");
          return;
      }
  }
}

void MainWindow::saveAsFileSlot()
{
    QString filename=QFileDialog::getSaveFileName(this,"save file",QDir::currentPath(),tr("TXT files (*.txt);;HTML-Files "
                                                                                         "(*.htm *.html);;All Files (*)"));
    if(filename.isEmpty())
    {
        QMessageBox::information(this,"Error Message","the filename is empty!!");
        return;
    }
    QFile *file=new QFile;
    file->setFileName(filename);
    //qDebug()<<"get:1";
    bool ok=file->open(QIODevice::WriteOnly);
    if(ok)
    {
       QTextStream out(file);
       out<<ui->textEdit->toPlainText();
       file->close();
       delete file;
    }
    else{
        QMessageBox::information(this,"Error Message","the filename is empty!!");
        return;
    }
}

void MainWindow::printfFileSlot()
{
    //Qstring printf status  memory;
}

void MainWindow::setFontSlot()
{
    //get font
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        // the user clicked OK and font is set to the font the user selected
        ui->textEdit->setFont(font);
    } else {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Helvetica [Cronyx], 10
        QMessageBox::information(this,"Error Message","the filename is empty!!");
        return;
    }
}

void MainWindow::setColorSlot()
{
    QColor color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
        QMessageBox::information(this,"Error Message","color is unvailed!");
        return;
    }
}

void MainWindow::getTimeSlot()
{
    QDateTime current=QDateTime::currentDateTime();
    QString time=current.toString("dddd, yyyy M d hh:mm:ss");
    ui->textEdit->append(time);
}























