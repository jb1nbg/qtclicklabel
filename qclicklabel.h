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

#ifndef QCLICKLABEL_H
#define QCLICKLABEL_H

#include <QLabel>

class QClickLabel : public QLabel
{
    Q_OBJECT

public:
    explicit QClickLabel(QWidget *parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags());
    explicit QClickLabel(const QString &text, QWidget *parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags());

signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent *ev) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;
};

#endif
