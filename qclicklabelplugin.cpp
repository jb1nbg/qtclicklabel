/*
Project: qclicklabel
Copyright (C) 2019-2020 Joerg Bressler <jb1nbg@gmx.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "qclicklabel.h"
#include "qclicklabelplugin.h"

#include <QtPlugin>

QClickLabelPlugin::QClickLabelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QClickLabelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QClickLabelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QClickLabelPlugin::createWidget(QWidget *parent)
{
    return new QClickLabel(parent);
}

QString QClickLabelPlugin::name() const
{
    return QLatin1String("QClickLabel");
}

QString QClickLabelPlugin::group() const
{
    return QLatin1String("Display Widgets");
}

QIcon QClickLabelPlugin::icon() const
{
    return QIcon();
}

QString QClickLabelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QClickLabelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QClickLabelPlugin::isContainer() const
{
    return false;
}

QString QClickLabelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QClickLabel\" name=\"qClickLabel\">\n</widget>\n");
}

QString QClickLabelPlugin::includeFile() const
{
    return QLatin1String("qclicklabel.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qclicklabelplugin, QClickLabelPlugin)
#endif // QT_VERSION < 0x050000
