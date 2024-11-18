#include "elidedlabel.h"

/*************************/
/* ElidedLabel functions */
/*************************/

ElidedLabel::ElidedLabel(QWidget* parent)
    : QLabel(parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setMinimumWidth(1);
}

ElidedLabel::ElidedLabel(const QString& txt, QWidget* parent)
    : QLabel(txt, parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setMinimumWidth(1);
}

void ElidedLabel::paintEvent( QPaintEvent* )
{
    QPainter painter(this);
    drawFrame(&painter);

    QRect cr = contentsRect();
    cr.adjust(margin(), margin(), -margin(), -margin());

    QString fullText = text();

    if (fullText != m_lastText || cr.width() != m_lastWidth)
    {
        m_elidedText = fontMetrics().elidedText(fullText, Qt::ElideRight, cr.width());
        m_isElided = m_elidedText != fullText;
        emit showHideButton(m_isElided && !m_elidedText.isEmpty());
        m_lastText = fullText;
        m_lastWidth = cr.width();
    }

    QStyleOption opt;
    opt.initFrom(this);

    style()->drawItemText(&painter, cr, alignment(), opt.palette, isEnabled(), m_elidedText, foregroundRole());
}

bool ElidedLabel::isElided() const
{
    return m_isElided;
}
