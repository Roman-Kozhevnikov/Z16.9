// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Chat.h"
#include "Message.h"
#include "User.h"
#include "BadLogin.h"
#include "BadPassword.h"
#include <iostream>
#include <ctime>


int main() {
	
	Chat ch;
	
	Chat* contain = ch.ChatStart();
		
	std::cout << "check contain some element\n";
	
	if (contain->isontheList(contain->getVusers(), "name", "Roman"))		
		
		std::cout << "Ura! isontheList found Roman! \n";
	else std::cout << "In _users Nothing not found! \n";
	
	if (contain->isontheList(contain->getVmessages(), "text", "Roman to Roman"))
		
		std::cout << "Ura! isontheList found \"Roman to Roman\"! \n";
	else std::cout << "In messages Nothing not found! \n";
	
	std::cout << std::endl;
	std::cout << "Done!";

	return 0;

}