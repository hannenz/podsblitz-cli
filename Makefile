podsblitz: src/main.cpp src/feed.cpp src/episode.cpp src/feed_parser.cpp
	g++ -Wall -o $@ $^ -lcurl `pkg-config --cflags --libs libxml++-2.6`

