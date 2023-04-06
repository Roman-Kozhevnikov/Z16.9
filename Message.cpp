// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Message.h"
#include <iostream>
#include <ctime>

Message::Message(const std::string& text, const std::string& sender, const std::string& recipient) :
	_text(text),
	_sender(sender),
	_recipient(recipient)
{
	time_t result = std::time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	_time = str;
}

const std::string Message::getText()const
{
	return _text;
}

const std::string& Message::getSender()const
{
	return _sender;
}

const std::string& Message::getRecipient()const 
{	
	return _recipient;
}

std::string Message::getTime()const
{	
	return _time;
}

std::ostream& operator<<(std::ostream& stream, Message& message)
{
	
	stream << message.getSender() << std::setw(35) << message.getTime() <<std::setw(30) << "--->" << std::setw(30)
		<< message.getRecipient() << std::endl << std::endl << std::setw(20) << "\" " << message.getText() << " \""
		<< std::endl << std::endl;
	return stream;
}
