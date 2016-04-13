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
        RPC_epilog(", \"id\": 1 }"),
        response()
    {
      connect(&socket, &QWebSocket::connected,
              this, &client::connected);
    }

    // connection
    void client::connect_socket(QString host,
                                int port)
    {
      socket.open(host + QStringLiteral(":") + port + QStringLiteral("/jsonrpc"));
    }
    void client::connected()
    {
      connect(&socket, &QWebSocket::textMessageReceived, this, &client::record_response);
    }

    // input
    void client::keypress(int keycode)
    {
      Qt::Key key = static_cast<Qt::Key>(keycode);
      // TODO: use QHash
      // TODO: fast-forward, rewind, next, previous
      // ["left","right","up","down","pageup","pagedown","select","highlight","parentdir","parentfolder","back","menu",
      //  "previousmenu","info","pause","stop","skipnext","skipprevious", "fullscreen","aspectratio","stepforward",
      //  "stepback","bigstepforward","bigstepback", "chapterorbigstepforward","chapterorbigstepback","osd",
      //  "showsubtitles","nextsubtitle","cyclesubtitle","codecinfo","nextpicture","previouspicture","zoomout",
      //  "zoomin","playlist","queue","zoomnormal","zoomlevel1","zoomlevel2","zoomlevel3","zoomlevel4","zoomlevel5",
      //  "zoomlevel6","zoomlevel7","zoomlevel8","zoomlevel9","nextcalibration","resetcalibration","analogmove",
      //  "analogmovex","analogmovey","rotate","rotateccw","close","subtitledelayminus","subtitledelay",
      //  "subtitledelayplus","audiodelayminus","audiodelay","audiodelayplus","subtitleshiftup","subtitleshiftdown",
      //  "subtitlealign","audionextlanguage","verticalshiftup","verticalshiftdown","nextresolution",
      //  "audiotoggledigital","number0","number1","number2","number3","number4","number5","number6","number7",
      //  "number8","number9","smallstepback","fastforward","rewind","play","playpause","switchplayer","delete","copy",
      //  "move","screenshot","rename","togglewatched","scanitem","reloadkeymaps","volumeup","volumedown","mute",
      //  "backspace","scrollup","scrolldown","analogfastforward","analogrewind","moveitemup","moveitemdown",
      //  "contextmenu","shift","symbols","cursorleft","cursorright","showtime","analogseekforward","analogseekback",
      //  "showpreset","nextpreset","previouspreset","lockpreset","randompreset","increasevisrating",
      //  "decreasevisrating","showvideomenu","enter","increaserating","decreaserating","togglefullscreen","nextscene",
      //  "previousscene","nextletter","prevletter","jumpsms2","jumpsms3","jumpsms4","jumpsms5","jumpsms6","jumpsms7",
      //  "jumpsms8","jumpsms9","filter","filterclear","filtersms2","filtersms3","filtersms4","filtersms5","filtersms6",
      //  "filtersms7","filtersms8","filtersms9","firstpage","lastpage","guiprofile","red","green","yellow","blue",
      //  "increasepar","decreasepar","volampup","volampdown","volumeamplification","createbookmark",
      //  "createepisodebookmark","settingsreset","settingslevelchange","stereomode","nextstereomode",
      //  "previousstereomode","togglestereomode","stereomodetomono","channelup","channeldown","previouschannelgroup",
      //  "nextchannelgroup","playpvr","playpvrtv","playpvrradio","record","leftclick","rightclick","middleclick",
      //  "doubleclick","longclick","wheelup","wheeldown","mousedrag","mousemove","tap","longpress","pangesture",
      //  "zoomgesture","rotategesture","swipeleft","swiperight","swipeup","swipedown","error","noop"]
      switch(key)
      {
        case Qt::Key_Up:
          call_method("Input.Up");
          break;
        case Qt::Key::Key_Down:
          call_method("Input.Down");
          break;
        case Qt::Key_Left:
          call_method("Input.Left");
          break;
        case Qt::Key_Right:
          call_method("Input.Right");
          break;
        case Qt::Key_Enter:
          call_method("Input.Select");
          break;
        case Qt::Key_Back:
          call_method("Input.Back");
          break;
        case Qt::Key_Menu:
          call_method("Input.Menu");
          break;
        case Qt::Key_Home:
          call_method("Input.Home");
          break;
        case Qt::Key_Info:
          call_method("Input.Info");
          break;
        case Qt::Key_MediaPlay:
          call_method("Input.ExecuteAction", {{ "action", "play" }});
          break;
        case Qt::Key_MediaPause:
          call_method("Input.ExecuteAction", {{ "action", "pause" }});
          break;
        case Qt::Key_MediaStop:
          call_method("Input.ExecuteAction", {{ "action", "stop" }});
          break;
        case Qt::Key_AudioForward:
          call_method("Input.ExecuteAction", {{ "action", "fastforward" }});
          break;
        case Qt::Key_AudioRewind:
          call_method("Input.ExecuteAction", {{ "action", "rewind" }});
          break;
        case Qt::Key_MediaNext:
          call_method("Input.ExecuteAction", {{ "action", "skipnext" }});
          break;
        case Qt::Key_MediaPrevious:
          call_method("Input.ExecuteAction", {{ "action", "skipprevious" }});
          break;
        default:
          call_method("Input.ExecuteAction", {{ "action", "noop" }});
      }
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

    void client::call_method(QString method, QList<QPair<QString, QString>> parameters)
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
      request += RPC_epilog;
      qDebug() << "Sending request: \'" << request << "\'.";

      socket.sendTextMessage(request);
    }
    void client::record_response(QString response)
    {
      qDebug() << "Response received: \'" << response << "\'.";
      this->response = response;
    }
  }
}
