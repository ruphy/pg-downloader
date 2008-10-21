
#include <QtXml>
#include <QtGui>
#include <QtNetwork>

class Parser : public QObject
{
  Q_OBJECT
  public:
    void setUrl(QString url) { m_url = url; }
    void parse();

  public slots:
    void processData(QNetworkReply*);

  private:
    QString m_url;
    QString m_params;
//     QHttp *m_http;
};

void Parser::parse()
{
  int page = 0;
  m_params = "p-"+QString(page)+"?mr=100&rk=4";
  QString finalUrl = m_url+m_params;
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  connect(manager, SIGNAL(finished(QNetworkReply*)),
          this, SLOT(processData(QNetworkReply*)));

  manager->get(QNetworkRequest(QUrl(finalUrl)));
}

void Parser::processData(QNetworkReply *reply)
{

}

int main(int argc, char** argv)
{
  QApplication a(argc, argv);
  Parser p;
  p.setUrl("http://www.paginegialle.it/pgol/1-006644400/4-ottica%20lenti%20a%20contatto%20ed%20occhiali%20vendita%20al%20dettaglio/l-1/");

  a.exec();
}


#include "main.moc"
