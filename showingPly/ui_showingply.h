/********************************************************************************
** Form generated from reading UI file 'showingply.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWINGPLY_H
#define UI_SHOWINGPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showingPly
{
public:

    void setupUi(QWidget *showingPly)
    {
        if (showingPly->objectName().isEmpty())
            showingPly->setObjectName(QStringLiteral("showingPly"));
        showingPly->resize(600, 400);

        retranslateUi(showingPly);

        QMetaObject::connectSlotsByName(showingPly);
    } // setupUi

    void retranslateUi(QWidget *showingPly)
    {
        showingPly->setWindowTitle(QApplication::translate("showingPly", "showingPly", 0));
    } // retranslateUi

};

namespace Ui {
    class showingPly: public Ui_showingPly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINGPLY_H
