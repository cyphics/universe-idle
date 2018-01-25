/********************************************************************************
** Form generated from reading UI file 'UniverseIdleGUIOwzDTV.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UNIVERSEIDLEGUIOWZDTV_H
#define UNIVERSEIDLEGUIOWZDTV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UniverseIdleMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *mainGroup;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *displayLayout;
    QGroupBox *displayGroup;
    QWidget *verticalLayoutWidget_2;
    QHBoxLayout *infoLayout;
    QGroupBox *infoGroup;
    QWidget *formLayoutWidget;
    QFormLayout *physics_layout;
    QLabel *speed_label;
    QLabel *speed_value_labep;
    QLabel *distance_label;
    QLabel *distance_value_label;
    QLabel *acceleration_label;
    QLabel *time_label;
    QLabel *time_value_label;
    QLabel *acceleration_value_label;
    QWidget *formLayoutWidget_2;
    QFormLayout *resources_layout;
    QLabel *cinetic_energy_label;
    QLabel *dark_matter_label;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *upgrades_layout;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *small_boost_layout;
    QLabel *small_boost_remaining_time;
    QPushButton *small_boost_button;
    QLabel *small_boost_price;
    QWidget *gridLayoutWidget_3;
    QGridLayout *big_boost_layout;
    QLabel *big_boost_remaining_time;
    QPushButton *big_boost_button;
    QLabel *big_boost_price;
    QWidget *gridLayoutWidget;
    QGridLayout *quitLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UniverseIdleMainWindow)
    {
        if (UniverseIdleMainWindow->objectName().isEmpty())
            UniverseIdleMainWindow->setObjectName(QStringLiteral("UniverseIdleMainWindow"));
        UniverseIdleMainWindow->resize(1113, 917);
        centralwidget = new QWidget(UniverseIdleMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainGroup = new QGroupBox(centralwidget);
        mainGroup->setObjectName(QStringLiteral("mainGroup"));
        verticalLayoutWidget = new QWidget(mainGroup);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 1051, 721));
        displayLayout = new QVBoxLayout(verticalLayoutWidget);
        displayLayout->setObjectName(QStringLiteral("displayLayout"));
        displayLayout->setContentsMargins(0, 0, 0, 0);
        displayGroup = new QGroupBox(verticalLayoutWidget);
        displayGroup->setObjectName(QStringLiteral("displayGroup"));
        verticalLayoutWidget_2 = new QWidget(displayGroup);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(11, 29, 591, 681));
        infoLayout = new QHBoxLayout(verticalLayoutWidget_2);
        infoLayout->setObjectName(QStringLiteral("infoLayout"));
        infoLayout->setContentsMargins(0, 0, 0, 0);
        infoGroup = new QGroupBox(verticalLayoutWidget_2);
        infoGroup->setObjectName(QStringLiteral("infoGroup"));
        formLayoutWidget = new QWidget(infoGroup);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 441, 81));
        physics_layout = new QFormLayout(formLayoutWidget);
        physics_layout->setObjectName(QStringLiteral("physics_layout"));
        physics_layout->setContentsMargins(0, 0, 0, 0);
        speed_label = new QLabel(formLayoutWidget);
        speed_label->setObjectName(QStringLiteral("speed_label"));

        physics_layout->setWidget(0, QFormLayout::LabelRole, speed_label);

        speed_value_labep = new QLabel(formLayoutWidget);
        speed_value_labep->setObjectName(QStringLiteral("speed_value_labep"));

        physics_layout->setWidget(0, QFormLayout::FieldRole, speed_value_labep);

        distance_label = new QLabel(formLayoutWidget);
        distance_label->setObjectName(QStringLiteral("distance_label"));

        physics_layout->setWidget(2, QFormLayout::LabelRole, distance_label);

        distance_value_label = new QLabel(formLayoutWidget);
        distance_value_label->setObjectName(QStringLiteral("distance_value_label"));

        physics_layout->setWidget(2, QFormLayout::FieldRole, distance_value_label);

        acceleration_label = new QLabel(formLayoutWidget);
        acceleration_label->setObjectName(QStringLiteral("acceleration_label"));

        physics_layout->setWidget(1, QFormLayout::LabelRole, acceleration_label);

        time_label = new QLabel(formLayoutWidget);
        time_label->setObjectName(QStringLiteral("time_label"));

        physics_layout->setWidget(3, QFormLayout::LabelRole, time_label);

        time_value_label = new QLabel(formLayoutWidget);
        time_value_label->setObjectName(QStringLiteral("time_value_label"));

        physics_layout->setWidget(3, QFormLayout::FieldRole, time_value_label);

        acceleration_value_label = new QLabel(formLayoutWidget);
        acceleration_value_label->setObjectName(QStringLiteral("acceleration_value_label"));

        physics_layout->setWidget(1, QFormLayout::FieldRole, acceleration_value_label);

        formLayoutWidget_2 = new QWidget(infoGroup);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 140, 291, 51));
        resources_layout = new QFormLayout(formLayoutWidget_2);
        resources_layout->setObjectName(QStringLiteral("resources_layout"));
        resources_layout->setContentsMargins(0, 0, 0, 0);
        cinetic_energy_label = new QLabel(formLayoutWidget_2);
        cinetic_energy_label->setObjectName(QStringLiteral("cinetic_energy_label"));

        resources_layout->setWidget(0, QFormLayout::LabelRole, cinetic_energy_label);

        dark_matter_label = new QLabel(formLayoutWidget_2);
        dark_matter_label->setObjectName(QStringLiteral("dark_matter_label"));

        resources_layout->setWidget(1, QFormLayout::LabelRole, dark_matter_label);


        infoLayout->addWidget(infoGroup);

        verticalLayoutWidget_6 = new QWidget(displayGroup);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(610, 30, 421, 681));
        upgrades_layout = new QVBoxLayout(verticalLayoutWidget_6);
        upgrades_layout->setObjectName(QStringLiteral("upgrades_layout"));
        upgrades_layout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget_6);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 30, 341, 24));
        small_boost_layout = new QGridLayout(gridLayoutWidget_2);
        small_boost_layout->setObjectName(QStringLiteral("small_boost_layout"));
        small_boost_layout->setContentsMargins(0, 0, 0, 0);
        small_boost_remaining_time = new QLabel(gridLayoutWidget_2);
        small_boost_remaining_time->setObjectName(QStringLiteral("small_boost_remaining_time"));

        small_boost_layout->addWidget(small_boost_remaining_time, 0, 3, 1, 1);

        small_boost_button = new QPushButton(gridLayoutWidget_2);
        small_boost_button->setObjectName(QStringLiteral("small_boost_button"));

        small_boost_layout->addWidget(small_boost_button, 0, 0, 1, 1);

        small_boost_price = new QLabel(gridLayoutWidget_2);
        small_boost_price->setObjectName(QStringLiteral("small_boost_price"));

        small_boost_layout->addWidget(small_boost_price, 0, 2, 1, 1);

        gridLayoutWidget_3 = new QWidget(groupBox);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 120, 341, 24));
        big_boost_layout = new QGridLayout(gridLayoutWidget_3);
        big_boost_layout->setObjectName(QStringLiteral("big_boost_layout"));
        big_boost_layout->setContentsMargins(0, 0, 0, 0);
        big_boost_remaining_time = new QLabel(gridLayoutWidget_3);
        big_boost_remaining_time->setObjectName(QStringLiteral("big_boost_remaining_time"));

        big_boost_layout->addWidget(big_boost_remaining_time, 0, 3, 1, 1);

        big_boost_button = new QPushButton(gridLayoutWidget_3);
        big_boost_button->setObjectName(QStringLiteral("big_boost_button"));

        big_boost_layout->addWidget(big_boost_button, 0, 0, 1, 1);

        big_boost_price = new QLabel(gridLayoutWidget_3);
        big_boost_price->setObjectName(QStringLiteral("big_boost_price"));

        big_boost_layout->addWidget(big_boost_price, 0, 2, 1, 1);


        upgrades_layout->addWidget(groupBox);


        displayLayout->addWidget(displayGroup);

        gridLayoutWidget = new QWidget(mainGroup);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(890, 760, 160, 80));
        quitLayout = new QGridLayout(gridLayoutWidget);
        quitLayout->setObjectName(QStringLiteral("quitLayout"));
        quitLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(mainGroup);

        UniverseIdleMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UniverseIdleMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1113, 20));
        UniverseIdleMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UniverseIdleMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UniverseIdleMainWindow->setStatusBar(statusbar);

        retranslateUi(UniverseIdleMainWindow);

        QMetaObject::connectSlotsByName(UniverseIdleMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UniverseIdleMainWindow)
    {
        UniverseIdleMainWindow->setWindowTitle(QApplication::translate("UniverseIdleMainWindow", "Universe Idle", nullptr));
        mainGroup->setTitle(QApplication::translate("UniverseIdleMainWindow", "main group", nullptr));
        displayGroup->setTitle(QApplication::translate("UniverseIdleMainWindow", "display Group", nullptr));
        infoGroup->setTitle(QApplication::translate("UniverseIdleMainWindow", "infoBox", nullptr));
        speed_label->setText(QApplication::translate("UniverseIdleMainWindow", "Speed :", nullptr));
        speed_value_labep->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
        distance_label->setText(QApplication::translate("UniverseIdleMainWindow", "Distance traveled :", nullptr));
        distance_value_label->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
        acceleration_label->setText(QApplication::translate("UniverseIdleMainWindow", "Acceleration : ", nullptr));
        time_label->setText(QApplication::translate("UniverseIdleMainWindow", "Time until destination :", nullptr));
        time_value_label->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
        acceleration_value_label->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
        cinetic_energy_label->setText(QApplication::translate("UniverseIdleMainWindow", "Cinetic energy :", nullptr));
        dark_matter_label->setText(QApplication::translate("UniverseIdleMainWindow", "Dark Matter :", nullptr));
        groupBox->setTitle(QApplication::translate("UniverseIdleMainWindow", "GroupBox", nullptr));
        small_boost_remaining_time->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
        small_boost_button->setText(QApplication::translate("UniverseIdleMainWindow", "Small boost", nullptr));
        small_boost_price->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
        big_boost_remaining_time->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
        big_boost_button->setText(QApplication::translate("UniverseIdleMainWindow", "Small boost", nullptr));
        big_boost_price->setText(QApplication::translate("UniverseIdleMainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UniverseIdleMainWindow: public Ui_UniverseIdleMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UNIVERSEIDLEGUIOWZDTV_H
