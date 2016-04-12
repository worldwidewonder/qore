/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#ifndef QORE_API_AUDIO_ALBUM_H
#define QORE_API_AUDIO_ALBUM_H

#include <QtCore/QString>
#include <QtGui/QImage>

namespace qore
{
  namespace api
  {
    class album
    {
      public:
        album();

        QString name;
        int id;
        QString artist;
        QImage thumbnail;
        QImage fanart;
    };

  }
}

#endif // QORE_API_AUDIO_ALBUM_H
