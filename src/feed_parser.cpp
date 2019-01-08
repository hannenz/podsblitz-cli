#include "feed_parser.h"
#include <glibmm/convert.h>

#include <iostream>

FeedParser::FeedParser() : xmlpp::SaxParser() {
}

FeedParser::~FeedParser() {
}

void FeedParser::on_start_document() {
	std::cout << "on_start_document" << std::endl;
}

void FeedParser::on_end_document() {
	std::cout << "on_end_document" << std::endl;
}

void FeedParser::on_start_element(const Glib::ustring& name, const AttributeList& attributes) {
	std::cout << "node name: " << name << std::endl;
}

void FeedParser::on_end_element(const Glib::ustring& name) {
	std::cout << "on_end_element" << std::endl;
}

void FeedParser::on_characters(const Glib::ustring& text) {
	try {
		std::cout << "on_characters: " << text << std::endl;
	}
	catch (const Glib::ConvertError& ex) {
		std::cerr << "FeedParser::on_characters(): Exception caught while converting " << ex.what() << std::endl;
	}
}

void FeedParser::on_comment(const Glib::ustring& text) {
	try {
		std::cout << "on_comment: " << text << std::endl;
	}
	catch (const Glib::ConvertError& ex) {
		std::cerr << "FeedParser::on_comment(): Exception caught while converting " << ex.what() << std::endl;
	}
}

void FeedParser::on_warning(const Glib::ustring& text) {
	try {
		std::cout << "on_warning: " << text << std::endl;
	}
	catch (const Glib::ConvertError& ex) {
		std::cerr << "FeedParser::on_warning(): Exception caught while converting " << ex.what() << std::endl;
	}
}

void FeedParser::on_error(const Glib::ustring& text) {
	try {
		std::cout << "on_error: " << text << std::endl;
	}
	catch (const Glib::ConvertError& ex) {
		std::cerr << "FeedParser::on_error(): Exception caught while converting " << ex.what() << std::endl;
	}
}

void FeedParser::on_fatal_error(const Glib::ustring& text) {
	try {
		std::cout << "on_fatal_error: " << text << std::endl;
	}
	catch (const Glib::ConvertError& ex) {
		std::cerr << "FeedParser::on_fatal_error(): Exception caught while converting " << ex.what() << std::endl;
	}
}
