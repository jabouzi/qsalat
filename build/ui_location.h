/********************************************************************************
** Form generated from reading UI file 'location.ui'
**
** Created: Tue Jan 5 22:39:36 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATION_H
#define UI_LOCATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Location
{
public:
    QLabel *label;
    QLineEdit *locationLineEdit;
    QPushButton *searchButton;
    QWebView *webView;
    QLabel *latLabel;
    QLabel *lngLabel;
    QPushButton *cancelButton;
    QPushButton *applyButton;
    QPushButton *okButton;
    QLabel *label_2;
    QLabel *countryLabel;
    QLabel *cityLabel;
    QLabel *timeZoneLabel;
    QLineEdit *latLineEdit;
    QLineEdit *lngLineEdit;
    QLineEdit *countryLineEdit;
    QLineEdit *cityLineEdit;
    QLineEdit *timezoneLineEdit;

    void setupUi(QDialog *Location)
    {
        if (Location->objectName().isEmpty())
            Location->setObjectName(QString::fromUtf8("Location"));
        Location->resize(301, 540);
        Location->setMinimumSize(QSize(301, 450));
        Location->setMaximumSize(QSize(301, 600));
        label = new QLabel(Location);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 54, 31));
        locationLineEdit = new QLineEdit(Location);
        locationLineEdit->setObjectName(QString::fromUtf8("locationLineEdit"));
        locationLineEdit->setGeometry(QRect(60, 40, 161, 28));
        searchButton = new QPushButton(Location);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(230, 40, 61, 28));
        webView = new QWebView(Location);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(10, 79, 281, 281));
        webView->setUrl(QUrl("http://www.skanderjabouzi.com/qpray/"));
        latLabel = new QLabel(Location);
        latLabel->setObjectName(QString::fromUtf8("latLabel"));
        latLabel->setGeometry(QRect(10, 380, 61, 20));
        lngLabel = new QLabel(Location);
        lngLabel->setObjectName(QString::fromUtf8("lngLabel"));
        lngLabel->setGeometry(QRect(140, 380, 61, 20));
        cancelButton = new QPushButton(Location);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(219, 500, 71, 28));
        applyButton = new QPushButton(Location);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setEnabled(true);
        applyButton->setGeometry(QRect(90, 500, 121, 28));
        okButton = new QPushButton(Location);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(20, 500, 61, 28));
        label_2 = new QLabel(Location);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 281, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        countryLabel = new QLabel(Location);
        countryLabel->setObjectName(QString::fromUtf8("countryLabel"));
        countryLabel->setGeometry(QRect(10, 410, 51, 20));
        cityLabel = new QLabel(Location);
        cityLabel->setObjectName(QString::fromUtf8("cityLabel"));
        cityLabel->setGeometry(QRect(10, 440, 51, 20));
        timeZoneLabel = new QLabel(Location);
        timeZoneLabel->setObjectName(QString::fromUtf8("timeZoneLabel"));
        timeZoneLabel->setGeometry(QRect(10, 470, 61, 20));
        latLineEdit = new QLineEdit(Location);
        latLineEdit->setObjectName(QString::fromUtf8("latLineEdit"));
        latLineEdit->setGeometry(QRect(70, 380, 61, 21));
        lngLineEdit = new QLineEdit(Location);
        lngLineEdit->setObjectName(QString::fromUtf8("lngLineEdit"));
        lngLineEdit->setGeometry(QRect(210, 380, 61, 21));
        countryLineEdit = new QLineEdit(Location);
        countryLineEdit->setObjectName(QString::fromUtf8("countryLineEdit"));
        countryLineEdit->setGeometry(QRect(70, 410, 201, 21));
        cityLineEdit = new QLineEdit(Location);
        cityLineEdit->setObjectName(QString::fromUtf8("cityLineEdit"));
        cityLineEdit->setGeometry(QRect(70, 440, 201, 21));
        timezoneLineEdit = new QLineEdit(Location);
        timezoneLineEdit->setObjectName(QString::fromUtf8("timezoneLineEdit"));
        timezoneLineEdit->setGeometry(QRect(70, 470, 51, 21));

        retranslateUi(Location);

        QMetaObject::connectSlotsByName(Location);
    } // setupUi

    void retranslateUi(QDialog *Location)
    {
        Location->setWindowTitle(QApplication::translate("Location", "Qsalat - location", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Location", "Location", 0, QApplication::UnicodeUTF8));
        searchButton->setText(QApplication::translate("Location", "Search", 0, QApplication::UnicodeUTF8));
        latLabel->setText(QApplication::translate("Location", "Latitude", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lngLabel->setStatusTip(QApplication::translate("Location", "Longitude", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lngLabel->setText(QApplication::translate("Location", "Longitude", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Location", "Cancel", 0, QApplication::UnicodeUTF8));
        applyButton->setText(QApplication::translate("Location", "Show coordinates", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("Location", "Save", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Location", "Set your location", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        countryLabel->setStatusTip(QApplication::translate("Location", "Longitude", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        countryLabel->setText(QApplication::translate("Location", "Country", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        cityLabel->setStatusTip(QApplication::translate("Location", "Longitude", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        cityLabel->setText(QApplication::translate("Location", "City", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        timeZoneLabel->setStatusTip(QApplication::translate("Location", "Longitude", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        timeZoneLabel->setText(QApplication::translate("Location", "Timezone", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Location: public Ui_Location {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATION_H
