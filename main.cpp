#include "QtIntelligentMap.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	
    QApplication app(argc, argv);
    QtIntelligentMap window;
    window.show();
    return app.exec();
}
