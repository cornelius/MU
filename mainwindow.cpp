#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->output->setFont( QFont( "Courier", 20, QFont::Bold ) );

    connect( ui->start, SIGNAL( clicked() ), SLOT( start() ) );

    connect( new QShortcut( Qt::Key_0, this ), SIGNAL( activated() ), SLOT( start() ) );

    connect( ui->applyOne, SIGNAL( clicked() ), SLOT( applyOne() ) );
    connect( ui->applyTwo, SIGNAL( clicked() ), SLOT( applyTwo() ) );
    connect( ui->applyThree, SIGNAL( clicked() ), SLOT( applyThree() ) );
    connect( ui->applyFour, SIGNAL( clicked() ), SLOT( applyFour() ) );

    connect( new QShortcut( Qt::Key_1, this ), SIGNAL( activated() ), SLOT( applyOne() ) );
    connect( new QShortcut( Qt::Key_2, this ), SIGNAL( activated() ), SLOT( applyTwo() ) );
    connect( new QShortcut( Qt::Key_3, this ), SIGNAL( activated() ), SLOT( applyThree() ) );
    connect( new QShortcut( Qt::Key_4, this ), SIGNAL( activated() ), SLOT( applyFour() ) );

    start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    ui->output->clear();
    addLine( "MI" );
    selectLastLine();
}

void MainWindow::applyOne()
{
    if ( lastLine().endsWith("I") ) {
        addLine( lastLine() + "U" );
    }
    selectLastLine();
}

void MainWindow::applyTwo()
{
    addLine( lastLine() + lastLine().mid( 1 ) );
    selectLastLine();
}

void MainWindow::applyThree()
{
    for( int i = 0; i < lastLine().length() - 2; ++i ) {
        if ( lastLine().mid( i, 3 ) == "III" ) {
            addLine( lastLine().left( i ) + "U" + lastLine().mid( i + 3 ) );
        }
    }
    selectLastLine();
}

void MainWindow::applyFour()
{
    QString result;
    QString lastResult;
    for( int i = 0; i < lastLine().length() - 1; ++i ) {
        if ( lastLine().mid( i, 2 ) == "UU" ) {
            result = lastLine().left( i ) + lastLine().mid( i + 2 );
            if ( result != lastResult ) {
                addLine( result );
                lastResult = result;
            }
        }
    }
    selectLastLine();
}

void MainWindow::addLine( const QString &line )
{
    ui->output->addItem( line );
    ui->output->scrollToBottom();
}

QString MainWindow::lastLine() const
{
    return ui->output->currentItem()->text();
}

void MainWindow::selectLastLine()
{
    ui->output->setCurrentItem( ui->output->item( ui->output->count() - 1 ) );
}
