#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class book {
private:
	std::string text;
	std::string author;
	std::string title;

	void print_text();
	void print_author();
	void print_title();

public:
	book(std::string text, std::string author, std::string title):
		text(text),
		author(author),
		title(title)
	{}

	void print();
};

#endif // BOOK_HPP
