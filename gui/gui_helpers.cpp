// helpers.cpp
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#include "gui_helpers.h"
QString Ui::toqstr(std::string input)
{
  return QString::fromStdString(input);
}

//////////////////////////////////////////////////////////////////////
// $Log:$
//