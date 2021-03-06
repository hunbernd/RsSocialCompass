#include "topjcdialog.h"
#include "ui_topjcdialog.h"



/** Constructor
LinksDialog::LinksDialog(RsPeers *peers, RsFiles *files, QWidget *parent)
: MainPage(parent), mPeers(peers), mFiles(files)
{

}**/

TopJCDialog::TopJCDialog(QWidget *parent) :
    MainPage(parent),
    ui(new Ui::TopJCDialog)
{
    ui->setupUi(this);
}

TopJCDialog::~TopJCDialog()
{
    delete ui;
}


void TopJCDialog::lookupGxsId(RsGxsId gxsid){

    std::vector<RsGRouter::GRouterRoutingCacheInfo> cache_infos ;
    RsGRouter::GRouterRoutingMatrixInfo matrix_info ;

    rsGRouter->getRoutingCacheInfo(cache_infos) ;
    rsGRouter->getRoutingMatrixInfo(matrix_info) ;
    ui->textBrowser->append("\n");
    ui->textBrowser->append(QString("Looking up ID %1").arg(QString::fromStdString(gxsid.toStdString())));

    RsPeerDetails peer_ssl_details;
    //print matrix
    std::map<GRouterKeyId,std::vector<float> >::const_iterator it;
    it = matrix_info.per_friend_probabilities.find(gxsid);

    if (it != matrix_info.per_friend_probabilities.end()){

        bool is_null = true ;

        for(uint32_t i=0;i<matrix_info.friend_ids.size();++i)
            if(it->second[i] > 0.0)
                is_null = false ;

        if(!is_null)
        {
            QString ids = QString::fromStdString(it->first.toStdString())+" : " ;

            for(uint32_t i=0;i<matrix_info.friend_ids.size();++i){
                rsPeers->getPeerDetails(matrix_info.friend_ids[i], peer_ssl_details);
                float friend_chance = it->second[i];
                if (friend_chance>0.0){
                    QString friend_name = QString::fromUtf8(peer_ssl_details.name.c_str());

                    QString formatted_string = QString("%1 has a chance of %2").arg(friend_name, QString::number(friend_chance));
                    ui->textBrowser->append(formatted_string);
                    //ui->textBrowser->append("\n");
                }
            }
            if (matrix_info.friend_ids.size() == 0)
                ui->textBrowser->append("no friends found in routing matrix?");

        }else{
            ui->textBrowser->append("no route found");
        }
    } else {
        ui->textBrowser->append("ID not found in matrix... booted RS recently? wait a while? Check id is correct!!");
    }
}
void temp(){

    std::vector<RsGRouter::GRouterRoutingCacheInfo> cache_infos ;
    RsGRouter::GRouterRoutingMatrixInfo matrix_info ;

    rsGRouter->getRoutingCacheInfo(cache_infos) ;
    rsGRouter->getRoutingMatrixInfo(matrix_info) ;

    rsGRouter->getRoutingMatrixInfo(matrix_info) ;

	//print friends in the same order their prob is shown
	QString FO = "Friend Order  (";
	RsPeerDetails peer_ssl_details;
	for(uint32_t i=0;i<matrix_info.friend_ids.size();++i){
		rsPeers->getPeerDetails(matrix_info.friend_ids[i], peer_ssl_details);
		QString fn = QString::fromUtf8(peer_ssl_details.name.c_str());
		FO+=fn;
		FO+=" ";

	}
	FO+=")";


    //print matrix

    for(std::map<GRouterKeyId,std::vector<float> >::const_iterator it(matrix_info.per_friend_probabilities.begin());it!=matrix_info.per_friend_probabilities.end();++it)
    {
        bool is_null = true ;

        for(uint32_t i=0;i<matrix_info.friend_ids.size();++i)
            if(it->second[i] > 0.0)
                is_null = false ;

        if(!is_null)
        {
            QString ids = QString::fromStdString(it->first.toStdString())+" : " ;
            //painter.drawText(ox+2*cellx,oy+celly,ids) ;

            //for(uint32_t i=0;i<matrix_info.friend_ids.size();++i)
            //    painter.fillRect(ox+i*cellx+fm_monospace.width(ids),oy,cellx,celly,colorScale(it->second[i])) ;

            //oy += celly ;
        }
    }
}

void TopJCDialog::on_lineEdit_returnPressed()
{
    RsGxsId gxsid = RsGxsId(ui->lineEdit->text().toStdString());
    ui->idLabel->setId(gxsid);
    lookupGxsId(gxsid);

}
