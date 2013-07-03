#include <iostream>
#include <string>
#include "chrono.h"
#include <stdexcept>
#include <cctype>
#include <vector>
class Book
{
 public:
  enum Genre
  {
    fiction, nonfiction, periodica1, biography, children
  };
  Book(std::string title,std::string author,std::string isbn,chrono::Date d,Genre g);
  void check_out();
  void check_in();
  std::string get_title() const;
  std::string get_author() const;
  std::string get_isbn() const;
  Genre get_genre() const;
  bool is_available() const;
 private:
  bool is_valid_isbn(const std::string& isbn) const;
  bool is_valid_author(const std::string& author) const;
  std::string title;
  std::string author;
  std::string ISBN;
  chrono::Date copy_right;
  Genre genre;
  bool available;
  
};

bool operator==(const Book& left,const Book& right);
bool operator!=(const Book& left,const Book& right);
std::ostream& operator<<(std::ostream& s,const Book& right);
std::ostream& operator<<(std::ostream& s,const Book::Genre right);
