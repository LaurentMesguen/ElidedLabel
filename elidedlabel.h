#ifndef ELIDEDLABEL_H
#define ELIDEDLABEL_H

#include <QLabel>
#include <QResizeEvent>
#include <QDebug>
#include <QPainter>
#include <QStyleOption>

class ElidedLabel : public QLabel
{
    Q_OBJECT
public:
    ElidedLabel(QWidget* parent=nullptr);
    ElidedLabel(const QString& txt, QWidget* parent=nullptr);

    bool isElided() const;

protected: // QLabel overrides
    void paintEvent(QPaintEvent*);

signals:
    void showHideButton(const bool);

private:
    QString m_lastText;
    QString m_elidedText;
    int m_lastWidth;
    bool m_isElided;
};

#endif
