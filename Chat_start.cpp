// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Chat.h"
#include "Message.h"
#include "User.h"
#include "BadLogin.h"
#include "BadPassword.h"
#include <iostream>
#include <ctime>

Chat* Chat::ChatStart() {
	//std::shared_ptr<Chat> chat = std::make_shared<Chat>(*this);	

	std::cout << "Hello! Let's start!" << std::endl;

	char choose;
	while (true)
	{
		while (getActiveUser() == nullptr) {
			std::cout << "Would you like login(enter 'L'), register(enter 'R') or quit(enter 'Q')?" << std::endl;
			std::string selection;
			std::cin >> selection;
			if (selection.size() > 1) {
				std::cout << "I think you mean '" << selection.at(0) << "'" << std::endl;
			}
			switch (selection.at(0))
			{
			case 'R':
			{
				std::string name, login, password;
				std::cout << "Enter login" << std::endl;
				std::cin >> login;
				if (isLoginExist(login)) {
					std::cout << "User with login " << login << " is already exists." << std::endl;
					break;
				}					
				std::cout << "Enter password" << std::endl;
				std::cin >> password;
				std::cout << "Enter name" << std::endl;
				std::cin >> name;
				createNewUser(name, login, password);
				break;
			}
			case 'L':
			{
				std::string login, password;
				std::cout << "Enter login" << std::endl;
				std::cin >> login;
				std::cout << "Enter password" << std::endl;
				std::cin >> password;
				int tries = 3;

				try {
					Chat::login(login, password);
					std::cout << std::endl;
					showAllUserMesseges(getActiveUser());
					std::cout << std::endl;
				}
				catch (BadLogin& e) {
					std::cout << e.what() << std::endl;
					break;
				}
				catch (BadPassword& e) {
					std::cout << e.what() << std::endl;
					while (--tries > 0) {
						try {
							std::cout << "Enter password (" << tries << " tries left)" << std::endl;
							std::cin >> password;
							Chat::login(login, password);
							std::cout << std::endl;
							showAllUserMesseges(getActiveUser());
							std::cout << std::endl;
						}
						catch (BadPassword& e) {
							std::cout << e.what() << std::endl;
						}
					}
					break;
				}
				break;
			}
			case 'Q':
				std::cout << "Good luck, bye!" << std::endl;
				return this;
			default:
				std::cout << "Enter L, R or Q" << std::endl;
				break;
			}
		}

		showMenuAddMessege(); // 1 - One, 2 - All, 3 - Exit	    
	    std::cin >> choose;
		while (std::cin.get() != '\n')
			continue;
	    std::string message;
		std::string name_recipient;
		std::string log_recipient;
		switch (choose)
		{
		case '1':		
		    {
		      std::cout << "You are : " << getActiveUser()->getName() << std::endl;
			  std::cout << "Choose the recipient: \n";
			  std::cout << *this << std::endl;
			  std::getline (std::cin,name_recipient);
			  
			  if (!(isontheList(name_recipient)))	     	  
				    continue;			    

			  if (!isUnicName(name_recipient)) // 
			    {			    
			      std::cout << "The name is not unique, chose name by login list : \n";
			    	showAllLogin();
			    	std::cout << std::endl;
	     		  	std::string login_from_list;
	    			std::getline(std::cin, login_from_list);	     			
					if (!(isontheList(getNameByLogin(login_from_list))))
						continue;
					log_recipient = login_from_list;	
				
				
	    		} else
			      log_recipient = getLoginByName(name_recipient);
			      std::cout << std::endl;
			      std::cout << "The logrecipient is :" << log_recipient << std::endl;
			      std::cout << std::endl;
			      std::cout << "write a message\n";
			      std::getline(std::cin,message);
			      std::cout << std::endl;
			      write(message, getUser(log_recipient));
			      time_t result = time(NULL);
			      char str[26];
			      ctime_s(str, sizeof str, &result);
			     std::cout << getActiveUser()->getName() << std::setw(35) << str <<std::setw(30) 
			    	<< "--->"<< std::setw(30)
			    	<< getNameByLogin(log_recipient) << std::endl << std::endl << std::setw(15) << "\" " << message << " \""
			    	<< std::endl << std::endl;
		    }
			continue;

		case '2':
		    {
		     	std::cout << "You are : " << getActiveUser()->getName() << std::endl;
		    	std::cout << "write a message : \n";
		    	std::getline(std::cin,message);			
	    		writeToAll(message);
	    		std::cout << std::endl;
	    		time_t result = time(NULL);
	    		char str[26];
	    		ctime_s(str, sizeof str, &result);
	    		std::cout << getActiveUser()->getName() << std::setw(35) << str << std::setw(30)
				<< "--->" << std::setw(30)
				<< "All" << std::endl << std::endl << std::setw(15) << "\" " << message << " \""
				<< std::endl << std::endl;
		    }
			continue;
		
		case '3':
		    {			
			std::cout << "Exit write massege... \n";
			setActiveUser(nullptr);
			break;
		    }

		default: std::cout << "bad choose mode, try again! \n";
			continue;
		}

	}

	//std::shared_ptr<Chat> chat2 = std::shared_ptr<Chat>(new Chat());
	std::cout << std::endl;
	std::cout << "Done Chat_Start!";
	return nullptr;
}