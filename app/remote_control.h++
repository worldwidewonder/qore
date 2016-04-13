/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <QtWidgets/QStyle>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "client.h++"

class QWebSocket;

namespace qore
{
  namespace app
  {
    class remote_control : public QWidget
    {
        Q_OBJECT
      public:
        explicit remote_control(const api::client& client,
                                QWidget* parent = 0);

      signals:

      public slots:

      private:
        const api::client& client;
        const QStyle* style;

        QSignalMapper* signal_mapper;
        QPushButton* up;
        QPushButton* down;
        QPushButton* left;
        QPushButton* right;
        QPushButton* center;
        QPushButton* back;
        QPushButton* context;

        QPushButton* play;
        QPushButton* pause;
        QPushButton* stop;
        QPushButton* fast_forward;
        QPushButton* rewind;
        QPushButton* next;
        QPushButton* previous;
    };
  }
}

#endif // REMOTE_CONTROL_H
