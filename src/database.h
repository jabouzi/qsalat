#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <stdlib.h>

class Database : public QObject
{  
  Q_OBJECT     
    public:
        Database(QObject* = 0); 
        void setDatabaseName(QString);
        void setDatabase();
        void prepareDB(); 
        void setTable(QString); 
        void where(QString); 
        void selectAll();
        QString select(QString);
        void insert(QString); 
        void update(QString, QString);
        QString getStringResult(QString);
        int getIntResult(QString);
        void sqlQuery(QString);
        bool tableExists(QString);
        void createTable(QString);
        void quit();
    
    private:    
        QSqlDatabase db;
        QString database;
        QString table;
        QString sqlWhere;
        QStringList result;  
        QSqlQuery dbQuery;      
};

#endif
