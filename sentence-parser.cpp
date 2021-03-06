#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <vector>


class Token
{
public:
  char kind;
  std::string value;
  Token(char ch)
  :kind(ch),value(""){}
  Token(char ch,std::string val)
    :kind(ch),value(val){}
};

class Token_stream
{
public:
  Token_stream();
  Token get();
  void put_back(Token t);

private:
  bool full;
  Token buffer;

};

Token_stream::Token_stream()
  :full(false),buffer(0)
{
}
void Token_stream::put_back(Token t)
{
  if(full)
    {
      throw std::runtime_error("buffer full");
    }
  buffer = t;
  full = true;
}


Token Token_stream::get()    // read a token from cin
{
  if(full)
    {
      full = false;
      return buffer;
    }
    
  std::string s;
  std::cin >> s;
  
  if(s == "birds" || s == "fish" || s == "c++")
    {
      return Token('n',s);
    }
  else if(s == "rules" || s == "fly" || s == "swim")
    {
      return Token('v',s);
    }
  else if(s == "and" || s == "or" || s == "but")
    {
      return Token('c',s);
    }
  else if(s == "the")
    {
      return Token('a',s);
    }
  else if( s == ".")
    {
      return Token('.',s);
    }
  else
    {
      std::cout << s << '\n';
      throw std::runtime_error("unrecgonized symbol");
    }
}



Token_stream ts;

bool parse_sentence();

bool parse_conjunction()
{
  std::cout << "parse_conjunction \n";
  Token t = ts.get();
  switch(t.kind)
    {
    case 'c':
      return parse_sentence();
    case '.':
      return true;
    default:
      throw std::runtime_error("expected conjunction or full stop \n");
    }
}

bool parse_verb()p
{
  std::cout << "parse_verb \n";
  Token t = ts.get();
  if(t.kind != 'v')
    {
      return false;
    }
  return true;
}



bool parse_sentence()
{  
  std::cout << "parse_sentence \n";
  Token t = ts.get();
  
  switch(t.kind)
    {
    case 'n':
      if(!parse_verb())
	{
	  return false;
	}
      return parse_conjunction();
    case 'a':
      return parse_sentence();
    case '.' :
      return true;
    default:
      std::cout << t.kind << '\n';
      throw std::runtime_error("word not recognized \n");
    }

}

int main()
{
  try
    {
      if( parse_sentence())
	{
	  std::cout << "Sentence okay\n";
	}
      else
	{
	  std::cout << "Sentence incorrect \n";
	}
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "runtime error: " << e.what() << '\n';
      return -1;
    }
}
