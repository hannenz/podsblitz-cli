#ifndef FEED_PARSER_H
#define FEED_PARSER_H

#include <libxml++/libxml++.h>

class FeedParser : public xmlpp::SaxParser {
	public:
		FeedParser();
		~FeedParser();

	protected:
		void on_start_document() override;
		void on_end_document() override;
		void on_start_element(const Glib::ustring& name, const AttributeList& attributes) override; 
		void on_end_element(const Glib::ustring& name) override;
		void on_characters(const Glib::ustring& text) override;
		void on_comment(const Glib::ustring& text) override;
		void on_warning(const Glib::ustring& text) override;
		void on_error(const Glib::ustring& text) override;
		void on_fatal_error(const Glib::ustring& text) override;
};
#endif
