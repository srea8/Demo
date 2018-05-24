/********************************************************************************
** Form generated from reading UI file 'choosepicture.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEPICTURE_H
#define UI_CHOOSEPICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choosePictureClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *img_GraphicsView;
    QLabel *label_8;
    QPlainTextEdit *Log_TextEdit;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QWidget *widget_9;
    QGridLayout *gridLayout_4;
    QCheckBox *Log_checkBox;
    QCheckBox *Config_checkBox;
    QLabel *label_10;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QCheckBox *AllFob_checkBox;
    QCheckBox *Yang_checkBox;
    QCheckBox *RouYang_checkBox;
    QCheckBox *Yin_checkBox;
    QCheckBox *AllcheckBox;
    QSpacerItem *verticalSpacer;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QCheckBox *AllCell_checkBox;
    QCheckBox *RedCell_checkBox;
    QCheckBox *WhiteCell_checkBox;
    QCheckBox *Mold_checkBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QCheckBox *AllColor_checkBox;
    QCheckBox *Yellow_checkBox;
    QCheckBox *Red_checkBox;
    QCheckBox *Brown_checkBox;
    QCheckBox *Black_checkBox;
    QLabel *label_9;
    QCheckBox *AllTraits_checkBox;
    QCheckBox *Rash_checkBox;
    QCheckBox *Soft_checkBox;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QPushButton *leftTurn;
    QPushButton *RightUid;
    QPushButton *LeftUid;
    QPushButton *RightTurn;
    QPushButton *Find_Button;
    QPushButton *Save_Pic;
    QWidget *widget_8;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *label_6;
    QDateEdit *End_dateEdit;
    QDateEdit *Start_dateEdit;
    QLabel *label_2;
    QLabel *label_11;
    QLineEdit *UID_lineEdit;
    QLineEdit *Count_Pic;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *choosePictureClass)
    {
        if (choosePictureClass->objectName().isEmpty())
            choosePictureClass->setObjectName(QStringLiteral("choosePictureClass"));
        choosePictureClass->resize(1070, 754);
        centralWidget = new QWidget(choosePictureClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(240, 240, 240);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(198, 200, 191);"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        img_GraphicsView = new QGraphicsView(widget_2);
        img_GraphicsView->setObjectName(QStringLiteral("img_GraphicsView"));
        img_GraphicsView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(img_GraphicsView);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(198, 200, 191);\n"
"font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout->addWidget(label_8);

        Log_TextEdit = new QPlainTextEdit(widget_2);
        Log_TextEdit->setObjectName(QStringLiteral("Log_TextEdit"));
        Log_TextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Log_TextEdit->setReadOnly(true);

        verticalLayout->addWidget(Log_TextEdit);

        verticalLayout->setStretch(0, 11);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 5);

        gridLayout_2->addWidget(widget_2, 0, 0, 1, 2);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(198, 200, 191);"));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_9 = new QWidget(widget_4);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        gridLayout_4 = new QGridLayout(widget_9);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        Log_checkBox = new QCheckBox(widget_9);
        Log_checkBox->setObjectName(QStringLiteral("Log_checkBox"));

        gridLayout_4->addWidget(Log_checkBox, 1, 1, 1, 1);

        Config_checkBox = new QCheckBox(widget_9);
        Config_checkBox->setObjectName(QStringLiteral("Config_checkBox"));

        gridLayout_4->addWidget(Config_checkBox, 1, 2, 1, 1);

        label_10 = new QLabel(widget_9);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(0, 40));
        label_10->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        gridLayout_4->addWidget(label_10, 0, 1, 1, 1);


        gridLayout->addWidget(widget_9, 2, 0, 1, 3);

        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_5 = new QLabel(widget_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(0, 40));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_5->addWidget(label_5);

        AllFob_checkBox = new QCheckBox(widget_7);
        AllFob_checkBox->setObjectName(QStringLiteral("AllFob_checkBox"));

        verticalLayout_5->addWidget(AllFob_checkBox);

        Yang_checkBox = new QCheckBox(widget_7);
        Yang_checkBox->setObjectName(QStringLiteral("Yang_checkBox"));

        verticalLayout_5->addWidget(Yang_checkBox);

        RouYang_checkBox = new QCheckBox(widget_7);
        RouYang_checkBox->setObjectName(QStringLiteral("RouYang_checkBox"));

        verticalLayout_5->addWidget(RouYang_checkBox);

        Yin_checkBox = new QCheckBox(widget_7);
        Yin_checkBox->setObjectName(QStringLiteral("Yin_checkBox"));

        verticalLayout_5->addWidget(Yin_checkBox);

        AllcheckBox = new QCheckBox(widget_7);
        AllcheckBox->setObjectName(QStringLiteral("AllcheckBox"));

        verticalLayout_5->addWidget(AllcheckBox);

        verticalSpacer = new QSpacerItem(20, 123, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_5->setStretch(0, 1);

        gridLayout->addWidget(widget_7, 3, 2, 1, 1);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        verticalLayout_3 = new QVBoxLayout(widget_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_3->addWidget(label_3);

        AllCell_checkBox = new QCheckBox(widget_5);
        AllCell_checkBox->setObjectName(QStringLiteral("AllCell_checkBox"));

        verticalLayout_3->addWidget(AllCell_checkBox);

        RedCell_checkBox = new QCheckBox(widget_5);
        RedCell_checkBox->setObjectName(QStringLiteral("RedCell_checkBox"));

        verticalLayout_3->addWidget(RedCell_checkBox);

        WhiteCell_checkBox = new QCheckBox(widget_5);
        WhiteCell_checkBox->setObjectName(QStringLiteral("WhiteCell_checkBox"));

        verticalLayout_3->addWidget(WhiteCell_checkBox);

        Mold_checkBox = new QCheckBox(widget_5);
        Mold_checkBox->setObjectName(QStringLiteral("Mold_checkBox"));

        verticalLayout_3->addWidget(Mold_checkBox);

        verticalSpacer_2 = new QSpacerItem(20, 117, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addWidget(widget_5, 3, 0, 1, 1);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(0, 40));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_4->addWidget(label_4);

        AllColor_checkBox = new QCheckBox(widget_6);
        AllColor_checkBox->setObjectName(QStringLiteral("AllColor_checkBox"));

        verticalLayout_4->addWidget(AllColor_checkBox);

        Yellow_checkBox = new QCheckBox(widget_6);
        Yellow_checkBox->setObjectName(QStringLiteral("Yellow_checkBox"));

        verticalLayout_4->addWidget(Yellow_checkBox);

        Red_checkBox = new QCheckBox(widget_6);
        Red_checkBox->setObjectName(QStringLiteral("Red_checkBox"));

        verticalLayout_4->addWidget(Red_checkBox);

        Brown_checkBox = new QCheckBox(widget_6);
        Brown_checkBox->setObjectName(QStringLiteral("Brown_checkBox"));

        verticalLayout_4->addWidget(Brown_checkBox);

        Black_checkBox = new QCheckBox(widget_6);
        Black_checkBox->setObjectName(QStringLiteral("Black_checkBox"));

        verticalLayout_4->addWidget(Black_checkBox);

        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(0, 40));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        verticalLayout_4->addWidget(label_9);

        AllTraits_checkBox = new QCheckBox(widget_6);
        AllTraits_checkBox->setObjectName(QStringLiteral("AllTraits_checkBox"));

        verticalLayout_4->addWidget(AllTraits_checkBox);

        Rash_checkBox = new QCheckBox(widget_6);
        Rash_checkBox->setObjectName(QStringLiteral("Rash_checkBox"));

        verticalLayout_4->addWidget(Rash_checkBox);

        Soft_checkBox = new QCheckBox(widget_6);
        Soft_checkBox->setObjectName(QStringLiteral("Soft_checkBox"));

        verticalLayout_4->addWidget(Soft_checkBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        gridLayout->addWidget(widget_6, 3, 1, 1, 1);

        frame = new QFrame(widget_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("background-color: rgb(198, 200, 191);\n"
"background-color: rgb(240, 240, 240);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        leftTurn = new QPushButton(frame);
        leftTurn->setObjectName(QStringLiteral("leftTurn"));
        leftTurn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"font: 14pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(leftTurn, 1, 0, 1, 1);

        RightUid = new QPushButton(frame);
        RightUid->setObjectName(QStringLiteral("RightUid"));
        RightUid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"font: 14pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(RightUid, 1, 3, 1, 1);

        LeftUid = new QPushButton(frame);
        LeftUid->setObjectName(QStringLiteral("LeftUid"));
        LeftUid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"font: 14pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(LeftUid, 1, 2, 1, 1);

        RightTurn = new QPushButton(frame);
        RightTurn->setObjectName(QStringLiteral("RightTurn"));
        RightTurn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"font: 14pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(RightTurn, 1, 1, 1, 1);

        Find_Button = new QPushButton(frame);
        Find_Button->setObjectName(QStringLiteral("Find_Button"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Find_Button->sizePolicy().hasHeightForWidth());
        Find_Button->setSizePolicy(sizePolicy1);
        Find_Button->setMaximumSize(QSize(200, 16777215));
        Find_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"font: 14pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(Find_Button, 0, 0, 1, 2);

        Save_Pic = new QPushButton(frame);
        Save_Pic->setObjectName(QStringLiteral("Save_Pic"));
        sizePolicy1.setHeightForWidth(Save_Pic->sizePolicy().hasHeightForWidth());
        Save_Pic->setSizePolicy(sizePolicy1);
        Save_Pic->setMaximumSize(QSize(200, 16777215));
        Save_Pic->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(Save_Pic, 0, 2, 1, 2);


        gridLayout->addWidget(frame, 0, 0, 1, 3);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        gridLayout_3 = new QGridLayout(widget_8);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 3, 3, 1, 1);

        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 3, 0, 1, 1);

        End_dateEdit = new QDateEdit(widget_8);
        End_dateEdit->setObjectName(QStringLiteral("End_dateEdit"));
        sizePolicy1.setHeightForWidth(End_dateEdit->sizePolicy().hasHeightForWidth());
        End_dateEdit->setSizePolicy(sizePolicy1);
        End_dateEdit->setMinimumSize(QSize(120, 0));
        End_dateEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        End_dateEdit->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        gridLayout_3->addWidget(End_dateEdit, 3, 5, 1, 1);

        Start_dateEdit = new QDateEdit(widget_8);
        Start_dateEdit->setObjectName(QStringLiteral("Start_dateEdit"));
        sizePolicy1.setHeightForWidth(Start_dateEdit->sizePolicy().hasHeightForWidth());
        Start_dateEdit->setSizePolicy(sizePolicy1);
        Start_dateEdit->setMinimumSize(QSize(120, 0));
        Start_dateEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Start_dateEdit->setReadOnly(false);
        Start_dateEdit->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));

        gridLayout_3->addWidget(Start_dateEdit, 3, 1, 1, 1);

        label_2 = new QLabel(widget_8);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label_11 = new QLabel(widget_8);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 1, 3, 1, 1);

        UID_lineEdit = new QLineEdit(widget_8);
        UID_lineEdit->setObjectName(QStringLiteral("UID_lineEdit"));
        sizePolicy1.setHeightForWidth(UID_lineEdit->sizePolicy().hasHeightForWidth());
        UID_lineEdit->setSizePolicy(sizePolicy1);
        UID_lineEdit->setMinimumSize(QSize(100, 0));
        UID_lineEdit->setMaximumSize(QSize(120, 16777215));
        UID_lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(UID_lineEdit, 1, 5, 1, 1);

        Count_Pic = new QLineEdit(widget_8);
        Count_Pic->setObjectName(QStringLiteral("Count_Pic"));
        sizePolicy1.setHeightForWidth(Count_Pic->sizePolicy().hasHeightForWidth());
        Count_Pic->setSizePolicy(sizePolicy1);
        Count_Pic->setMinimumSize(QSize(100, 0));
        Count_Pic->setMaximumSize(QSize(120, 16777215));
        Count_Pic->setCursor(QCursor(Qt::IBeamCursor));
        Count_Pic->setMouseTracking(true);
        Count_Pic->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Count_Pic->setReadOnly(true);

        gridLayout_3->addWidget(Count_Pic, 1, 1, 1, 1);


        gridLayout->addWidget(widget_8, 1, 0, 1, 3);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        gridLayout_2->addWidget(widget_4, 0, 2, 1, 1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        progressBar = new QProgressBar(widget_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        gridLayout_2->addWidget(widget_3, 1, 0, 1, 3);

        gridLayout_2->setColumnStretch(0, 3);

        verticalLayout_2->addWidget(widget);

        choosePictureClass->setCentralWidget(centralWidget);

        retranslateUi(choosePictureClass);

        QMetaObject::connectSlotsByName(choosePictureClass);
    } // setupUi

    void retranslateUi(QMainWindow *choosePictureClass)
    {
        choosePictureClass->setWindowTitle(QApplication::translate("choosePictureClass", "choosePicture", 0));
        label_8->setText(QApplication::translate("choosePictureClass", "\346\227\245\345\277\227\346\226\207\344\273\266", 0));
        Log_checkBox->setText(QApplication::translate("choosePictureClass", "Log\346\226\207\344\273\266", 0));
        Config_checkBox->setText(QApplication::translate("choosePictureClass", "\351\205\215\347\275\256\346\226\207\344\273\266", 0));
        label_10->setText(QApplication::translate("choosePictureClass", "Log/\351\205\215\347\275\256\346\226\207\344\273\266", 0));
        label_5->setText(QApplication::translate("choosePictureClass", "FOB\345\215\241", 0));
        AllFob_checkBox->setText(QApplication::translate("choosePictureClass", "\345\205\250\351\200\211", 0));
        Yang_checkBox->setText(QApplication::translate("choosePictureClass", "\351\230\263\346\200\247", 0));
        RouYang_checkBox->setText(QApplication::translate("choosePictureClass", "\345\274\261\351\230\263\346\200\247", 0));
        Yin_checkBox->setText(QApplication::translate("choosePictureClass", "\351\230\264\346\200\247", 0));
        AllcheckBox->setText(QApplication::translate("choosePictureClass", "\345\244\215\351\200\211", 0));
        label_3->setText(QApplication::translate("choosePictureClass", "\347\273\206\350\203\236", 0));
        AllCell_checkBox->setText(QApplication::translate("choosePictureClass", "\345\205\250\351\200\211", 0));
        RedCell_checkBox->setText(QApplication::translate("choosePictureClass", "\347\272\242\347\273\206\350\203\236", 0));
        WhiteCell_checkBox->setText(QApplication::translate("choosePictureClass", "\347\231\275\347\273\206\350\203\236", 0));
        Mold_checkBox->setText(QApplication::translate("choosePictureClass", "\351\234\211\350\217\214", 0));
        label_4->setText(QApplication::translate("choosePictureClass", "\351\242\234\350\211\262", 0));
        AllColor_checkBox->setText(QApplication::translate("choosePictureClass", "\345\205\250\351\200\211", 0));
        Yellow_checkBox->setText(QApplication::translate("choosePictureClass", "\351\273\204\350\211\262", 0));
        Red_checkBox->setText(QApplication::translate("choosePictureClass", "\347\272\242\350\211\262", 0));
        Brown_checkBox->setText(QApplication::translate("choosePictureClass", "\350\244\220\350\211\262", 0));
        Black_checkBox->setText(QApplication::translate("choosePictureClass", "\351\273\221\350\211\262", 0));
        label_9->setText(QApplication::translate("choosePictureClass", "\346\200\247\347\212\266", 0));
        AllTraits_checkBox->setText(QApplication::translate("choosePictureClass", "\345\205\250\351\200\211", 0));
        Rash_checkBox->setText(QApplication::translate("choosePictureClass", "\347\250\200\344\276\277", 0));
        Soft_checkBox->setText(QApplication::translate("choosePictureClass", "\350\275\257\344\276\277", 0));
        leftTurn->setText(QApplication::translate("choosePictureClass", "\344\270\212\344\270\200\345\274\240", 0));
        RightUid->setText(QApplication::translate("choosePictureClass", "\344\270\213\344\270\252\346\240\267\346\234\254", 0));
        LeftUid->setText(QApplication::translate("choosePictureClass", "\344\270\212\344\270\252\346\240\267\346\234\254", 0));
        RightTurn->setText(QApplication::translate("choosePictureClass", "\344\270\213\344\270\200\345\274\240", 0));
        Find_Button->setText(QApplication::translate("choosePictureClass", "\346\237\245\350\257\242", 0));
        Save_Pic->setText(QApplication::translate("choosePictureClass", "\345\257\274\345\207\272\345\233\276\347\211\207", 0));
        label_7->setText(QApplication::translate("choosePictureClass", "\347\273\223\346\235\237\346\227\266\351\227\264", 0));
        label_6->setText(QApplication::translate("choosePictureClass", "\350\265\267\345\247\213\346\227\266\351\227\264", 0));
        label_2->setText(QApplication::translate("choosePictureClass", "\345\233\276\347\211\207\344\270\252\346\225\260", 0));
        label_11->setText(QApplication::translate("choosePictureClass", "UID", 0));
        Count_Pic->setText(QApplication::translate("choosePictureClass", "0/0", 0));
        label->setText(QApplication::translate("choosePictureClass", "\350\277\233\345\272\246\346\235\241", 0));
    } // retranslateUi

};

namespace Ui {
    class choosePictureClass: public Ui_choosePictureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEPICTURE_H
