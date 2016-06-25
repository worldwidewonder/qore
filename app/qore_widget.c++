/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#include "qore_widget.h++"

#include <QtWidgets/QTabBar>

#include "connection.h++"
#include "remote_control.h++"

namespace qore
{
  namespace app
  {
    qore_widget::qore_widget(QWidget* parent)
      : QMainWindow(parent),
        client(this),
        //titleBar(addToolBar("Qore")),
        view(new QTabWidget(this)),
        connection(new app::connection(client.socket, view)),
        remote_control(new app::remote_control(client, view))
    {
      qDebug() << "Client should be constructed...";
      /// Widget Setup
      view->setTabPosition(QTabWidget::West);
      view->addTab(connection, style()->standardIcon(QStyle::SP_DriveNetIcon), tr(""));
      view->addTab(remote_control, style()->standardIcon(QStyle::SP_MediaPlay), tr(""));

      /// Layout setup
      setCentralWidget(view);
    }
  }
}
