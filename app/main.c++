/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#include <QtWidgets/QApplication>

#include "qore_widget.h++"

using namespace qore::app;

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  qore_widget widget;
  widget.show();

  return a.exec();
}
