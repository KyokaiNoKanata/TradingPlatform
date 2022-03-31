#include "messageManager.h"

messageManager::messageManager()
{
	readFile();
}

messageManager::~messageManager()
{
	writeFile();
}

void messageManager::addMessage(QString senderID, QString receiverID, QString content)
{
	readFile();
	data.push_back(message(qdt.currentDateTime().toString("yyyy-MM-dd"), senderID, receiverID, content));
	writeFile();
}

std::vector<message> messageManager::getMessage(QString ID)
{
	readFile();
	std::vector<message> res;
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if ((*it).receiverID == ID)
		{
			res.push_back(*it);
		}
	}
	return res;
}

void messageManager::readFile()
{
	data.clear();
	QFile qf("data/message.txt");
	qf.open(QIODevice::ReadOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	QString qs;
	QStringList qsl;
	qs = qts.readLine();
	while (!qts.atEnd())
	{
		qs = qts.readLine();
		qsl = qs.split(",");
		message m(qsl);
		data.push_back(m);
	}
	qf.close();
}

void messageManager::writeFile()
{
	QFile qf("data/message.txt");
	qf.open(QIODevice::WriteOnly);
	QTextStream qts(&qf);
	qts.setAutoDetectUnicode(true);
	qts << "时间,发送者ID,接收者ID,内容";
	for (auto it = data.begin(); it != data.end(); it++)
	{
		qts << '\n'
			<< (*it).time << ',' << (*it).senderID << ',' << (*it).receiverID << ',' << (*it).content;
	}
	qf.close();
}
