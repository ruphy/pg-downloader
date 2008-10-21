
#include <QtXml>
#include <QtGui>
#include <QtNetwork>


class Item
{
  public:
    QString name, cap, locality, region, address, tel;
}

class Parser : public QXmlStreamReader
{
  Q_OBJECT
  public:
    void parse(QIODevice*);

  private:
};

void Parser::parse(QIODevice *d)
{
  setDevice(d);
  while (!atEnd()) {
    readNext();

  }
}

int main(int argc, char** argv)
{
  QApplication a(argc, argv);
  Parser p;
  p.parse(QFile("big-bad-file.html");

  a.exec();
}


#include "main.moc"
