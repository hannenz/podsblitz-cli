#include <iostream>
#include <string>
#include "feed.h"
#include "episode.h"

using namespace std;

void Episode::play() {
	cout << "Playing episode: " << title << endl;
}

void Episode::set_title(string _title) {
	Episode::title = _title;
}

