/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DQUICKGLOBAL_H
#define QT3DQUICKGLOBAL_H

#include <QtCore/qglobal.h>

QT_LICENSED_MODULE(QtQuick3D)
#if defined(Q_OS_WIN)
#  if defined(QT_NODLL)
#    undef QT_MAKEDLL
#    undef QT_DLL
#  elif defined(QT_MAKEDLL)        /* create a Qt DLL library */
#    if defined(QT_DLL)
#      undef QT_DLL
#    endif
#    if defined(QT_BUILD_QT3D_QUICK_LIB)
#        define Q_QT3D_QUICK_EXPORT Q_DECL_EXPORT
#    else
#        define Q_QT3D_QUICK_EXPORT Q_DECL_IMPORT
#    endif
#  elif defined(QT_DLL) /* use a Qt DLL library */
#    define Q_QT3D_QUICK_EXPORT Q_DECL_IMPORT
#  endif
#endif
#if !defined(Q_QT3D_QUICK_EXPORT)
#   if defined(QT_SHARED)
#       define Q_QT3D_QUICK_EXPORT Q_DECL_EXPORT
#   else
#       define Q_QT3D_QUICK_EXPORT
#   endif
#endif

#endif
