#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <limits>
#include <vector>
#include <stdexcept>
#include <cctype>
class Token
{
public:
  char kind;
  double value;
  std::string name;
  Token(char ch)
    :kind(ch),value(0),name(""){}
  Token(char ch,double val)
    :kind(ch),value(val),name(""){}
  Token(char ch,std::string n)
    :kind(ch),value(0),name(n){}
};

class Token_stream
{
public:
  Token_stream(istream& s); // make a Token_stream that reads from cin
  Token get(); // get a Token
  void put_back(Token t); // store a token for later
  void ignore(char c); // discard characters up to and include c
  
private:
  bool full; // is there a Token already stored?
  Token buffer; // Storage for token used by put_back()
};

class Variable
{
public:
  std::string name;
  double value;
  Variable(std::string n, double v)
    :name(n),value(v){}

};

Token_stream::Token_stream()
  :full(false),buffer(0)
{
}

void Token_stream::ignore(char c)
{
  std::cout << "buffer: " << buffer.kind << '\n';
  if(full && c == buffer.kind)
    {
      full = false;
      return;
    }
  full = false;

  char ch = 0;
  while(std::cin >> ch)
    {
      std::cout << "ch: " << ch << '\n';
      if(ch == c)
        {
          return;
        }
    }
}
void Token_stream::put_back(Token t)
{
  if(full)
    {
      throw std::runtime_error("Buffer is full");
    }
  buffer = t;
  full = true;
}

void error(std::string s1,std::string s2)
{
  std::string temp = s1 + s2;
  throw std::runtime_error(temp);
}

const char number = '8'; // t.kind == number means that t is a number Token
const char quit = 'q'; // quit token
const char print = ';'; // print token
const char prompt = '>'; 
const char result = '='; // used to indicate that what follows is the result
const char name = 'a';
const char let = 'L';
const std::string declkey = "let";


std::vector<Variable> var_table; //storing variables that have been declared

double get_value(std::string s)
{
  for(unsigned int i = 0; i < var_table.size();++i)
    {
      if(var_table[i].name == s)
        {
          return var_table[i].value;
        }
    }

  error("get: undefined variable ",s);
  return 0.0; // to stop compiler warning
}


void set_value (std::string s, double d)
{
  for(unsigned int i = 0; i < var_table.size(); ++i)
    {
      if(var_table[i].name == s)
        {
          var_table[i].value = d;
          return;
        }
    }
  error("set: undefined variable ",s);
}
void keep_window_open()
{
  std::cin.clear();
  std::cout << "Please enter a character to exit\n";
  char ch;
  std::cin >> ch;
  return;
}

void keep_window_open(std::string s)
{
  if (s=="") return;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
  while(true)
    {
      std::cout << "Please enter " << s << " to exit\n";
      std::string ss;
      while (std::cin >> ss && ss!=s)
        {
          std::cout << "Please enter " << s << " to exit\n";
        }
      return;
    }
}

int factorial(unsigned int f)
{
  std::cout << "f: " << f << "\n";
  int answer = 1;
  if(f == 0)
    {
      return answer;
    }

  for(unsigned int i = 1; i <= f; ++i)
    {
      answer*=i;
      std::cout << "i: " << i << "\n";
    }
  return answer;
}



Token Token_stream::get()    // characters from cin turn them into tokens
{
  if(full) // check if we already have a token stored
    {
      full = false;
      return buffer;
    }
  char ch;
  std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

  switch (ch) {
  case print:
  case quit:
  case '(':
  case ')':
  case '{':
  case '}':
  case '+':
  case '-':
  case '*':
  case '/': 
  case '!':
  case '%':
  case '=':
    return Token(ch);        // let each character represent itself
  case '.':
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    {
      std::cin.putback(ch);         // put digit back into the input stream
      double val;
      std::cin >> val;              // read a floating-point number
      return Token(number,val);   // let '8' represent "a number"
    }
  default:
    {
      if(isalpha(ch))
        {
          std::string s;
          s+=ch;
          while(std::cin.get(ch) && (isalpha(ch) || isdigit(ch)))
            {
              s+=ch;
            }
            std::cin.putback(ch);
            std::cout << "String s in get after putback " << s << '\n';
            if(s == declkey)
              {
                return Token(let); // declaration keyword
              }
            return Token(name,s);
        }
      throw std::runtime_error("Bad Token");
    }
  }
}


double expression(Token_stream& ts);  // read and evaluate a Expression

double primary(Token_stream& ts)
{
  Token t = ts.get();
  switch(t.kind)
    {
    case '(':
      {

        double d = expression(ts);
        t = ts.get();
        if(t.kind != ')')
          {
            throw std::runtime_error(" ) expected");
          }
        return d;
      }
    case '{':
      {

        double d = expression(ts);
        t = ts.get();
        if(t.kind != '}')
          {
            throw std::runtime_error(" } expected");
          }
        return d;
      }
    case number:
      {
        return t.value;
      }
    case '+':
      {
        return primary(ts);
      }
    case '-':
      {
        return -primary(ts);
      }
    case name:
      {
        return get_value(t.name);
      }
    default:
      {
        ts.put_back(t);
        throw std::runtime_error("primary expected");
      }
    }
}

double lower_term(Token_stream& ts)
{
  double left = primary(ts);
  Token t = ts.get();
  while(true)
    {
      switch(t.kind)
        {
        case '!':
          left = factorial((int)left);
          t = ts.get();
          break;
        default:
          ts.put_back(t);
          return left;
        }
    }
}

double term(Token_stream& ts)
{
  double left = lower_term(ts);
  Token t = ts.get();

  while(true)
    {
      switch(t.kind)
        {
        case '*':
          {
            left*=lower_term(ts);
            t = ts.get();
            break;
          }
        case '/':
          {
            double d = lower_term(ts);
            if(d == 0)
              {
                throw std::runtime_error("Cant divide by zero");
              }
            left/=d;
            t=ts.get();
            break;
          }
        case '%':
          {
            double d = term(ts);
            int left_int = int(left); // convert the left hand side into an int
            if(left_int != left) // then compare the new left to the original, if doesnt match then it wasnt an int to begin with
              {
                throw std::runtime_error("left hand operand of % is not int");
              }
            int right_int = int(d); // same as above
            if(right_int != d)
              {
                throw std::runtime_error("right hand operand of % is not int");
              }
            
            if(right_int == 0)
              {
                throw std::runtime_error("right hand operand of % is zero");
              }
            left = left_int % right_int;
            t = ts.get();
            break;
        }
          
        default:
          {
            ts.put_back(t);
            return left;
          }
        }
    }
}

double expression(Token_stream& ts)
{
  double left = term(ts);
  Token t = ts.get();
  while(true)
    {
      switch(t.kind)
        {
        case '+':
          {
            left+=term(ts);
            t = ts.get();
            break;
          }
        case '-':
          {
            left-= term(ts);
            t = ts.get();
            break;
          }
        default:
          {
            ts.put_back(t);
            return left;
          }
        }
    }
}

bool is_declared(std::string var) // is var declared i.e. is var in var_table
{
  for(unsigned int i = 0; i < var_table.size(); ++i)
    {
      if(var_table[i].name == var)
        {
          return true;
        }
    }
  return false;
}

double define_name(std::string var, double val)
{
  if(is_declared(var))
    {
      error(var, " is declared twice");
    }
  var_table.push_back(Variable(var,val));
  return val;
}

double declaration(Token_stream& ts)
// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the inital value "expression"
{
  Token t = ts.get();
  if(t.kind != name)
   {
     throw std::runtime_error("name expected in declaration");
   }
  
  std::string var_name = t.name;
  Token t2 = ts.get();
  if(t2.kind != '=')
    {
      error(" = missing in declaration of ", var_name);
    }

  double d = expression(ts);
  define_name(var_name,d);
  return d;
}
double statement(Token_stream& ts)
{
  Token t = ts.get();
  switch(t.kind)
    {
    case let:
      return declaration(ts);
    default:
      ts.put_back(t);
      return expression(ts);
    }
}

void clean_up(Token_stream& ts)
{
  ts.ignore(print);
}
void calculate()
{
  Token_stream ts(std::cin);
  while(std::cin)
    {
      char test = std::cin.peek();
      std::cout << "peek: " << test << '\n';
      try
        {
          std::cout << prompt;
          Token t = ts.get();
          while(t.kind == print)
            {
              t = ts.get();
            }
          if(t.kind == quit)
            {
              break;
            }
          ts.put_back(t);
          std::cout << result <<  statement(ts) << std::endl;
       }
      catch(std::exception& e)
       {
          std::cout << "in catch calculate \n";
          std::cerr << e.what() << std::endl;
          clean_up(ts);
        }
    }
}
int main()
{
      std::cout << "Welcome to our simple calculator.\n"
                << "Please enter expressions using floating-point numbers.\n";
      std::cout << "Operators available (), *, /, +, -, ; (print answer), q (quit program)\n";
  try
    {
      // predefined names
      define_name("pi",std::atan(1.0)*4);
      define_name("e" ,2.7182818284);
      calculate();
      keep_window_open();
      return 0;
    }
  catch(std::runtime_error& e)
    {
      std::cerr << e.what() << std::endl;
      std::cout << "in main catch \n";
      keep_window_open();
      return -1;
    }
  catch(...)
    {
      std::cout << "in main catch everything \n";
      std::cerr << "exception \n";
    }
}
