#pragma once

#include <QString>
#include <QStringList>

class message
{
public:
	message();
	message(QString time, QString senderID, QString receiverID, QString content);
	message(QStringList qsl);
	QString time;
	QString senderID;
	QString receiverID;
	QString content;
};
