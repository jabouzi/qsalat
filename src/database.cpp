#include "database.h"

bool Database::instanceFlag = false;
Database* Database::single = NULL;

Database::Database() 
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

Database* Database::getInstance()
{
    if(! instanceFlag)
    {
        single = new Database();
        instanceFlag = true;
        return single;       
    }
    else
    {
        return single;
    }
}

Database::~Database()
{
    db.close();
}

void Database::setDatabaseName(QString dbName)
{
    database = dbName;
}

void Database::setDatabase()
{
    db.setDatabaseName(database);
}

void Database::prepareDB()
{
    db.open();    
} 

void Database::setTable(QString tableName)
{
    table = tableName;
} 

void Database::where(QString whereString)
{
    sqlWhere = whereString;
}

void Database::selectAll()
{
    prepareDB();
    QSqlQuery query;
    query.exec("SELECT * FROM "+table+" "+sqlWhere);
}

QString Database::select(QString select)
{   
    prepareDB();
    QSqlQuery query;
    QString sql = "SELECT "+select+" FROM "+table+" "+sqlWhere;
    qDebug("%s",sql.toLatin1().data());
    query.exec(sql);
    int field = query.record().indexOf(select);
    query.next();
    return query.value(field).toString();
}

void Database::insert(QString sqlQuery)
{
    prepareDB();
    QSqlQuery query;
    query.exec(sqlQuery);
}

void Database::update(QString field, QString value)
{
    prepareDB();
    QSqlQuery query;    
    QString sql = "UPDATE "+table+" SET "+field+" = '"+value+"' "+sqlWhere;
    qDebug("%s",sql.toLatin1().data());
    query.exec(sql);
}

QString Database::getStringResult(QString filedName)
{
    int field = dbQuery.record().indexOf(filedName);
    dbQuery.next();
    return dbQuery.value(field).toString();
}

int Database::getIntResult(QString filedName)
{
    bool ok;
    int field = dbQuery.record().indexOf(filedName);
    dbQuery.next();
    return dbQuery.value(field).toInt(&ok);
}

bool Database::tableExists(QString tableName)
{
    QStringList tables = db.tables(QSql::Tables);
    return tables.indexOf(tableName) >= 0;
}

void Database::createTable(QString sqlQuery)
{
    prepareDB(); 
    QSqlQuery query;
    query.exec(sqlQuery);
}

void Database::sqlQuery(QString sqlQuery)
{ 
    prepareDB(); 
    QSqlQuery query;
    query.exec(sqlQuery);
}
