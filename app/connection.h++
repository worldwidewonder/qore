/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#ifndef QORE_APP_CONNECTION_H
#define QORE_APP_CONNECTION_H

#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

class QWebSocket;

namespace qore
{
  namespace app
  {
    class connection : public QGroupBox
    {
        Q_OBJECT

      public:
        connection(QWebSocket& socket,
                   QWidget* parent = 0);

      signals:
        void connection_OK();

      public slots:
        void OK_button_clicked();

      private:
        QWebSocket& socket;
        QLineEdit* input_hostname;
        QLineEdit* input_port;
        //QLineEdit* input_username;
        //QLineEdit* input_password;

        QDialogButtonBox* buttons;
    };
  }
}

#endif // QORE_APP_CONNECTION_H
