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
	int send(string, string);

public:
	tgapi(string);
	int sendMessage(string, string);

};
