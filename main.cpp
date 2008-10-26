
#include <QtXml>
#include <QtGui>
#include <QtNetwork>


class Item
{
public:
    QString name, cap, locality, region, address, tel;
};

class Parser : public QXmlStreamReader
{
public:
    void parse(QIODevice*);
private:
    void readClient();

    QList<Item*> items;
};

void Parser::parse(QIODevice *d)
{
    setDevice(d);

    while (!atEnd()) {

        readNext();
        if (hasError()) {
            qDebug() << "ERROR!!!";
        }

        //     if (isStartElement() && name() == "div" && attributes().value("class") == "client-identifying-pg") {

        //       qDebug() << text().toString().toUtf8();
        //       while ((!isEndElement()) && name() == "div" && attributes().value("class") == "client-identifying-pg") {
        //  readNext();

        Item *i = new Item;

        forever {
            if (isStartElement() && name() == "h3" && attributes().value("class") == "org") { // Process informations for one company
                while (i->name.isEmpty()) {
                    readNext();
                    if (tokenType() == QXmlStreamReader::Characters) {
                        i->name = text().toString();
                    }
                }
                break;
            }
            if (atEnd()) {
                break;
            }
            readNext();
        }

        forever {
            if (isStartElement() && name() == "span" && attributes().value("class") == "postal-code") {
                while (i->cap.isEmpty()) {
                    readNext();
                    if (tokenType() == QXmlStreamReader::Characters) {
                        i->cap = text().toString();
                    }
                }
                break;
            }
            if (atEnd()) {
                break;
            }
            readNext();
        }

        forever {
            if (isStartElement() && name() == "span" && attributes().value("class") == "locality") {
                while (i->locality.isEmpty()) {
                    readNext();
                    if (tokenType() == QXmlStreamReader::Characters) {
                        i->locality = text().toString();
                    }
                }
                break;
            }
            if (atEnd()) {
                break;
            }
            readNext();
        }

        forever {
            if (isStartElement() && name() == "span" && attributes().value("class") == "region") {
                while (i->region.isEmpty()) {
                    readNext();
                    if (tokenType() == QXmlStreamReader::Characters) {
                        i->region = text().toString();
                        i->region.remove(')');
                        i->region.remove('(');
                    }
                }
                break;
            }
            if (atEnd()) {
                break;
            }
            readNext();
        }

        forever {
            if (isStartElement() && name() == "p" && attributes().value("class") == "street-address") {
                while (i->address.isEmpty()) {
                    readNext();
                    if (tokenType() == QXmlStreamReader::Characters) {
                        i->address = text().toString();
                    }
                }
                break;
            }
            if (atEnd()) {
                break;
            }
            readNext();
        }

        forever {
            if (isStartElement() && name() == "p" && attributes().value("class") == "tel") {
                while (i->tel.isEmpty()) {
                    readNext();
                    if (tokenType() == QXmlStreamReader::Characters) {
                        i->tel = text().toString();
                    }
                }
                break;
            }
            if (atEnd()) {
                break;
            }
            readNext();
        }

        items << i;
    }

    foreach(Item *item, items) {
        qDebug() << item->name << item->cap << item->locality << item->region << item->address << item->tel;
    }
}

void Parser::readClient()
{
//   forever {



//   }
}

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    Parser p;
    QFile *f = new QFile("test.html");
//   qDebug() << f->exists();
    f->open(QIODevice::ReadOnly);
    p.parse(f);
    f->close();


//   a.exec();
}


//#include "main.moc"
