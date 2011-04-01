#include "gnufreecall.h"
#include "ui_gnufreecall.h"

#include <QtSvg>
#include <QtDebug>

QFileInfo fi("./");
QString PROJECT_PATH = fi.absolutePath();
QString PROJECT_AVATARS = PROJECT_PATH + "/avatars/";

/*TODO
* void GNUFreeCall::resizeEvent(QResizeEvent *event)
* Fix this functionality. When app is started logo is to small but when randomly resized logo would be a normal
*/
bool FIRST_RESIZE = true;
/**/

GNUFreeCall::GNUFreeCall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GNUFreeCall)
{
    ui->setupUi(this);

    connect(ui->buttonYou, SIGNAL(clicked()), this, SLOT(pageYou()));
    connect(ui->buttonFellowGNUs, SIGNAL(clicked()), this, SLOT(pageFollowGNUs()));
    connect(ui->buttonDiscoverHurd, SIGNAL(clicked()), this, SLOT(pageDiscoverHurd()));

    pageMain();
}

GNUFreeCall::~GNUFreeCall()
{
    delete ui;
}

void GNUFreeCall::resizeEvent(QResizeEvent *event)
{
    /*ReDraw logo when size is changed*/
    QWidget::resizeEvent(event);
    QGraphicsScene *scene = new QGraphicsScene();
    ui->videoView->setScene(scene);

    QSvgRenderer *renderer = new QSvgRenderer(PROJECT_AVATARS+"default.svg");
    QGraphicsSvgItem *svg_item = new QGraphicsSvgItem();
    svg_item->setSharedRenderer(renderer);
    scene->addItem(svg_item);

    /*
    *This is must be fixed. I think that it not a standard method.
    *For understanding where bug just remove "if" and "else" statements
    */
    if (!FIRST_RESIZE)
    {
        ui->videoView->fitInView(svg_item, Qt::KeepAspectRatio);
    }
    else
    {
        FIRST_RESIZE = false;
    }
    /**/
}

void GNUFreeCall::pageMain()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GNUFreeCall::pageYou()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GNUFreeCall::pageFollowGNUs()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GNUFreeCall::pageDiscoverHurd()
{
    ui->stackedWidget->setCurrentIndex(3);
}
