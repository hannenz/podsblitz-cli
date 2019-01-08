#ifndef FEED_H
#define FEED_H

#include <string>
#include "episode.h"

using namespace std;

class Feed {
	private:
		string url;
		string category;
		string description;
		string language;


	public:

		Feed(string url);
		Episode* get_latest_episode();
		void update();
		string get_url();
		string get_category();
		string get_description();
		string get_langauge();
};

#endif
