#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::downloadfinished(QNetworkReply *rep){

    QPixmap pixSunny(":/resources/img/sunny.png");
    QPixmap pixRainy(":/resources/img/rainy.png");
    QPixmap pixCloudy(":/resources/img/cloudy.png");
    QPixmap pixFewClouds(":/resources/img/fewclouds.png");
    QPixmap pixBackground(":/resources/img/background.jpg");

    QByteArray bts = rep->readAll();
    QString str(bts);

    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());

    QJsonObject jsonObject = jsonResponse.object();
    QJsonObject temp = jsonObject["main"].toObject();
    double deg =  temp["temp"].toDouble() - 273;
    QString degStr = QString::number(deg);

    QString city = jsonObject["name"].toString();

    QJsonValue weather = jsonObject.value("weather");
    QJsonArray weatherArray = weather.toArray();

    foreach (const QJsonValue & v, weatherArray) {
        QString hava = v.toObject().value("icon").toString();

        if(hava == "01d" || hava == "01n"){
            ui->label_pic->setPixmap(pixSunny.scaled(190,255,Qt::KeepAspectRatio));
        }

        else if(hava == "02d" || hava == "02n"){
            ui->label_pic->setPixmap(pixFewClouds.scaled(190,255,Qt::KeepAspectRatio));
        }

        else if(hava == "03d" || hava == "03n" || hava == "04d" ||hava == "04n"){
            ui->label_pic->setPixmap(pixCloudy.scaled(190,255,Qt::KeepAspectRatio));
        }

        else if(hava == "09d" || hava == "09n" ||hava == "10d" ||hava == "10n"){
            ui->label_pic->setPixmap(pixRainy.scaled(190,255,Qt::KeepAspectRatio));
        }
    }

    ui->labelCity->setText(city + "\n" + degStr);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

using namespace std;


void MainWindow::on_searchButton_clicked()
{
    QString cityName = ui->lineEdit->text();
    list<QString> sehirler;


    QString settings;
    QFile file;
    file.setFileName(":/resources/img/iller.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    settings = file.readAll();
    file.close();

    QJsonDocument sd = QJsonDocument::fromJson(settings.toUtf8());

    QJsonObject cityObj = sd.object();

    if(isAdded == false){

         for (int i=1; i<=81; i++) {

            QString city = QString::number(i);
            sehirler.push_back(cityObj.value(QString(city)).toString());
            ui->comboBox->addItem(cityObj.value(QString(city)).toString());
            isAdded = true;
        }
    }

    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    mgr->get(QNetworkRequest(QUrl("https://api.openweathermap.org/data/2.5/weather?q="+ cityName + "&appid=983c30e9c1adf4b366c9ee9694735b6d")));

    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(downloadfinished(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
}

