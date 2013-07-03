#include "book.h"
#include "patron.h"

class Library
{
 public:
  Library();
  void add_book(Book b);
  void add_patron(Patron p);
  void check_out_book(const chrono::Date& d,const Patron& p,Book& b);
  std::vector<Patron> patron_with_fees() const;
  void return_book(Book& b,const Patron& p);
 private:
  bool patron_exists(const Patron& p) const;
  bool book_exists(const Book& b) const;
  std::vector<Book> books;
  std::vector<Patron> patrons;
  struct Transactions
  {
    chrono::Date date;
    Patron patron;
    Book book;
    Transactions(chrono::Date d, Patron p, Book b)
    :date(d),patron(p),book(b)
    {
    }
  };
  std::vector<Transactions> transactions;
};

