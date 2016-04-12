/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

/*
 * Client
 * Central Kodi client providing access to all functionality:
 *  - Connection
 *  - Input commands
 *  - ... (TODO)
 */
#ifndef QORE_API_CLIENT_H
#define QORE_API_CLIENT_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include <QtCore>

#include "audio/album.h++"
#include "audio/artist.h++"
#include "audio/song.h++"

namespace qore
{
  namespace api
  {
    // constants
    static constexpr QPair<int, int> default_range = {0,25};

    class client : public QObject
    {
        Q_OBJECT
      public:
        explicit client(QObject *parent = 0);

        QWebSocket socket;

      signals:

      public slots:
        // connection
        void connect_socket(QString host,
                            int port);

        // input
        void keypress(int keycode);

        // audio
        QList<artist> get_artists(QPair<int, int> range = default_range);
        QList<album> get_albums(QPair<int, int> range = default_range);
        QList<song> get_songs(QPair<int, int> range = default_range);

      private:
        QString RPC_prolog;
        QString RPC_epilog;

        QString call_method(QString method, QList<QPair<QString, QString>> parameters = {});

      private slots:
        void print_response(QString response);
        void print_binary_response(QByteArray response);
    };

  }
}

#endif // QORE_API_CLIENT_H
