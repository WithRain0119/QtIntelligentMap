#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtIntelligentMap.h"
#include "BFSTRAVERSE.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtIntelligentMapClass; };
QT_END_NAMESPACE

class QtIntelligentMap : public QWidget
{
    Q_OBJECT

public:
    QtIntelligentMap(QWidget *parent = nullptr);
    ~QtIntelligentMap();
    void InitUI();

    void initRoadLines();
    void setRoadColor(char roadName, QString color);
    
public slots :
	void onButtonClicked(QAbstractButton* btn);


private:
    Ui::QtIntelligentMapClass *ui;

   


};

