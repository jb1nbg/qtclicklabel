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

#include <QPainter>
#include <QPalette>
#include <QFontMetrics>
#include <QPainterPath>
#include <QLinearGradient>

QClickLabel::QClickLabel(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent, f)
{
    this->setText("QClickLabel");
}

QClickLabel::QClickLabel(const QString &text, QWidget* parent, Qt::WindowFlags f)
    : QLabel(text, parent, f)
{
}

void QClickLabel::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, true);

    QFontMetrics fm(this->font());
    QString text = this->text();
    int width = fm.width(text);
    int alpha = 255;
    int availableWidth = this->width();
    int textStartPosX = 0;
    if (this->pixmap() != Q_NULLPTR)
    {
        availableWidth -= this->pixmap()->width();
        textStartPosX += this->pixmap()->width();
    }
    if (width > availableWidth)
    {
        alpha = 32;
        while (width > availableWidth)
        {
            text = text.mid(0, text.length() - 1);
            width = fm.width(text + "...");
        }
        text += "...";
    }

    QPalette palette = this->palette();
    QBrush textBrush = palette.text();
    QPainterPath path;
    QColor textColor = textBrush.color();
    if ((this->alignment() & Qt::AlignCenter) == Qt::AlignCenter)
    {
        textStartPosX += ((availableWidth - width) / 2);
    }
    else if ((this->alignment() & Qt::AlignRight) == Qt::AlignRight)
    {
        textStartPosX += (availableWidth - width);
    }
    path.addText(textStartPosX, fm.height(), this->font(), text);
    QLinearGradient gradient(textStartPosX, 1, availableWidth, 1);
    gradient.setColorAt(0, textColor);
    gradient.setColorAt(0.85, textColor);
    gradient.setColorAt(1, QColor::fromRgb(textColor.red(), textColor.green(), textColor.blue(), alpha));
    painter.fillPath(path, gradient);
    if (this->pixmap() != Q_NULLPTR)
    {
        if (!this->pixmap()->isNull())
            painter.drawPixmap(0, 0, *this->pixmap());
    }
}

void QClickLabel::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    emit clicked();
}
