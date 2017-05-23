/****************************************************************************
**
** Copyright (C) 2016 Paul Lemire
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DRENDER_RENDER_FILTERLAYERENTITYJOB_H
#define QT3DRENDER_RENDER_FILTERLAYERENTITYJOB_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <Qt3DCore/qaspectjob.h>
#include <Qt3DCore/qnodeid.h>
#include <Qt3DRender/private/qt3drender_global_p.h>
#include <Qt3DRender/qlayerfilter.h>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {

namespace Render {

class Entity;
class NodeManagers;

class QT3DRENDERSHARED_PRIVATE_EXPORT FilterLayerEntityJob : public Qt3DCore::QAspectJob
{
public:
    FilterLayerEntityJob();

    inline void setManager(NodeManagers *manager) Q_DECL_NOEXCEPT { m_manager = manager; }
    inline void setLayers(const Qt3DCore::QNodeIdVector &layerIds) Q_DECL_NOEXCEPT { m_layerIds = layerIds; }
    inline void setHasLayerFilter(bool hasLayerFilter) Q_DECL_NOEXCEPT { m_hasLayerFilter = hasLayerFilter; }
    inline QVector<Entity *> filteredEntities() const Q_DECL_NOEXCEPT { return m_filteredEntities; }

    inline bool hasLayerFilter() const Q_DECL_NOTHROW { return m_hasLayerFilter; }
    inline Qt3DCore::QNodeIdVector layers() const { return m_layerIds; }

    // QAspectJob interface
    void run() Q_DECL_FINAL;

    void setFilterMode(QLayerFilter::FilterMode filterMode);
    bool filterMode() const {return m_filterMode;}

private:
    void filterLayerAndEntity();
    void selectAllEntities();

    NodeManagers *m_manager;
    Qt3DCore::QNodeIdVector m_layerIds;
    QVector<Entity *> m_filteredEntities;
    bool m_hasLayerFilter;
    QLayerFilter::FilterMode m_filterMode;
};

typedef QSharedPointer<FilterLayerEntityJob> FilterLayerEntityJobPtr;

} // Render

} // Qt3DRender

QT_END_NAMESPACE

#endif // QT3DRENDER_RENDER_FILTERLAYERENTITYJOB_H
