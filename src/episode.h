#ifndef EPISODE_H
#define EPISODE_H

#include <string>


using namespace std;

class Episode {

	private:
		string title;


	public:

		void play();
		void set_title(string _title);
};

#endif
