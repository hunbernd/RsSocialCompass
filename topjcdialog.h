#ifndef TOPJCDIALOG_H
#define TOPJCDIALOG_H

#include <retroshare-gui/mainpage.h>
#include <retroshare/rsfiles.h>
#include <retroshare/rspeers.h>

#include <retroshare/rsgrouter.h>

#include <QWidget>

namespace Ui {
class TopJCDialog;
}

class TopJCDialog  : public MainPage
{
    Q_OBJECT
    
public:
	explicit TopJCDialog(RsPeers *peers, RsGRouter *gRouter, QWidget *parent = 0);
    ~TopJCDialog();
    
    void lookupGxsId(RsGxsId gxsid);
private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::TopJCDialog *ui;
	RsPeers *mPeers;
	RsGRouter *mGRouter;
};

#endif // TOPJCDIALOG_H
