/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#include "client.h++"

#include <QtCore/QPair>

namespace qore
{
  namespace api
  {
    client::client(QObject *parent)
      : QObject(parent),
        RPC_prolog("{ \"jsonrpc\": \"2.0\""),
        RPC_epilog(", \"id\": 1 }")
    {}

    // connection
    void client::connect_socket(QString host,
                                int port)
    {
      socket.open(host + QStringLiteral(":") + port + QStringLiteral("/jsonrpc"));
      connect(&socket, &QWebSocket::textMessageReceived,
              this, &client::print_response);
      connect(&socket, &QWebSocket::binaryMessageReceived,
              this, &client::print_binary_response);
    }

    // input
    void client::keypress(int keycode)
    {
      Qt::Key key = static_cast<Qt::Key>(keycode);
      // TODO: use QHash
      // TODO: fast-forward, rewind, next, previous
      // ["left","right","up","down","pageup","pagedown","select","highlight","parentdir","parentfolder","back","menu","previousmenu","info","pause","stop","skipnext","skipprevious","fullscreen","aspectratio","stepforward","stepback","bigstepforward","bigstepback","chapterorbigstepforward","chapterorbigstepback","osd","showsubtitles","nextsubtitle","cyclesubtitle","codecinfo","nextpicture","previouspicture","zoomout","zoomin","playlist","queue","zoomnormal","zoomlevel1","zoomlevel2","zoomlevel3","zoomlevel4","zoomlevel5","zoomlevel6","zoomlevel7","zoomlevel8","zoomlevel9","nextcalibration","resetcalibration","analogmove","analogmovex","analogmovey","rotate","rotateccw","close","subtitledelayminus","subtitledelay","subtitledelayplus","audiodelayminus","audiodelay","audiodelayplus","subtitleshiftup","subtitleshiftdown","subtitlealign","audionextlanguage","verticalshiftup","verticalshiftdown","nextresolution","audiotoggledigital","number0","number1","number2","number3","number4","number5","number6","number7","number8","number9","smallstepback","fastforward","rewind","play","playpause","switchplayer","delete","copy","move","screenshot","rename","togglewatched","scanitem","reloadkeymaps","volumeup","volumedown","mute","backspace","scrollup","scrolldown","analogfastforward","analogrewind","moveitemup","moveitemdown","contextmenu","shift","symbols","cursorleft","cursorright","showtime","analogseekforward","analogseekback","showpreset","nextpreset","previouspreset","lockpreset","randompreset","increasevisrating","decreasevisrating","showvideomenu","enter","increaserating","decreaserating","togglefullscreen","nextscene","previousscene","nextletter","prevletter","jumpsms2","jumpsms3","jumpsms4","jumpsms5","jumpsms6","jumpsms7","jumpsms8","jumpsms9","filter","filterclear","filtersms2","filtersms3","filtersms4","filtersms5","filtersms6","filtersms7","filtersms8","filtersms9","firstpage","lastpage","guiprofile","red","green","yellow","blue","increasepar","decreasepar","volampup","volampdown","volumeamplification","createbookmark","createepisodebookmark","settingsreset","settingslevelchange","stereomode","nextstereomode","previousstereomode","togglestereomode","stereomodetomono","channelup","channeldown","previouschannelgroup","nextchannelgroup","playpvr","playpvrtv","playpvrradio","record","leftclick","rightclick","middleclick","doubleclick","longclick","wheelup","wheeldown","mousedrag","mousemove","tap","longpress","pangesture","zoomgesture","rotategesture","swipeleft","swiperight","swipeup","swipedown","error","noop"]
      QString jsonkey;
      switch(key)
      {
        case Qt::Key_Up:
          jsonkey = "up";
          break;
        case Qt::Key::Key_Down:
          jsonkey = "down";
          break;
        case Qt::Key_Left:
          jsonkey = "left";
          break;
        case Qt::Key_Right:
          jsonkey = "right";
          break;
        case Qt::Key_Enter:
          jsonkey = "enter";
          break;
        case Qt::Key_MediaPlay:
          jsonkey = "play";
          break;
        case Qt::Key_MediaPause:
          jsonkey = "pause";
          break;
        case Qt::Key_MediaStop:
          jsonkey = "stop";
          break;
        default:
          jsonkey = "noop";
      }
      call_method("Input.ExecuteAction", {{ "action", jsonkey }});
    }

    QList<artist> client::get_artists(QPair<int, int> range)
    {
      QList<artist> result;

      return result;
    }

    QList<album> client::get_albums(QPair<int, int> range)
    {
      QList<album> result;

      return result;
    }

    QList<song> client::get_songs(QPair<int, int> range)
    {
      QList<song> result;

      return result;
    }

    QString client::call_method(QString method, QList<QPair<QString, QString>> parameters)
    {
      QString request = RPC_prolog + ",\"method\":\"" + method + '\"';

      if(!parameters.empty())
      {
        QString params = ",\"params\":{\"" + parameters.first().first + "\":\"" + parameters.first().second + "\"";
        for(int i = 1; i < parameters.length(); ++i)
        {
          const auto& parameter = parameters[i];
          params += ",\"" + parameter.first + "\":\"" + parameter.second + '\"';
        }
        params += '}';
        request += params;
      }
      qDebug() << request;

      socket.sendTextMessage(request);
      socket.flush(); // ensure data is actually sent

      return QStringLiteral("");
    }

    void client::print_response(QString response)
    {
      qDebug() << response;
    }
    void client::print_binary_response(QByteArray response)
    {
      qDebug() << QString::fromUtf8(response);
    }
  }
}
