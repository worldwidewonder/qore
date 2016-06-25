/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#include "remote_control.h++"

#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>

namespace qore
{
  namespace app
  {
#ifdef _MSC_VER
#define default_button_size {48,48}
#else
    constexpr QSize default_button_size {48,48};
#endif
    remote_control::remote_control(const api::client& client,
                                   QWidget* parent)
      : QWidget(parent),
        client(client),
        style(QApplication::style()),
        signal_mapper(new QSignalMapper(this)),
        up(new QPushButton(style->standardIcon(QStyle::SP_ArrowUp), "")),
        down(new QPushButton(style->standardIcon(QStyle::SP_ArrowDown), "")),
        left(new QPushButton(style->standardIcon(QStyle::SP_ArrowLeft), "")),
        right(new QPushButton(style->standardIcon(QStyle::SP_ArrowRight), "")),
        center(new QPushButton(style->standardIcon(QStyle::SP_DialogApplyButton), "")),
        back(new QPushButton(style->standardIcon(QStyle::SP_ArrowBack), "")),
        context(new QPushButton(style->standardIcon(QStyle::SP_MessageBoxQuestion), "")),
        play(new QPushButton(style->standardIcon(QStyle::SP_MediaPlay), "")),
        pause(new QPushButton(style->standardIcon(QStyle::SP_MediaPause), "")),
        stop(new QPushButton(style->standardIcon(QStyle::SP_MediaStop), "")),
        fast_forward(new QPushButton(style->standardIcon(QStyle::SP_MediaSeekForward), "")),
        rewind(new QPushButton(style->standardIcon(QStyle::SP_MediaSeekBackward), "")),
        next(new QPushButton(style->standardIcon(QStyle::SP_MediaSkipForward), "")),
        previous(new QPushButton(style->standardIcon(QStyle::SP_MediaSkipBackward), "")),
        buttons({up, down, left, right, center, back, context, play, pause, stop, fast_forward, rewind, next, previous})
    {
      /// Widget setup
      for(auto& button : buttons)
      {
        button->setFlat(true);
        button->setIconSize(default_button_size);
      }

      /// Layout Setup
      // Navigation buttons
      auto button_grid = new QGridLayout(this);
      button_grid->addWidget(up, 0, 1);
      button_grid->addWidget(left, 1, 0);
      button_grid->addWidget(center, 1, 1);
      button_grid->addWidget(right, 1, 2);
      button_grid->addWidget(back, 2, 0);
      button_grid->addWidget(down, 2, 1);
      button_grid->addWidget(stop, 3, 0);
      button_grid->addWidget(pause, 3, 1);
      button_grid->addWidget(play, 3, 2);

      // Media controls
      auto bottom_grid = new QGridLayout();
      bottom_grid->addWidget(previous, 0, 0);
      bottom_grid->addWidget(rewind, 0, 1);
      bottom_grid->addWidget(fast_forward, 0, 2);
      bottom_grid->addWidget(next, 0, 3);
      button_grid->addLayout(bottom_grid, 4, 0, 1, 3);

      /// Connections
      signal_mapper->setMapping(up, Qt::Key_Up);
      signal_mapper->setMapping(down, Qt::Key_Down);
      signal_mapper->setMapping(left, Qt::Key_Left);
      signal_mapper->setMapping(right, Qt::Key_Right);
      signal_mapper->setMapping(center, Qt::Key_Enter);
      signal_mapper->setMapping(back, Qt::Key_Back);
      signal_mapper->setMapping(context, Qt::Key_Menu);
      signal_mapper->setMapping(play, Qt::Key_MediaPlay);
      signal_mapper->setMapping(pause, Qt::Key_MediaPause);
      signal_mapper->setMapping(stop, Qt::Key_MediaStop);
      signal_mapper->setMapping(fast_forward, Qt::Key_AudioForward);
      signal_mapper->setMapping(rewind, Qt::Key_AudioRewind);
      signal_mapper->setMapping(next, Qt::Key_MediaNext);
      signal_mapper->setMapping(previous, Qt::Key_MediaPrevious);

      // TODO: use Qt 5.7's qOverload helper
      for(const auto& button : buttons)
      {
        connect(button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
      }

      connect(signal_mapper, SIGNAL(mapped(int)),
              &client, SLOT(keypress(int)));
    }

    void remote_control::resizeEvent(QResizeEvent *event)
    {

    }
  }
}
