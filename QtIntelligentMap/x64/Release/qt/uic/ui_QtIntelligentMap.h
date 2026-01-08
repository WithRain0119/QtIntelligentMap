/********************************************************************************
** Form generated from reading UI file 'QtIntelligentMap.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTINTELLIGENTMAP_H
#define UI_QTINTELLIGENTMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtIntelligentMapClass
{
public:
    QLabel *Label_tittle;
    QFrame *line_Tittle;
    QFrame *line_mapright;
    QFrame *line_btndown;
    QPushButton *pushButton_BFS;
    QLabel *label_btnArea;
    QLabel *label_prtArea;
    QPushButton *pushButton_show;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_short;
    QPushButton *pushButton_DFS;
    QLabel *label_topMap;
    QLabel *label_arrow;
    QTextEdit *textEdit_print;
    QPushButton *pushButton_1;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_11;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QFrame *line_i1;
    QFrame *line_i2;
    QFrame *line_j1;
    QFrame *line_k1;
    QFrame *line_l1;
    QFrame *line_o1;
    QFrame *line_h1;
    QFrame *line_h2;
    QFrame *line_g1;
    QFrame *line_b1;
    QFrame *line_b2;
    QFrame *line_a1;
    QFrame *line_e1;
    QFrame *line_e2;
    QFrame *line_d1;
    QFrame *line_d2;
    QFrame *line_c1;
    QFrame *line_f1;
    QFrame *line_n1;
    QFrame *line_n2;
    QFrame *line_f2;
    QFrame *line_m2;
    QFrame *line_m1;
    QLabel *label_a;
    QLabel *label_b;
    QLabel *label_d;
    QLabel *label_e;
    QLabel *label_f;
    QLabel *label_c;
    QLabel *label_g;
    QLabel *label_h;
    QLabel *label_n;
    QLabel *label_m;
    QLabel *label_o;
    QLabel *label_l;
    QLabel *label_k;
    QLabel *label_j;
    QLabel *label_i;
    QFrame *line_p1;
    QFrame *line_p2;
    QLabel *label_p;
    QPushButton *pushButton_car;
    QPushButton *pushButton_bike;
    QPushButton *pushButton_walk;
    QPushButton *pushButton_12;
    QFrame *line_q1;
    QLabel *label_q;
    QLabel *label_transArea;

    void setupUi(QWidget *QtIntelligentMapClass)
    {
        if (QtIntelligentMapClass->objectName().isEmpty())
            QtIntelligentMapClass->setObjectName("QtIntelligentMapClass");
        QtIntelligentMapClass->resize(916, 561);
        QtIntelligentMapClass->setMinimumSize(QSize(916, 561));
        QtIntelligentMapClass->setMaximumSize(QSize(916, 561));
        QtIntelligentMapClass->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	\n"
"	background-color:rgb(245, 240, 230)\n"
"}\n"
"\n"
"QPushButton {\n"
"    border: 1px solid #666666; /* \345\237\272\347\241\200\350\276\271\346\241\206 */\n"
"    background-color: #f0f0f0; /* \346\255\243\345\270\270\347\212\266\346\200\201\350\203\214\346\231\257\350\211\262\357\274\214\350\264\264\350\277\221\345\216\237\347\224\237 */\n"
"    padding: 5px; /* \345\217\257\351\200\211\357\274\232\345\242\236\345\212\240\345\206\205\350\276\271\350\267\235\357\274\214\346\214\211\351\222\256\346\233\264\347\276\216\350\247\202 */\n"
"    border-radius: 2px; /* \345\217\257\351\200\211\357\274\232\350\275\273\345\276\256\345\234\206\350\247\222\357\274\214\350\264\264\350\277\221\345\216\237\347\224\237\346\240\267\345\274\217 */\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\345\217\215\351\246\2101\357\274\232\351\274\240\346\240\207\347\247\273\344\270\212\345\216\273\345\217\230\350\211\262\357\274\211 */\n"
"QPushButton:hover {\n"
""
                        "    background-color: #e5e5e5; /* \346\257\224\346\255\243\345\270\270\347\212\266\346\200\201\346\232\227\344\270\200\347\202\271 */\n"
"    border-color: #555555; /* \350\276\271\346\241\206\347\225\245\346\267\261 */\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\345\217\215\351\246\2102\357\274\232\347\202\271\345\207\273\346\227\266\345\217\230\350\211\262\357\274\211 */\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0; /* \346\257\224\346\202\254\345\201\234\347\212\266\346\200\201\346\233\264\346\232\227 */\n"
"    border-color: #444444; /* \350\276\271\346\241\206\346\233\264\346\267\261 */\n"
"    /* \345\217\257\351\200\211\357\274\232\346\214\211\344\270\213\346\227\266\350\275\273\345\276\256\345\201\217\347\247\273\357\274\214\346\250\241\346\213\237\346\214\211\345\216\213\346\204\237 */\n"
"    padding-left: 6px;\n"
"    padding-top: 6px;\n"
"}\n"
"\n"
""));
        Label_tittle = new QLabel(QtIntelligentMapClass);
        Label_tittle->setObjectName("Label_tittle");
        Label_tittle->setGeometry(QRect(70, 10, 741, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        Label_tittle->setFont(font);
        line_Tittle = new QFrame(QtIntelligentMapClass);
        line_Tittle->setObjectName("line_Tittle");
        line_Tittle->setGeometry(QRect(-60, 40, 2000, 2));
        line_Tittle->setMinimumSize(QSize(2000, 2));
        line_Tittle->setMaximumSize(QSize(16777215, 2));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        line_Tittle->setFont(font1);
        line_Tittle->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_Tittle->setFrameShape(QFrame::Shape::HLine);
        line_Tittle->setFrameShadow(QFrame::Shadow::Sunken);
        line_mapright = new QFrame(QtIntelligentMapClass);
        line_mapright->setObjectName("line_mapright");
        line_mapright->setGeometry(QRect(680, 40, 2, 531));
        line_mapright->setMinimumSize(QSize(2, 0));
        line_mapright->setMaximumSize(QSize(2, 16777215));
        line_mapright->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_mapright->setFrameShape(QFrame::Shape::VLine);
        line_mapright->setFrameShadow(QFrame::Shadow::Sunken);
        line_btndown = new QFrame(QtIntelligentMapClass);
        line_btndown->setObjectName("line_btndown");
        line_btndown->setGeometry(QRect(680, 220, 271, 2));
        line_btndown->setMinimumSize(QSize(0, 2));
        line_btndown->setMaximumSize(QSize(16777215, 2));
        line_btndown->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_btndown->setFrameShape(QFrame::Shape::HLine);
        line_btndown->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton_BFS = new QPushButton(QtIntelligentMapClass);
        pushButton_BFS->setObjectName("pushButton_BFS");
        pushButton_BFS->setGeometry(QRect(720, 80, 80, 40));
        pushButton_BFS->setStyleSheet(QString::fromUtf8(""));
        label_btnArea = new QLabel(QtIntelligentMapClass);
        label_btnArea->setObjectName("label_btnArea");
        label_btnArea->setGeometry(QRect(750, 50, 111, 20));
        label_btnArea->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 115, 207);"));
        label_btnArea->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_prtArea = new QLabel(QtIntelligentMapClass);
        label_prtArea->setObjectName("label_prtArea");
        label_prtArea->setGeometry(QRect(750, 230, 111, 20));
        label_prtArea->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 115, 207);"));
        label_prtArea->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_show = new QPushButton(QtIntelligentMapClass);
        pushButton_show->setObjectName("pushButton_show");
        pushButton_show->setGeometry(QRect(720, 126, 80, 40));
        pushButton_show->setStyleSheet(QString::fromUtf8(""));
        pushButton_clear = new QPushButton(QtIntelligentMapClass);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setGeometry(QRect(720, 172, 80, 40));
        pushButton_clear->setStyleSheet(QString::fromUtf8(""));
        pushButton_exit = new QPushButton(QtIntelligentMapClass);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(806, 172, 80, 40));
        pushButton_exit->setStyleSheet(QString::fromUtf8(""));
        pushButton_short = new QPushButton(QtIntelligentMapClass);
        pushButton_short->setObjectName("pushButton_short");
        pushButton_short->setGeometry(QRect(806, 126, 80, 40));
        pushButton_short->setStyleSheet(QString::fromUtf8(""));
        pushButton_DFS = new QPushButton(QtIntelligentMapClass);
        pushButton_DFS->setObjectName("pushButton_DFS");
        pushButton_DFS->setGeometry(QRect(806, 80, 80, 40));
        pushButton_DFS->setStyleSheet(QString::fromUtf8(""));
        label_topMap = new QLabel(QtIntelligentMapClass);
        label_topMap->setObjectName("label_topMap");
        label_topMap->setGeometry(QRect(10, 60, 651, 16));
        label_arrow = new QLabel(QtIntelligentMapClass);
        label_arrow->setObjectName("label_arrow");
        label_arrow->setGeometry(QRect(620, 50, 51, 51));
        QFont font2;
        font2.setPointSize(15);
        label_arrow->setFont(font2);
        label_arrow->setAlignment(Qt::AlignmentFlag::AlignCenter);
        textEdit_print = new QTextEdit(QtIntelligentMapClass);
        textEdit_print->setObjectName("textEdit_print");
        textEdit_print->setGeometry(QRect(690, 250, 221, 311));
        textEdit_print->setStyleSheet(QString::fromUtf8("border:none;\n"
""));
        textEdit_print->setLineWidth(15);
        textEdit_print->setReadOnly(true);
        pushButton_1 = new QPushButton(QtIntelligentMapClass);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(30, 163, 61, 91));
        pushButton_4 = new QPushButton(QtIntelligentMapClass);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(140, 423, 80, 31));
        pushButton_3 = new QPushButton(QtIntelligentMapClass);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 270, 80, 24));
        pushButton_6 = new QPushButton(QtIntelligentMapClass);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(280, 183, 80, 41));
        pushButton_7 = new QPushButton(QtIntelligentMapClass);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(400, 123, 80, 41));
        pushButton_2 = new QPushButton(QtIntelligentMapClass);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 333, 80, 31));
        pushButton_8 = new QPushButton(QtIntelligentMapClass);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(380, 263, 80, 41));
        pushButton_5 = new QPushButton(QtIntelligentMapClass);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(280, 420, 81, 31));
        pushButton_11 = new QPushButton(QtIntelligentMapClass);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(420, 470, 131, 24));
        pushButton_9 = new QPushButton(QtIntelligentMapClass);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(560, 113, 80, 51));
        pushButton_10 = new QPushButton(QtIntelligentMapClass);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(500, 350, 80, 24));
        line_i1 = new QFrame(QtIntelligentMapClass);
        line_i1->setObjectName("line_i1");
        line_i1->setGeometry(QRect(330, 480, 90, 4));
        line_i1->setMinimumSize(QSize(0, 0));
        line_i1->setMaximumSize(QSize(16777215, 444));
        line_i1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_i1->setFrameShape(QFrame::Shape::HLine);
        line_i1->setFrameShadow(QFrame::Shadow::Sunken);
        line_i2 = new QFrame(QtIntelligentMapClass);
        line_i2->setObjectName("line_i2");
        line_i2->setGeometry(QRect(330, 450, 4, 30));
        line_i2->setMinimumSize(QSize(0, 0));
        line_i2->setMaximumSize(QSize(99999, 16777215));
        line_i2->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_i2->setFrameShape(QFrame::Shape::VLine);
        line_i2->setFrameShadow(QFrame::Shadow::Sunken);
        line_j1 = new QFrame(QtIntelligentMapClass);
        line_j1->setObjectName("line_j1");
        line_j1->setGeometry(QRect(540, 374, 4, 97));
        line_j1->setMinimumSize(QSize(0, 0));
        line_j1->setMaximumSize(QSize(99999, 16777215));
        line_j1->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_j1->setFrameShape(QFrame::Shape::VLine);
        line_j1->setFrameShadow(QFrame::Shadow::Sunken);
        line_k1 = new QFrame(QtIntelligentMapClass);
        line_k1->setObjectName("line_k1");
        line_k1->setGeometry(QRect(570, 163, 4, 188));
        line_k1->setMinimumSize(QSize(0, 0));
        line_k1->setMaximumSize(QSize(99999, 16777215));
        line_k1->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_k1->setFrameShape(QFrame::Shape::VLine);
        line_k1->setFrameShadow(QFrame::Shadow::Sunken);
        line_l1 = new QFrame(QtIntelligentMapClass);
        line_l1->setObjectName("line_l1");
        line_l1->setGeometry(QRect(479, 150, 81, 4));
        line_l1->setMinimumSize(QSize(0, 0));
        line_l1->setMaximumSize(QSize(16777215, 444));
        line_l1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */\n"
"background-color: black;"));
        line_l1->setFrameShape(QFrame::Shape::HLine);
        line_l1->setFrameShadow(QFrame::Shadow::Sunken);
        line_o1 = new QFrame(QtIntelligentMapClass);
        line_o1->setObjectName("line_o1");
        line_o1->setGeometry(QRect(440, 164, 4, 100));
        line_o1->setMinimumSize(QSize(0, 0));
        line_o1->setMaximumSize(QSize(99999, 16777215));
        line_o1->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_o1->setFrameShape(QFrame::Shape::VLine);
        line_o1->setFrameShadow(QFrame::Shadow::Sunken);
        line_h1 = new QFrame(QtIntelligentMapClass);
        line_h1->setObjectName("line_h1");
        line_h1->setGeometry(QRect(420, 304, 4, 130));
        line_h1->setMinimumSize(QSize(0, 0));
        line_h1->setMaximumSize(QSize(99999, 16777215));
        line_h1->setStyleSheet(QString::fromUtf8("    background-color: red;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_h1->setFrameShape(QFrame::Shape::VLine);
        line_h1->setFrameShadow(QFrame::Shadow::Sunken);
        line_h2 = new QFrame(QtIntelligentMapClass);
        line_h2->setObjectName("line_h2");
        line_h2->setGeometry(QRect(360, 432, 64, 4));
        line_h2->setMinimumSize(QSize(0, 0));
        line_h2->setMaximumSize(QSize(16777215, 444));
        line_h2->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: red;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_h2->setFrameShape(QFrame::Shape::HLine);
        line_h2->setFrameShadow(QFrame::Shadow::Sunken);
        line_g1 = new QFrame(QtIntelligentMapClass);
        line_g1->setObjectName("line_g1");
        line_g1->setGeometry(QRect(220, 440, 60, 4));
        line_g1->setMinimumSize(QSize(0, 0));
        line_g1->setMaximumSize(QSize(16777215, 444));
        line_g1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_g1->setFrameShape(QFrame::Shape::HLine);
        line_g1->setFrameShadow(QFrame::Shadow::Sunken);
        line_b1 = new QFrame(QtIntelligentMapClass);
        line_b1->setObjectName("line_b1");
        line_b1->setGeometry(QRect(80, 440, 60, 4));
        line_b1->setMinimumSize(QSize(0, 0));
        line_b1->setMaximumSize(QSize(16777215, 444));
        line_b1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_b1->setFrameShape(QFrame::Shape::HLine);
        line_b1->setFrameShadow(QFrame::Shadow::Sunken);
        line_b2 = new QFrame(QtIntelligentMapClass);
        line_b2->setObjectName("line_b2");
        line_b2->setGeometry(QRect(80, 363, 4, 79));
        line_b2->setMinimumSize(QSize(0, 0));
        line_b2->setMaximumSize(QSize(99999, 16777215));
        line_b2->setStyleSheet(QString::fromUtf8("background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_b2->setFrameShape(QFrame::Shape::VLine);
        line_b2->setFrameShadow(QFrame::Shadow::Sunken);
        line_a1 = new QFrame(QtIntelligentMapClass);
        line_a1->setObjectName("line_a1");
        line_a1->setGeometry(QRect(60, 253, 4, 80));
        line_a1->setMinimumSize(QSize(0, 0));
        line_a1->setMaximumSize(QSize(99999, 16777215));
        line_a1->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_a1->setFrameShape(QFrame::Shape::VLine);
        line_a1->setFrameShadow(QFrame::Shadow::Sunken);
        line_e1 = new QFrame(QtIntelligentMapClass);
        line_e1->setObjectName("line_e1");
        line_e1->setGeometry(QRect(90, 200, 120, 4));
        line_e1->setMinimumSize(QSize(0, 0));
        line_e1->setMaximumSize(QSize(16777215, 44));
        line_e1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_e1->setFrameShape(QFrame::Shape::HLine);
        line_e1->setFrameShadow(QFrame::Shadow::Sunken);
        line_e2 = new QFrame(QtIntelligentMapClass);
        line_e2->setObjectName("line_e2");
        line_e2->setGeometry(QRect(210, 200, 4, 71));
        line_e2->setMinimumSize(QSize(0, 0));
        line_e2->setMaximumSize(QSize(99999, 16777215));
        line_e2->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_e2->setFrameShape(QFrame::Shape::VLine);
        line_e2->setFrameShadow(QFrame::Shadow::Sunken);
        line_d1 = new QFrame(QtIntelligentMapClass);
        line_d1->setObjectName("line_d1");
        line_d1->setGeometry(QRect(112, 280, 68, 4));
        line_d1->setMinimumSize(QSize(0, 0));
        line_d1->setMaximumSize(QSize(16777215, 444));
        line_d1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: red;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_d1->setFrameShape(QFrame::Shape::HLine);
        line_d1->setFrameShadow(QFrame::Shadow::Sunken);
        line_d2 = new QFrame(QtIntelligentMapClass);
        line_d2->setObjectName("line_d2");
        line_d2->setGeometry(QRect(110, 280, 4, 53));
        line_d2->setMinimumSize(QSize(0, 0));
        line_d2->setMaximumSize(QSize(99999, 16777215));
        line_d2->setStyleSheet(QString::fromUtf8("    background-color: red;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_d2->setFrameShape(QFrame::Shape::VLine);
        line_d2->setFrameShadow(QFrame::Shadow::Sunken);
        line_c1 = new QFrame(QtIntelligentMapClass);
        line_c1->setObjectName("line_c1");
        line_c1->setGeometry(QRect(200, 294, 4, 130));
        line_c1->setMinimumSize(QSize(0, 0));
        line_c1->setMaximumSize(QSize(99999, 16777215));
        line_c1->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_c1->setFrameShape(QFrame::Shape::VLine);
        line_c1->setFrameShadow(QFrame::Shadow::Sunken);
        line_f1 = new QFrame(QtIntelligentMapClass);
        line_f1->setObjectName("line_f1");
        line_f1->setGeometry(QRect(300, 223, 4, 60));
        line_f1->setMinimumSize(QSize(0, 0));
        line_f1->setMaximumSize(QSize(99999, 16777215));
        line_f1->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_f1->setFrameShape(QFrame::Shape::VLine);
        line_f1->setFrameShadow(QFrame::Shadow::Sunken);
        line_n1 = new QFrame(QtIntelligentMapClass);
        line_n1->setObjectName("line_n1");
        line_n1->setGeometry(QRect(410, 200, 4, 63));
        line_n1->setMinimumSize(QSize(0, 0));
        line_n1->setMaximumSize(QSize(99999, 16777215));
        line_n1->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_n1->setFrameShape(QFrame::Shape::VLine);
        line_n1->setFrameShadow(QFrame::Shadow::Sunken);
        line_n2 = new QFrame(QtIntelligentMapClass);
        line_n2->setObjectName("line_n2");
        line_n2->setGeometry(QRect(360, 200, 50, 4));
        line_n2->setMinimumSize(QSize(0, 0));
        line_n2->setMaximumSize(QSize(16777215, 444));
        line_n2->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_n2->setFrameShape(QFrame::Shape::HLine);
        line_n2->setFrameShadow(QFrame::Shadow::Sunken);
        line_f2 = new QFrame(QtIntelligentMapClass);
        line_f2->setObjectName("line_f2");
        line_f2->setGeometry(QRect(260, 282, 44, 4));
        line_f2->setMinimumSize(QSize(0, 0));
        line_f2->setMaximumSize(QSize(16777215, 44));
        line_f2->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_f2->setFrameShape(QFrame::Shape::HLine);
        line_f2->setFrameShadow(QFrame::Shadow::Sunken);
        line_m2 = new QFrame(QtIntelligentMapClass);
        line_m2->setObjectName("line_m2");
        line_m2->setGeometry(QRect(330, 130, 4, 53));
        line_m2->setMinimumSize(QSize(0, 0));
        line_m2->setMaximumSize(QSize(99999, 16777215));
        line_m2->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_m2->setFrameShape(QFrame::Shape::VLine);
        line_m2->setFrameShadow(QFrame::Shadow::Sunken);
        line_m1 = new QFrame(QtIntelligentMapClass);
        line_m1->setObjectName("line_m1");
        line_m1->setGeometry(QRect(332, 130, 68, 4));
        line_m1->setMinimumSize(QSize(0, 0));
        line_m1->setMaximumSize(QSize(16777215, 444));
        line_m1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_m1->setFrameShape(QFrame::Shape::HLine);
        line_m1->setFrameShadow(QFrame::Shadow::Sunken);
        label_a = new QLabel(QtIntelligentMapClass);
        label_a->setObjectName("label_a");
        label_a->setGeometry(QRect(40, 280, 16, 16));
        label_b = new QLabel(QtIntelligentMapClass);
        label_b->setObjectName("label_b");
        label_b->setGeometry(QRect(90, 420, 16, 16));
        label_d = new QLabel(QtIntelligentMapClass);
        label_d->setObjectName("label_d");
        label_d->setGeometry(QRect(130, 290, 16, 16));
        label_e = new QLabel(QtIntelligentMapClass);
        label_e->setObjectName("label_e");
        label_e->setGeometry(QRect(150, 210, 16, 16));
        label_f = new QLabel(QtIntelligentMapClass);
        label_f->setObjectName("label_f");
        label_f->setGeometry(QRect(290, 290, 16, 16));
        label_c = new QLabel(QtIntelligentMapClass);
        label_c->setObjectName("label_c");
        label_c->setGeometry(QRect(210, 350, 16, 16));
        label_g = new QLabel(QtIntelligentMapClass);
        label_g->setObjectName("label_g");
        label_g->setGeometry(QRect(240, 410, 16, 16));
        label_h = new QLabel(QtIntelligentMapClass);
        label_h->setObjectName("label_h");
        label_h->setGeometry(QRect(400, 360, 16, 16));
        label_n = new QLabel(QtIntelligentMapClass);
        label_n->setObjectName("label_n");
        label_n->setGeometry(QRect(390, 210, 16, 16));
        label_m = new QLabel(QtIntelligentMapClass);
        label_m->setObjectName("label_m");
        label_m->setGeometry(QRect(350, 110, 16, 16));
        label_o = new QLabel(QtIntelligentMapClass);
        label_o->setObjectName("label_o");
        label_o->setGeometry(QRect(450, 200, 16, 16));
        label_l = new QLabel(QtIntelligentMapClass);
        label_l->setObjectName("label_l");
        label_l->setGeometry(QRect(520, 130, 16, 16));
        label_k = new QLabel(QtIntelligentMapClass);
        label_k->setObjectName("label_k");
        label_k->setGeometry(QRect(580, 240, 16, 16));
        label_j = new QLabel(QtIntelligentMapClass);
        label_j->setObjectName("label_j");
        label_j->setGeometry(QRect(550, 400, 16, 16));
        label_i = new QLabel(QtIntelligentMapClass);
        label_i->setObjectName("label_i");
        label_i->setGeometry(QRect(380, 460, 16, 16));
        line_p1 = new QFrame(QtIntelligentMapClass);
        line_p1->setObjectName("line_p1");
        line_p1->setGeometry(QRect(460, 360, 40, 4));
        line_p1->setMinimumSize(QSize(0, 0));
        line_p1->setMaximumSize(QSize(16777215, 444));
        line_p1->setStyleSheet(QString::fromUtf8("\n"
"background: transparent;\n"
"    border: none;\n"
"    \n"
"    background-color: black;  /* \350\277\231\345\260\261\346\230\257\347\272\277\347\232\204\351\242\234\350\211\262 */"));
        line_p1->setFrameShape(QFrame::Shape::HLine);
        line_p1->setFrameShadow(QFrame::Shadow::Sunken);
        line_p2 = new QFrame(QtIntelligentMapClass);
        line_p2->setObjectName("line_p2");
        line_p2->setGeometry(QRect(460, 360, 4, 110));
        line_p2->setMinimumSize(QSize(0, 0));
        line_p2->setMaximumSize(QSize(99999, 16777215));
        line_p2->setStyleSheet(QString::fromUtf8("    background-color: black;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_p2->setFrameShape(QFrame::Shape::VLine);
        line_p2->setFrameShadow(QFrame::Shadow::Sunken);
        label_p = new QLabel(QtIntelligentMapClass);
        label_p->setObjectName("label_p");
        label_p->setGeometry(QRect(470, 370, 16, 16));
        pushButton_car = new QPushButton(QtIntelligentMapClass);
        pushButton_car->setObjectName("pushButton_car");
        pushButton_car->setGeometry(QRect(2, 528, 61, 31));
        pushButton_car->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        pushButton_bike = new QPushButton(QtIntelligentMapClass);
        pushButton_bike->setObjectName("pushButton_bike");
        pushButton_bike->setGeometry(QRect(66, 528, 61, 31));
        pushButton_bike->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        pushButton_walk = new QPushButton(QtIntelligentMapClass);
        pushButton_walk->setObjectName("pushButton_walk");
        pushButton_walk->setGeometry(QRect(130, 528, 61, 31));
        pushButton_walk->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        pushButton_12 = new QPushButton(QtIntelligentMapClass);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(390, 80, 80, 24));
        line_q1 = new QFrame(QtIntelligentMapClass);
        line_q1->setObjectName("line_q1");
        line_q1->setGeometry(QRect(440, 103, 4, 20));
        line_q1->setMinimumSize(QSize(0, 0));
        line_q1->setMaximumSize(QSize(99999, 16777215));
        line_q1->setStyleSheet(QString::fromUtf8("    background-color: red;  /* \347\272\277\347\232\204\351\242\234\350\211\262 */\n"
""));
        line_q1->setFrameShape(QFrame::Shape::VLine);
        line_q1->setFrameShadow(QFrame::Shadow::Sunken);
        label_q = new QLabel(QtIntelligentMapClass);
        label_q->setObjectName("label_q");
        label_q->setGeometry(QRect(450, 105, 16, 16));
        label_transArea = new QLabel(QtIntelligentMapClass);
        label_transArea->setObjectName("label_transArea");
        label_transArea->setGeometry(QRect(40, 500, 111, 20));
        label_transArea->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 115, 207);"));
        label_transArea->setAlignment(Qt::AlignmentFlag::AlignCenter);
        line_btndown->raise();
        Label_tittle->raise();
        line_Tittle->raise();
        line_mapright->raise();
        pushButton_BFS->raise();
        label_btnArea->raise();
        label_prtArea->raise();
        pushButton_show->raise();
        pushButton_clear->raise();
        pushButton_exit->raise();
        pushButton_short->raise();
        pushButton_DFS->raise();
        label_topMap->raise();
        label_arrow->raise();
        textEdit_print->raise();
        pushButton_1->raise();
        pushButton_4->raise();
        pushButton_3->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_2->raise();
        pushButton_8->raise();
        pushButton_5->raise();
        pushButton_11->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        line_i1->raise();
        line_i2->raise();
        line_j1->raise();
        line_k1->raise();
        line_l1->raise();
        line_o1->raise();
        line_h1->raise();
        line_h2->raise();
        line_g1->raise();
        line_b1->raise();
        line_b2->raise();
        line_a1->raise();
        line_e1->raise();
        line_e2->raise();
        line_d1->raise();
        line_d2->raise();
        line_c1->raise();
        line_f1->raise();
        line_n1->raise();
        line_n2->raise();
        line_f2->raise();
        line_m2->raise();
        line_m1->raise();
        label_a->raise();
        label_b->raise();
        label_d->raise();
        label_e->raise();
        label_f->raise();
        label_c->raise();
        label_g->raise();
        label_h->raise();
        label_n->raise();
        label_m->raise();
        label_o->raise();
        label_l->raise();
        label_k->raise();
        label_j->raise();
        label_i->raise();
        line_p1->raise();
        line_p2->raise();
        label_p->raise();
        pushButton_car->raise();
        pushButton_bike->raise();
        pushButton_walk->raise();
        pushButton_12->raise();
        line_q1->raise();
        label_q->raise();
        label_transArea->raise();

        retranslateUi(QtIntelligentMapClass);

        QMetaObject::connectSlotsByName(QtIntelligentMapClass);
    } // setupUi

    void retranslateUi(QWidget *QtIntelligentMapClass)
    {
        QtIntelligentMapClass->setWindowTitle(QCoreApplication::translate("QtIntelligentMapClass", "IntelligentMap", nullptr));
        Label_tittle->setText(QCoreApplication::translate("QtIntelligentMapClass", "<html><head/><body><p align=\"center\"><span style=\" color:#ff0000;\">\345\215\216\345\214\227\346\260\264\345\210\251\346\260\264\347\224\265\345\244\247\345\255\246\346\231\272\350\203\275\345\234\260\345\233\276</span></p></body></html>", nullptr));
        pushButton_BFS->setText(QCoreApplication::translate("QtIntelligentMapClass", "\347\224\250BFS\346\237\245\347\234\213\n"
"\345\217\257\344\273\245\345\210\260\345\223\252\351\207\214", nullptr));
        label_btnArea->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\214\211\351\224\256\345\212\237\350\203\275\345\214\272", nullptr));
        label_prtArea->setText(QCoreApplication::translate("QtIntelligentMapClass", "\350\276\223\345\207\272\346\230\276\347\244\272\345\214\272", nullptr));
        pushButton_show->setText(QCoreApplication::translate("QtIntelligentMapClass", "\344\273\213\347\273\215\345\273\272\347\255\221", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\270\205\347\251\272\346\230\276\347\244\272\345\214\272", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("QtIntelligentMapClass", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        pushButton_short->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\261\202\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        pushButton_DFS->setText(QCoreApplication::translate("QtIntelligentMapClass", "\347\224\250DFS\346\237\245\347\234\213\n"
"\345\217\257\344\273\245\345\210\260\345\223\252\351\207\214", nullptr));
        label_topMap->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\263\250\357\274\232\351\273\221\350\211\262\351\201\223\350\267\257\344\270\272\351\200\232\350\267\257\357\274\214\347\272\242\350\211\262\351\201\223\350\267\257\346\232\202\346\227\266\346\227\240\346\263\225\351\200\232\350\241\214\357\274\214\347\273\277\350\211\262\351\201\223\350\267\257\344\270\272\344\270\244\347\202\271\351\227\264\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        label_arrow->setText(QCoreApplication::translate("QtIntelligentMapClass", "S\n"
"\342\206\221", nullptr));
        pushButton_1->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\223\215\345\234\272", nullptr));
        pushButton_4->setText(QCoreApplication::translate("QtIntelligentMapClass", "F2\345\217\267\346\245\274", nullptr));
        pushButton_3->setText(QCoreApplication::translate("QtIntelligentMapClass", "\351\243\237\345\240\202A", nullptr));
        pushButton_6->setText(QCoreApplication::translate("QtIntelligentMapClass", "\345\233\276\344\271\246\351\246\206", nullptr));
        pushButton_7->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\225\231\345\255\246\346\245\274B", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QtIntelligentMapClass", "\345\256\277\350\210\215B", nullptr));
        pushButton_8->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\225\231\345\255\246\346\245\274A", nullptr));
        pushButton_5->setText(QCoreApplication::translate("QtIntelligentMapClass", "\345\256\277\350\210\215A", nullptr));
        pushButton_11->setText(QCoreApplication::translate("QtIntelligentMapClass", "\344\270\234\345\214\227\351\227\250", nullptr));
        pushButton_9->setText(QCoreApplication::translate("QtIntelligentMapClass", "\351\243\237\345\240\202B", nullptr));
        pushButton_10->setText(QCoreApplication::translate("QtIntelligentMapClass", "\345\256\266\345\261\236\351\231\242", nullptr));
        label_a->setText(QCoreApplication::translate("QtIntelligentMapClass", "a", nullptr));
        label_b->setText(QCoreApplication::translate("QtIntelligentMapClass", "b", nullptr));
        label_d->setText(QCoreApplication::translate("QtIntelligentMapClass", "d", nullptr));
        label_e->setText(QCoreApplication::translate("QtIntelligentMapClass", "e", nullptr));
        label_f->setText(QCoreApplication::translate("QtIntelligentMapClass", "f", nullptr));
        label_c->setText(QCoreApplication::translate("QtIntelligentMapClass", "c", nullptr));
        label_g->setText(QCoreApplication::translate("QtIntelligentMapClass", "g", nullptr));
        label_h->setText(QCoreApplication::translate("QtIntelligentMapClass", "h", nullptr));
        label_n->setText(QCoreApplication::translate("QtIntelligentMapClass", "n", nullptr));
        label_m->setText(QCoreApplication::translate("QtIntelligentMapClass", "m", nullptr));
        label_o->setText(QCoreApplication::translate("QtIntelligentMapClass", "o", nullptr));
        label_l->setText(QCoreApplication::translate("QtIntelligentMapClass", "l", nullptr));
        label_k->setText(QCoreApplication::translate("QtIntelligentMapClass", "k", nullptr));
        label_j->setText(QCoreApplication::translate("QtIntelligentMapClass", "j", nullptr));
        label_i->setText(QCoreApplication::translate("QtIntelligentMapClass", "i", nullptr));
        label_p->setText(QCoreApplication::translate("QtIntelligentMapClass", "p", nullptr));
        pushButton_car->setText(QCoreApplication::translate("QtIntelligentMapClass", "\345\260\217\350\275\277\350\275\246", nullptr));
        pushButton_bike->setText(QCoreApplication::translate("QtIntelligentMapClass", "\350\207\252\350\241\214\350\275\246", nullptr));
        pushButton_walk->setText(QCoreApplication::translate("QtIntelligentMapClass", "\346\255\245\350\241\214", nullptr));
        pushButton_12->setText(QCoreApplication::translate("QtIntelligentMapClass", "\345\215\227\351\227\250", nullptr));
        label_q->setText(QCoreApplication::translate("QtIntelligentMapClass", "q", nullptr));
        label_transArea->setText(QCoreApplication::translate("QtIntelligentMapClass", "\344\272\244\351\200\232\345\267\245\345\205\267\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtIntelligentMapClass: public Ui_QtIntelligentMapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTINTELLIGENTMAP_H
