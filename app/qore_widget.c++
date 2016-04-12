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

#include "connection.h++"
#include "remote_control.h++"

namespace qore
{
  namespace app
  {
    qore_widget::qore_widget(QWidget* parent)
      : QMainWindow(parent),
        client(this),
        connection(new app::connection(client.socket, this)),
        remote_control(new app::remote_control(client, this))
    {
      setCentralWidget(connection);

      connect(connection, &connection::connection_OK,
              this, &qore_widget::navigate_to_remote_control);
    }

    void qore_widget::navigate_to_remote_control()
    {
      // Layout setup
      setCentralWidget(remote_control);
    }
  }
}
