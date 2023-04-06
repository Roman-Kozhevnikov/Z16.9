#pragma once

#include <string>
#include <iomanip>



class Message
{
private:
	std::string _text;
	std::string _sender;
	std::string _recipient;
	std::string _time;
	

public:
	Message(const std::string& text, const std::string& sender, const std::string& recipient);

	const std::string getText()const ;
	const std::string& getSender()const ;
	const std::string& getRecipient() const;
	std::string getTime()const;
	
	friend std::ostream& operator<< (std::ostream& stream, Message& message);
};

