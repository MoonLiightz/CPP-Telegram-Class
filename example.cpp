#include <stdio.h>
#include "inc/tgapi.h"

#define BOT_ID "Insert your Bot API Key here"
#define CHAT_ID "Insert your Chat ID here"

int main()
{

	class tgapi bot(BOT_ID);

	bot.sendMessage(CHAT_ID, "Example Message");

	cout << bot.getUpdates() << endl;			// getUpdates without parameters
	cout << bot.getUpdates(20) << endl;			// getUpdates with offset
	cout << bot.getUpdates(20, 10) << endl;		// getUpdates with offset and limit
	cout << bot.getUpdates(20, 10, 10) << endl;	// getUpdates with offset, limit and timeout

	cout << endl;

	return 0;
}
