// UpgradeBox.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "UpgradeBox.h"

// Constructur
UpgradeBox::UpgradeBox(Upgrade_ID id, Game* game, QWidget *parent)
    : _upgrade_id(id), QWidget(parent)
{
  _main_layout = new QHBoxLayout(this);
  _button = new QPushButton();
  _button_name = Ui::toqstr(game->manage_upgrades()->get_upgrade_name(id));
  _price = new QLabel();
  _remaining_time = new QLabel();

  _button->setText(_button_name);
  _price->setText("Price");
  _remaining_time->setText("Time");

  _main_layout->addWidget(_button);
  _main_layout->addWidget(_price);
  _main_layout->addWidget(_remaining_time);

  setMinimumSize(QSize(361, 31));

  QObject::connect(_button, SIGNAL(clicked()), this, SLOT(click_button()));
}

UpgradeBox::UpgradeBox(const UpgradeBox& copy)
{
  _main_layout = new QHBoxLayout();
  _button = new QPushButton();
  _price = new QLabel();
  _remaining_time = new QLabel();
}

UpgradeBox::~UpgradeBox()
{
  delete _button;
  delete _price;
  delete _remaining_time;
  delete _main_layout;
}

Upgrade_ID UpgradeBox::get_id() const
{
  return _upgrade_id;
}

void UpgradeBox::update_box(const UpgradesManager* upgrades)
{

  set_button_availability(upgrades->is_affordable(_upgrade_id, 1));
  // If upgrade is not unique, upgrade button text
  if (!upgrades->is_unique(_upgrade_id)) {

    int level = upgrades->get_upgrade_level(_upgrade_id);
    if (level > 0) {
      QString name_level;
      name_level += " (";
      name_level += QString::number(level);
      name_level += ")";

      _button->setText(_button_name + name_level);

    }
  }

  // Set labels
  _price->setText(Ui::toqstr(upgrades->get_price_increase_level(_upgrade_id, 1).to_string()));
  _remaining_time->setText(Ui::toqstr(upgrades->time_until_affordable(_upgrade_id, 1).to_string()));

}


// Slot
void UpgradeBox::click_button()
{
  emit button_pressed(_upgrade_id);
}

void UpgradeBox::set_box_visibility(bool visible)
{
  if (visible)
    this->show();
  else
    this->hide();
}

void UpgradeBox::set_button_availability(bool available)
{
  _button->setEnabled(available);
}


void UpgradeBox::update_texts(QString price, QString time){
  _price->setText(price);
  _remaining_time->setText(time);
}
//////////////////////////////////////////////////////////////////////
// $Log:$
//
