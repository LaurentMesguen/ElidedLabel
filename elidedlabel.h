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
    ElidedLabel(QWidget* parent=0, Qt::WindowFlags f=0);
    ElidedLabel(const QString& txt, QWidget* parent=0, Qt::WindowFlags f=0);

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