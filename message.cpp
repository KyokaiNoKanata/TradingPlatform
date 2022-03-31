#include "message.h"

message::message()
{
	time = QString();
	senderID = QString();
	receiverID = QString();
	content = QString();
}

message::message(QString time, QString senderID, QString receiverID, QString content)
{
	this->time = time;
	this->senderID = senderID;
	this->receiverID = receiverID;
	this->content = content;
}

message::message(QStringList qsl)
{
	this->time = qsl[0];
	this->senderID = qsl[1];
	this->receiverID = qsl[2];
	this->content = qsl[3];
}
