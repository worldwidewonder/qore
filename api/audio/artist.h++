/**
 * Copyright (c) 2016 Ruben Van Boxem
 *
 * This code is dual licensed under the MIT and LGPLv3 licenses.
 * The full license texts can be found in MIT.txt and LGPLv3.txt.
 *
 * This file is part of Qore.
 *
 **/

#ifndef QORE_API_ARTIST_H
#define QORE_API_ARTIST_H

#include <QtCore/QString>
#include <QtGui/QImage>

namespace qore
{
  namespace api
  {
    struct artist
    {
      QString name;
      int ID;
      QString genre;
      QImage thumbnail;
      QImage fanart;
    };
  }
}

#endif // QOREI_API_ARTIST_H
