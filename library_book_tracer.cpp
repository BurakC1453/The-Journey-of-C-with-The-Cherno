#include <iostream>
#include <vector>
#include <string>

class library_book_tracer
{
private:
	std::vector <std::string> book_titles;
	std::vector <std::string> book_authors;
	std::vector <int> book_years;

	std::string book_title;
	std::string book_author;
	int book_year;
	std::string book_user_search_title;
	std::string book_user_search_author;
	int user_choice_of_operation ;

	void add_book()
	{
		std::cout << "Enter book title: ";
		std::getline(std::cin, book_title);
		std::cout << "Enter book author: ";
		std::getline(std::cin, book_author);
		std::cout << "Enter book publication year: ";
		std::cin >> book_year;
		std::cin.ignore(); // Clear the newline character from the input buffer
		book_titles.push_back(book_title);
		book_authors.push_back(book_author);
		book_years.push_back(book_year);
		std::cout << "Book added successfully!" << std::endl;
}

	void display_books()
	{
		std::cout << "Library Book List :" << std::endl;
		for (size_t i = 0; i < book_titles.size(); ++i)
		{
			std::cout << "Title: " << book_titles[i] << ", Author: " << book_authors[i] << ", Year: " << book_years[i] << std::endl;
		} 
	}

	void search_book_by_title()
	{
		std::cout << "Enter the title of the book to search: ";
		std::getline(std::cin, book_user_search_title);
		bool found = false;
		for (size_t i = 0; i < book_titles.size(); ++i)
		{
			if (book_titles[i] == book_user_search_title)
			{
				std::cout << "Book found: Title: " << book_titles[i] << ", Author: " << book_authors[i] << ", Year: " << book_years[i] << std::endl;
				found = true;
				break;
			}
		}
		if (!found)
		{
			std::cout << "Book not found in the library." << std::endl;
		}
	}

	void search_book_by_author()
	{
		std::cout << "Enter the author of the book to search: ";
		std::getline(std::cin, book_user_search_author);
		bool found = false;
		for (size_t i = 0; i < book_authors.size(); ++i)
		{
			if (book_authors[i] == book_user_search_author)
			{
				std::cout << "Book found: Title: " << book_titles[i] << ", Author: " << book_authors[i] << ", Year: " << book_years[i] << std::endl;
				found = true;
			}
		}
		if (!found)
		{
			std::cout << "No books found by that author in the library." << std::endl;
		}
	}

	void display_menu()
	{
		std::cout << "Library Book Tracer Menu:" << std::endl;
		std::cout << "1. Add a book" << std::endl;
		std::cout << "2. Display all books" << std::endl;
		std::cout << "3. Search for a book by title" << std::endl;
		std::cout << "4. Search for a book by author" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> user_choice_of_operation;
		std::cin.ignore(); // Clear the newline character from the input buffer
	}

	void user_operation()
	{
		switch (user_choice_of_operation)
		{
		case 1:
			add_book();
			break;
		case 2:
			display_books();
			break;
		case 3:
			search_book_by_title();
			break;
		case 4:
			search_book_by_author();
			break;
		case 5:
			std::cout << "Exiting. Thank you for using the Library Book Tracer!" << std::endl;
			exit(0);
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}

	void display_last_book_added()
	{
		if (!book_titles.empty())
		{
			std::cout << "Last book added: Title: " << book_titles.back() << ", Author: " << book_authors.back() << ", Year: " << book_years.back() << std::endl;
		}
		else
		{
			std::cout << "No books in the library." << std::endl;
		}
	}

	public:
		void run()
		{
			while (true)
			{
				display_menu();
				user_operation();
			}
		}
};

int main()
{
	library_book_tracer bookTracer;
	bookTracer.run();
	return 0;
}