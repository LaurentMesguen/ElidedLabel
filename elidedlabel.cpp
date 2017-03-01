#include "elidedlabel.h"

/*************************/
/* ElidedLabel functions */
/*************************/

// Implementation inspired from http://www.mimec.org/node/307

ElidedLabel::ElidedLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent, f)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setMinimumWidth(1);
}

ElidedLabel::ElidedLabel(const QString& txt, QWidget* parent, Qt::WindowFlags f)
    : QLabel(txt, parent, f)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setMinimumWidth(1);
}

void ElidedLabel::paintEvent( QPaintEvent* /*e*/ )
{
    QPainter painter(this);
    drawFrame(&painter);

    QRect cr = contentsRect();
    cr.adjust(margin(), margin(), -margin(), -margin());

    QString fullText = text();

    if (fullText != m_lastText || cr.width() != m_lastWidth)
    {
        m_elidedText = fontMetrics().elidedText(fullText, Qt::ElideRight, cr.width());
        if(m_elidedText != fullText)
        {
            m_isElided = true;
        }
        else
        {
            m_isElided = false;
        }
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