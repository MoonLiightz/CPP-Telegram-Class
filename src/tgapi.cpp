#include "../inc/tgapi.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

tgapi::tgapi(string id)
{
	this->bot_id = id;
}

string tgapi::send(string action, string param)
{
		string readBuffer;
    stringstream url;
    url << "https://api.telegram.org/bot" << this->bot_id << "/" << action;

		CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl)
    {
        const int timeout = 30000;

        curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322; .NET CLR 2.0.5");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, param.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, param.length());
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout/1000);

        res = curl_easy_perform(curl);
        if(CURLE_OK != res)
        {
            printf("Error: %s\n", strerror(res));
            //return -1;
        }

        curl_easy_cleanup(curl);

				//return 1;
				return readBuffer;
    }

	//return 0;
	return "";
}

string tgapi::sendMessage(string chat_id, string text)
{
	stringstream param;
	param << "chat_id=" << chat_id << "&text=" << text;

	return this->send("sendMessage", param.str());
}

string tgapi::getUpdates()
{
	return this->send("getUpdates", "");
}

string tgapi::getUpdates(int offset)
{
	stringstream param;
	param << "offset=" << offset;
	return this->send("getUpdates", param.str());
}

string tgapi::getUpdates(int offset, int limit)
{
	stringstream param;
	param << "offset=" << offset << "&limit=" << limit;
	return this->send("getUpdates", param.str());
}

string tgapi::getUpdates(int offset, int limit, int timeout)
{
	stringstream param;
	param << "offset=" << offset << "&limit=" << limit << "&timeout=" << timeout;
	return this->send("getUpdates", param.str());
}
