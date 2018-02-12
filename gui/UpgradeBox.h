// UpgradeBox.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef UPGRADE_BOX_H
#define UPGRADE_BOX_H 1

#include <QApplication>
#include <QtWidgets>
#include "ship/upgrades_helper.h"
#include "main/Game.h"
#include "ship/UpgradesManager.h"
#include "gui_helpers.h"

class UpgradeBox : public QWidget
{
  Q_OBJECT
 private:
  QHBoxLayout* _main_layout;// = new QHBoxLayout(this);
  QPushButton* _button;// = new QPushButton(this);
  QLabel* _price;// = new QLabel(this);
  QLabel* _remaining_time;// = new QLabel(this);
  Upgrade_ID _upgrade_id;
  QString _button_name;
  QString _message;

 public:
  UpgradeBox(Upgrade_ID id, Game* game, QWidget *parent = 0);
  UpgradeBox(const UpgradeBox& copy);
  ~UpgradeBox();

  Upgrade_ID get_id() const;

  void update_box(const UpgradesManager* upgrades);
  void set_box_visibility(bool visible);
  void update_texts(QString price, QString time);
  void set_button_availability(bool available);


private slots:
  void click_button();

 signals:
  void button_pressed(Upgrade_ID id);


};


#endif // _H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
