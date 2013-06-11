#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdexcept>
class Token
{
    public:
        char kind;
        double value;
        Token(char ch)
            :kind(ch),value(0){}
        Token(char ch,double val)
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
          throw std::runtime_error("Buffer is full");
    }
    buffer = t;
    full = true;
}

void keep_window_open()
{
	std::cin.clear();
	std::cout << "Please enter a character to exit\n";
	char ch;
	std::cin >> ch;
	return;
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

Token Token_stream::get()    // read a token from cin
{
    if(full)
    {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            std::cin.putback(ch);         // put digit back into the input stream
            double val;
            std::cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
	throw std::runtime_error("Bad Token");
    }
}



Token_stream ts;
double expression();  // read and evaluate a Expression

double primary()
{
    Token t = ts.get();
    switch(t.kind)
    {
        case '(':
            {

               double d = expression();
               t = ts.get();
               if(t.kind != ')')
               {
		   throw std::runtime_error(" ) expected");
               }
               return d;
            }
         case '{':
            {

               double d = expression();
               t = ts.get();
               if(t.kind != '}')
               {
                     throw std::runtime_error(" } expected");
               }
               return d;
            }
        case '8':
            {
                return t.value;
            }

        default:
            {
	      throw std::runtime_error("primary expected");
            }
    }
}

double lower_term()
{
    double left = primary();
    std::cout << left << "left \n";
    Token t = ts.get();

    std::cout << "Token-kind: " << t.kind << "\n";
    while(true)
    {
        switch(t.kind)
        {
	case '!':
	  left = factorial(left);
	  std::cout << "left in switch: " << left << "\n";
	  t = ts.get();
	  break;
	default:
	  ts.put_back(t);
	  return left;
        }
    }
}

double term()
{
    double left = lower_term();
    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '*':
                {
                    left*=lower_term();
                    t = ts.get();
                    break;
                }
            case '/':
                {
                    double d = lower_term();
                    if(d == 0.0)
                    {
                          throw std::runtime_error("Cant divide by zero");
                    }
                    left/=d;
                    t=ts.get();
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

double expression()
{
    double left = term();
    Token t = ts.get();
    while(true)
    {
        switch(t.kind)
        {
            case '+':
                {
                    left+=term();
                    t = ts.get();
                    break;
                }
            case '-':
                {
                    left-= term();
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

int main()
{
    try
    {
        std::cout << "Welcome to our simple calculator.\n"
            << "Please enter expressions using floating-point numbers.\n";
        std::cout << "Operators available (), *, /, +, -, = (print answer), x (quit program)\n";
        double val = 0;
        while(std::cin)
        {
	  std::cout << ">";
            Token t = ts.get();
            if(t.kind == 'q')
            {
                keep_window_open();
                break;
            }
            else if(t.kind == ';')
            {
                std::cout << "=" << val << '\n';
            }
            else
            {
                ts.put_back(t);
                val = expression();
            }
        }
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch(...)
    {
        std::cerr << "exception \n";
    }
}
