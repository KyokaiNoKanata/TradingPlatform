#pragma once

#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <vector>
#include <QDateTime>
#include "message.h"

class messageManager
{
public:
	messageManager();
	~messageManager();
	void addMessage(QString senderID, QString receiverID, QString content);
	std::vector<message>getMessage(QString ID);

private:
	QDateTime qdt;
	std::vector<message> data;

	void readFile();
	void writeFile();
};

