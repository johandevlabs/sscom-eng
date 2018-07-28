#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QObject>
#include <QHostAddress>

class CommonHelper
{
public:
    static QHostAddress getLocalHostIP();
    static time_t getDateFromMacro(char const *time);
};

#endif // COMMONHELPER_H
