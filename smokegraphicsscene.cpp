#include "smokegraphicsscene.h"

SmokeGraphicsScene::SmokeGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    this->createGrid();
}

void SmokeGraphicsScene::setGridOn(bool isOn)
{
    if (isOn) {

        //
        // Turn on grid
        //



    } else {

        //
        // Hide grid
        //
    }
}

void SmokeGraphicsScene::createGrid()
{
    int left = this->sceneRect().left();
    int right = this->sceneRect().right();
    int top = this->sceneRect().top();
    int bottom = this->sceneRect().bottom();

    for (int x = left; x < right; x+= 100)
    {
        grid.lines << QGraphicsLineItem(x, top, x, bottom, QPen(Qt::darkGray));
    }

    for (int y = top; y < bottom; y+= 100)
    {
        grid.lines << QGraphicsLineItem(x, top, x, bottom, QPen(Qt::darkGray));
    }

    //
    // Display some coord values
    //

    QFont font("Museo Slab", 8);
    for (int x = left; x < right; x+= 100) {
        for (int y = top; y < bottom; y+= 100) {

            QGraphicsSimpleTextItem* coordLabel =
                    QGraphicsSimpleTextItem(QString("%1,%2").arg(x).arg(y));
            coordLabel->setBrush(Qt::darkGray);
            coordLabel->setFont(font);
            coordLabel->setPos(x, y);

            grid.coordinates << coordLabel;
        }
    }
}
