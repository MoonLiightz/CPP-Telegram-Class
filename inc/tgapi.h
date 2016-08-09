#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <curl/curl.h>

using namespace std;

class tgapi
{

private:
	string bot_id;
	string send(string, string);

public:
	tgapi(string);
	string sendMessage(string, string);
	string getUpdates();
	string getUpdates(int);
	string getUpdates(int, int);
	string getUpdates(int, int, int);

};
