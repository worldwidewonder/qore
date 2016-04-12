/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#include "connection.h++"

#include <QtGui/QIntValidator>
#include <QtWebSockets/QWebSocket>
#include <QtNetwork/QHostAddress>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

namespace qore
{
  namespace app
  {
    connection::connection(QWebSocket& socket,
                           QWidget* parent)
      : QGroupBox(tr("Connection settings"), parent),
        socket(socket),
        input_hostname(new QLineEdit(socket.peerAddress().toString(), this)),
        input_port(new QLineEdit(QString::number(socket.peerPort()), this)),
        //input_username(new QLineEdit(this)),
        //input_password(new QLineEdit(this)),
        buttons(new QDialogButtonBox(QDialogButtonBox::Ok, this))
    {
      // Widget setup
      input_port->setValidator(new QIntValidator(input_port));
      //input_password->setEchoMode(QLineEdit::Password);

      // Layout setup
      QFormLayout* layout = new QFormLayout(this);
      layout->addRow(new QLabel(tr("Hostname"), this), input_hostname);
      layout->addRow(new QLabel(tr("Port"), this), input_port);
      //layout->addRow(new QLabel(tr("Username"), this), input_username);
      //layout->addRow(new QLabel(tr("Password"), this), input_password);

      buttons->button(QDialogButtonBox::Ok)->setText(tr("Verify and apply"));
      layout->addWidget(buttons);

      // Connections
      connect(buttons, &QDialogButtonBox::accepted,
              this, &connection::OK_button_clicked);
    }

    void connection::OK_button_clicked()
    {
      QUrl url = QStringLiteral("ws://") + input_hostname->text()
                 + QStringLiteral(":") + input_port->text()
                 + QStringLiteral("/jsonrpc");
      qDebug() << "Opening websocket connection with \'" << url << "\'.";
      socket.open(url);

      emit connection_OK();
    }
  }
}
