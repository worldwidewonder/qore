/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#ifndef QORE_API_AUDIO_TRACK_H
#define QORE_API_AUDIO_TRACK_H

#include <QtCore/QString>

#include "export.h++"

namespace qore
{
  namespace api
  {
    struct QORE_API song
    {
      QString name;
      QString album;
      QString artist;
      int tracknumber;
      QString genre;
    };
  }
}

#endif // QORE_API_AUDIO_TRACK_H
