#include <stdio.h>
#include "inc/tgapi.h"

#define BOT_ID "Insert your Bot API Key here"
#define CHAT_ID "Insert your Chat ID here"

int main()
{
	
	class tgapi bot(BOT_ID);
	
	bot.sendMessage(CHAT_ID, "Example Message");
	
	cout << endl;
	
	return 0;
}