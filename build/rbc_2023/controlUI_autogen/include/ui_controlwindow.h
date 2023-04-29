/********************************************************************************
** Form generated from reading UI file 'controlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWINDOW_H
#define UI_CONTROLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controlWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *testOutFile;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSpinBox *theta_present;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpinBox *y_present;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QSpinBox *x_present;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *pub_betad;
    QSpinBox *pub_beta;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_11;
    QLabel *dd;
    QSpinBox *pub_alpha;
    QHBoxLayout *horizontalLayout_12;
    QLabel *pub_speeds;
    QSpinBox *pub_speed;
    QGridLayout *gridLayout_11;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_7;
    QLabel *pub_ya;
    QSpinBox *pub_y;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_13;
    QSpinBox *pub_x;
    QHBoxLayout *horizontalLayout_8;
    QLabel *da;
    QSpinBox *pub_theta;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *beta_present;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10000;
    QSpinBox *alpha_present;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *speed_present;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout;
    QPushButton *IMUSetZero;
    QGridLayout *gridLayout_10;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *PublishIndicator;
    QPushButton *launch;
    QPushButton *clearOutputButton;
    QPushButton *emergencyStop;
    QLabel *Mode;
    QTextBrowser *OutputRegion;
    QLabel *label_16;
    QLCDNumber *lcdNumber;
    QWidget *Display;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *showWrite;
    QRadioButton *showRead;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *controlWindow)
    {
        if (controlWindow->objectName().isEmpty())
            controlWindow->setObjectName(QString::fromUtf8("controlWindow"));
        controlWindow->resize(1361, 906);
        centralwidget = new QWidget(controlWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        testOutFile = new QTabWidget(centralwidget);
        testOutFile->setObjectName(QString::fromUtf8("testOutFile"));
        testOutFile->setGeometry(QRect(10, 10, 1351, 861));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 50, 981, 741));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_9->setFont(font);
        label_9->setTextFormat(Qt::AutoText);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setMargin(10);
        label_9->setIndent(10);

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_6);

        theta_present = new QSpinBox(verticalLayoutWidget);
        theta_present->setObjectName(QString::fromUtf8("theta_present"));
        theta_present->setAlignment(Qt::AlignCenter);
        theta_present->setMaximum(1000000);

        horizontalLayout_4->addWidget(theta_present);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_7);

        y_present = new QSpinBox(verticalLayoutWidget);
        y_present->setObjectName(QString::fromUtf8("y_present"));
        y_present->setAlignment(Qt::AlignCenter);
        y_present->setMaximum(1000000);

        horizontalLayout_5->addWidget(y_present);


        gridLayout_3->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setTextFormat(Qt::PlainText);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(false);

        horizontalLayout_15->addWidget(label_14);

        x_present = new QSpinBox(verticalLayoutWidget);
        x_present->setObjectName(QString::fromUtf8("x_present"));
        x_present->setAlignment(Qt::AlignCenter);
        x_present->setMinimum(-100000);
        x_present->setMaximum(1000000);

        horizontalLayout_15->addWidget(x_present);


        gridLayout_3->addLayout(horizontalLayout_15, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pub_betad = new QLabel(verticalLayoutWidget);
        pub_betad->setObjectName(QString::fromUtf8("pub_betad"));
        pub_betad->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(pub_betad);

        pub_beta = new QSpinBox(verticalLayoutWidget);
        pub_beta->setObjectName(QString::fromUtf8("pub_beta"));
        pub_beta->setAlignment(Qt::AlignCenter);
        pub_beta->setMinimum(-1000);
        pub_beta->setMaximum(1000000);

        horizontalLayout_10->addWidget(pub_beta);


        gridLayout_7->addLayout(horizontalLayout_10, 3, 0, 1, 1);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setTextFormat(Qt::AutoText);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_15, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        dd = new QLabel(verticalLayoutWidget);
        dd->setObjectName(QString::fromUtf8("dd"));
        dd->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(dd);

        pub_alpha = new QSpinBox(verticalLayoutWidget);
        pub_alpha->setObjectName(QString::fromUtf8("pub_alpha"));
        pub_alpha->setAlignment(Qt::AlignCenter);
        pub_alpha->setMaximum(1000000);

        horizontalLayout_11->addWidget(pub_alpha);


        gridLayout_7->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pub_speeds = new QLabel(verticalLayoutWidget);
        pub_speeds->setObjectName(QString::fromUtf8("pub_speeds"));
        pub_speeds->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(pub_speeds);

        pub_speed = new QSpinBox(verticalLayoutWidget);
        pub_speed->setObjectName(QString::fromUtf8("pub_speed"));
        pub_speed->setAlignment(Qt::AlignCenter);
        pub_speed->setMaximum(100000);

        horizontalLayout_12->addWidget(pub_speed);


        gridLayout_7->addLayout(horizontalLayout_12, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_7, 0, 1, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setTextFormat(Qt::AutoText);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setMargin(10);
        label_11->setIndent(10);

        gridLayout_11->addWidget(label_11, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pub_ya = new QLabel(verticalLayoutWidget);
        pub_ya->setObjectName(QString::fromUtf8("pub_ya"));
        pub_ya->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(pub_ya);

        pub_y = new QSpinBox(verticalLayoutWidget);
        pub_y->setObjectName(QString::fromUtf8("pub_y"));
        pub_y->setAlignment(Qt::AlignCenter);
        pub_y->setMaximum(1000000);

        horizontalLayout_7->addWidget(pub_y);


        gridLayout_11->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setTextFormat(Qt::PlainText);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(false);

        horizontalLayout_9->addWidget(label_13);

        pub_x = new QSpinBox(verticalLayoutWidget);
        pub_x->setObjectName(QString::fromUtf8("pub_x"));
        pub_x->setAlignment(Qt::AlignCenter);
        pub_x->setMinimum(-10000000);
        pub_x->setMaximum(1000000);

        horizontalLayout_9->addWidget(pub_x);


        gridLayout_11->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        da = new QLabel(verticalLayoutWidget);
        da->setObjectName(QString::fromUtf8("da"));
        da->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(da);

        pub_theta = new QSpinBox(verticalLayoutWidget);
        pub_theta->setObjectName(QString::fromUtf8("pub_theta"));
        pub_theta->setAlignment(Qt::AlignCenter);
        pub_theta->setMinimum(-10000);
        pub_theta->setMaximum(1000000);

        horizontalLayout_8->addWidget(pub_theta);


        gridLayout_11->addLayout(horizontalLayout_8, 3, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_11, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        beta_present = new QSpinBox(verticalLayoutWidget);
        beta_present->setObjectName(QString::fromUtf8("beta_present"));
        beta_present->setAlignment(Qt::AlignCenter);
        beta_present->setMaximum(1000000);

        horizontalLayout_3->addWidget(beta_present);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_10000 = new QLabel(verticalLayoutWidget);
        label_10000->setObjectName(QString::fromUtf8("label_10000"));
        label_10000->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_10000);

        alpha_present = new QSpinBox(verticalLayoutWidget);
        alpha_present->setObjectName(QString::fromUtf8("alpha_present"));
        alpha_present->setAlignment(Qt::AlignCenter);
        alpha_present->setMaximum(1000000);

        horizontalLayout_2->addWidget(alpha_present);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        speed_present = new QSpinBox(verticalLayoutWidget);
        speed_present->setObjectName(QString::fromUtf8("speed_present"));
        speed_present->setAlignment(Qt::AlignCenter);
        speed_present->setMaximum(100000);

        horizontalLayout->addWidget(speed_present);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_5);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));

        gridLayout_8->addLayout(horizontalLayout_13, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout_8->addLayout(verticalLayout, 3, 1, 1, 1);

        IMUSetZero = new QPushButton(verticalLayoutWidget);
        IMUSetZero->setObjectName(QString::fromUtf8("IMUSetZero"));

        gridLayout_8->addWidget(IMUSetZero, 4, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_8);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_10->addWidget(label_2, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        PublishIndicator = new QPushButton(verticalLayoutWidget);
        PublishIndicator->setObjectName(QString::fromUtf8("PublishIndicator"));
        PublishIndicator->setBaseSize(QSize(3, 3));

        verticalLayout_5->addWidget(PublishIndicator);

        launch = new QPushButton(verticalLayoutWidget);
        launch->setObjectName(QString::fromUtf8("launch"));

        verticalLayout_5->addWidget(launch);

        clearOutputButton = new QPushButton(verticalLayoutWidget);
        clearOutputButton->setObjectName(QString::fromUtf8("clearOutputButton"));

        verticalLayout_5->addWidget(clearOutputButton);

        emergencyStop = new QPushButton(verticalLayoutWidget);
        emergencyStop->setObjectName(QString::fromUtf8("emergencyStop"));
        emergencyStop->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);"));

        verticalLayout_5->addWidget(emergencyStop);


        gridLayout_10->addLayout(verticalLayout_5, 2, 0, 1, 1);

        Mode = new QLabel(verticalLayoutWidget);
        Mode->setObjectName(QString::fromUtf8("Mode"));
        Mode->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(Mode, 0, 0, 1, 1);

        OutputRegion = new QTextBrowser(verticalLayoutWidget);
        OutputRegion->setObjectName(QString::fromUtf8("OutputRegion"));

        gridLayout_10->addWidget(OutputRegion, 2, 2, 1, 1);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_16, 0, 2, 1, 1);

        lcdNumber = new QLCDNumber(verticalLayoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Light"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lcdNumber->setFont(font1);
        lcdNumber->setAutoFillBackground(false);
        lcdNumber->setStyleSheet(QString::fromUtf8("border: 1px solid green; color: green; background: silver"));
        lcdNumber->setFrameShape(QFrame::Panel);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSegmentStyle(QLCDNumber::Outline);

        gridLayout_10->addWidget(lcdNumber, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_10);

        testOutFile->addTab(tab_2, QString());
        Display = new QWidget();
        Display->setObjectName(QString::fromUtf8("Display"));
        verticalLayoutWidget_2 = new QWidget(Display);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(80, 100, 211, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        showWrite = new QRadioButton(verticalLayoutWidget_2);
        showWrite->setObjectName(QString::fromUtf8("showWrite"));
        showWrite->setAutoExclusive(false);

        verticalLayout_2->addWidget(showWrite);

        showRead = new QRadioButton(verticalLayoutWidget_2);
        showRead->setObjectName(QString::fromUtf8("showRead"));
        showRead->setAutoExclusive(false);

        verticalLayout_2->addWidget(showRead);

        testOutFile->addTab(Display, QString());
        controlWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(controlWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1361, 28));
        controlWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(controlWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        controlWindow->setStatusBar(statusbar);

        retranslateUi(controlWindow);

        testOutFile->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(controlWindow);
    } // setupUi

    void retranslateUi(QMainWindow *controlWindow)
    {
        controlWindow->setWindowTitle(QApplication::translate("controlWindow", "controlWindow", nullptr));
        label_9->setText(QApplication::translate("controlWindow", "\345\256\236\346\227\266\347\212\266\346\200\201\345\217\215\351\246\210", nullptr));
        label_6->setText(QApplication::translate("controlWindow", "\345\201\217\350\247\222", nullptr));
        label_7->setText(QApplication::translate("controlWindow", "y", nullptr));
        label_14->setText(QApplication::translate("controlWindow", "x", nullptr));
        pub_betad->setText(QApplication::translate("controlWindow", "\344\272\221\345\217\260\346\260\264\345\271\263\350\247\222(\302\260)", nullptr));
        label_15->setText(QApplication::translate("controlWindow", "\344\272\221\345\217\260", nullptr));
        dd->setText(QApplication::translate("controlWindow", "\344\272\221\345\217\260\344\273\260\350\247\222(\302\260)", nullptr));
        pub_speeds->setText(QApplication::translate("controlWindow", "\345\220\214\346\255\245\345\270\246\351\200\237\345\272\246", nullptr));
        label_11->setText(QApplication::translate("controlWindow", "\345\272\225\347\233\230\357\274\210\345\244\247\350\261\241\357\274\211", nullptr));
        pub_ya->setText(QApplication::translate("controlWindow", "y", nullptr));
        label_13->setText(QApplication::translate("controlWindow", "x", nullptr));
        da->setText(QApplication::translate("controlWindow", "\345\201\217\350\247\222\357\274\210\302\260\357\274\211", nullptr));
        label_3->setText(QApplication::translate("controlWindow", "\344\272\221\345\217\260\346\260\264\345\271\263\350\247\222(\302\260)", nullptr));
        label_4->setText(QApplication::translate("controlWindow", "\345\256\236\346\227\266\347\212\266\346\200\201\345\217\215\351\246\210", nullptr));
        label_10000->setText(QApplication::translate("controlWindow", "\344\272\221\345\217\260\344\273\260\350\247\222(\302\260)", nullptr));
        label->setText(QApplication::translate("controlWindow", "\345\220\214\346\255\245\345\270\246\351\200\237\345\272\246", nullptr));
        IMUSetZero->setText(QApplication::translate("controlWindow", "\344\272\221\345\217\260\346\240\241\345\207\206", nullptr));
        label_2->setText(QString());
        PublishIndicator->setText(QApplication::translate("controlWindow", "\344\270\213\350\276\276\346\214\207\344\273\244", nullptr));
        launch->setText(QApplication::translate("controlWindow", "\345\217\221\345\260\204", nullptr));
        clearOutputButton->setText(QApplication::translate("controlWindow", "\346\270\205\347\251\272", nullptr));
        emergencyStop->setText(QApplication::translate("controlWindow", "\345\201\234\346\255\242", nullptr));
        Mode->setText(QApplication::translate("controlWindow", "\345\275\223\345\211\215\346\250\241\345\274\217", nullptr));
        label_16->setText(QApplication::translate("controlWindow", "\347\212\266\346\200\201\344\277\241\346\201\257\350\276\223\345\207\272\345\214\272\345\237\237", nullptr));
        testOutFile->setTabText(testOutFile->indexOf(tab_2), QApplication::translate("controlWindow", "\346\216\247\345\210\266\345\214\272", nullptr));
        showWrite->setText(QApplication::translate("controlWindow", "\346\230\276\347\244\272\345\206\231\345\205\245\347\232\204\346\225\260\346\215\256", nullptr));
        showRead->setText(QApplication::translate("controlWindow", "\346\230\276\347\244\272\350\257\273\345\217\226\347\232\204\346\225\260\346\215\256", nullptr));
        testOutFile->setTabText(testOutFile->indexOf(Display), QApplication::translate("controlWindow", "\346\265\213\350\257\225\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class controlWindow: public Ui_controlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
