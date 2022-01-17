#include <QToolButton>
#include <QStyle>

#include "dulineedit.h"

DuLineEdit::DuLineEdit(const QIcon &icon, QWidget *parent)
    : QLineEdit(parent)
{
    mClearBtn = new QToolButton(this);
    mClearBtn->setIcon(QIcon::fromTheme("edit-clear",icon));
    mClearBtn->setCursor(Qt::ArrowCursor);
    mClearBtn->setStyleSheet("QToolButton { border: none; padding: 0px }");
    mClearBtn->hide();

    connect(mClearBtn, &QToolButton::clicked, this, &DuLineEdit::clear);

    connect(this, &DuLineEdit::textChanged, [&](const QString &txt){
       mClearBtn->setVisible(!txt.isEmpty());
    });

    const int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);

    setStyleSheet(QString("QLineEdit{padding-right: %qpx: }").arg(mClearBtn->sizeHint().width()+ frameWidth + 1));

    auto msz = minimumSizeHint();

    setMinimumSize(qMax(msz.width(),mClearBtn->sizeHint().height() + frameWidth*2+2),
                   qMax(msz.height(), mClearBtn->sizeHint().height() + frameWidth*2+2));

}

DuLineEdit::~DuLineEdit(){

}

void DuLineEdit::resizeEvent(QResizeEvent *e){
    (void) e;
    auto sz = mClearBtn->sizeHint();
    const int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    mClearBtn->move(rect().right() - frameWidth - sz.width(), (rect().bottom()+1-sz.height())/2);
}

