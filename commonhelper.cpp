#include "commonhelper.h"

#include <QDateTime>
#include <QHostAddress>
#include <QNetworkInterface>

QHostAddress CommonHelper::getLocalHostIP()
{
  QList<QHostAddress> AddressList = QNetworkInterface::allAddresses();
  QHostAddress result;
  foreach(QHostAddress address, AddressList){
      if(address.protocol() == QAbstractSocket::IPv4Protocol &&
         address != QHostAddress::Null &&
         address != QHostAddress::LocalHost){
          if (address.toString().contains("127.0.")){
            continue;
          }
          result = address;
          break;
      }
  }
  return result;
}

/**
 * @brief getDateFromMacro
 * @param time __DATE__
 * @return
 */
time_t CommonHelper::getDateFromMacro(char const *time)
{
    char s_month[5];
    int month, day, year;
    struct tm t;
    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

    sscanf(time, "%s %d %d", s_month, &day, &year);

    month = (strstr(month_names, s_month)-month_names)/3;

    memset(&t, '\0', sizeof(t));
    t.tm_mon = month;
    t.tm_mday = day;
    t.tm_year = year - 1900;
    t.tm_isdst = -1;

    return mktime(&t);
}

QString CommonHelper::getCurrTimeStr()
{
    return QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz");
}
