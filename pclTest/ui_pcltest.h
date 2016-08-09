/********************************************************************************
** Form generated from reading UI file 'pcltest.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLTEST_H
#define UI_PCLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pclTest
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QWidget *pclTest)
    {
        if (pclTest->objectName().isEmpty())
            pclTest->setObjectName(QStringLiteral("pclTest"));
        pclTest->resize(600, 400);
        menuBar = new QMenuBar(pclTest);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        mainToolBar = new QToolBar(pclTest);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        centralWidget = new QWidget(pclTest);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        statusBar = new QStatusBar(pclTest);
        statusBar->setObjectName(QStringLiteral("statusBar"));

        retranslateUi(pclTest);

        QMetaObject::connectSlotsByName(pclTest);
    } // setupUi

    void retranslateUi(QWidget *pclTest)
    {
        pclTest->setWindowTitle(QApplication::translate("pclTest", "pclTest", 0));
    } // retranslateUi

};

namespace Ui {
    class pclTest: public Ui_pclTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLTEST_H
