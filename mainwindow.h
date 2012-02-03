#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addLine( const QString & );
    QString lastLine() const;

    void selectLastLine();

public slots:
    void applyOne();
    void applyTwo();
    void applyThree();
    void applyFour();

    void start();
    
private:
    Ui::MainWindow *ui;
};

#endif
