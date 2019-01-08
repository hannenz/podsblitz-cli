#include <iostream>
#include "feed.h"
#include "episode.h"

int main(int argc, char **argv) {

	Feed *feed = new Feed("https://www.deutschlandfunk.de/podcast-deutschlandfunk-der-tag.3417.de.podcast.xml");
	feed->get_latest_episode()->play();
	return 0;
}
