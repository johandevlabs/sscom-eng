#include "str_util.h"

#include <QDebug>

 /** 将String(abcdefg) to Hex(61 62 63 64 65 66 67) */
 QString str_util::stringToHex(QString str) {
     qDebug() << __func__ << ": " << str;

     QString ret;
     /* 将String(abcdefg) to Hex */
     for(int i = 0; i < str.length(); i++) {
         /* 将字符串中字符转换成QChar */
         QChar random = str.at(i).toLatin1();
         QString hex;
         QString str1;
         /* 将QChar转换成unicode */
         hex.setNum(random.unicode(), 16);
         /**
          * 由于unicode位数随机，所以需要根据情况进行格式化
          * 只保留末两位，如果不够两位补0
          */
         if(hex.length() >= 2) {
             qDebug() << "hex.length() >= 2 hex:" << hex;
             str1 = hex.mid(hex.length() - 2, hex.length());
         } else if(hex.length() == 1) {
             qDebug() << "hex.length() == 1 hex:" << hex;
             str1 = hex.prepend("0");
         } else {
             qDebug() << "else";
             str1 = "";
         }
         ret.append(str1.toUpper() + " ");
     }
     return ret;
 }


 /** 将hex(61 62 63 64 65 66 67) to String(abcdefg) */
 QString str_util::hexToString(QString hexStr) {
     qDebug() << __func__ << ": " << hexStr;

     QString ret;
     QStringList list = hexStr.split(" ", QString::SkipEmptyParts);
     for(QString qs : list) {
         bool bStatus = false;
         int a = qs.toInt(&bStatus, 16);
         if(bStatus && (qs.length() == 2)) {
             QString sA = QString(QChar(a));
             qDebug() << "a:" << a << "sA:" << sA << "qs:" + qs;
             ret.append(sA);
         } else {/* 转换失败，使用默认字体串 */
             qDebug() << "error!!!";
             break;
         }
     }
     return ret;
 }
