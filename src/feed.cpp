#include <iostream>
#include "feed.h"
#include "episode.h"
#include "feed_parser.h"
#include <curl/curl.h>
#include <libxml/parser.h>

using namespace std;

Feed::Feed(string url) {
	Feed::url = url;
	Feed::update();
}

Episode* Feed::get_latest_episode() {
	Episode *episode = new Episode();
	episode->set_title("Namen sind Schall und Rauch");
	return episode;
}

static int writer(char *data, size_t size, size_t nmemb, string *writerData) {

	if (writerData == NULL) {
		return 0;
	}

	writerData->append(data, size * nmemb);
	return size * nmemb;
}

void Feed::update() {
	CURL *conn;
	CURLcode code;
	string buffer;

	conn = curl_easy_init();
	if (conn == NULL) {
		fprintf(stderr, "Failed to create CURL connection\n");
	}

	curl_easy_setopt(conn, CURLOPT_URL, Feed::url.c_str());
	curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);
	// curl_easy_setopt(conn, CURLOPT_VERBOSE, 1L);

	code = curl_easy_perform(conn);
	if (code != CURLE_OK) {
		fprintf(stderr, "Failed to get %s: %u\n", Feed::url.c_str(), code);
	}

	curl_easy_cleanup(conn);

	cout << buffer;

	FeedParser *parser = new FeedParser();
	parser->parse_memory(buffer);


}
