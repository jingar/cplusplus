#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

struct Point
{
  int x;
  int y;
  Point(int x_,int y_)
    :x(x_),y(y_){}
};

void fill_points_from_file(std::vector<Point>& points,std::string file_name)
{
  std::ifstream f_in(file_name.c_str());
  if(!f_in)
    {
      throw std::runtime_error("could not open file: " + file_name);
    }
  int x;
  int y;
  f_in.exceptions(f_in.exceptions()| std::ios_base::badbit);
  while(f_in >> x >> y)
    {
      points.push_back(Point(x,y));
    }
  if(f_in.eof())
    {
      return; 
    }
  throw std::runtime_error("error while reading"); // if it gets here means failiure bit
}
void fill_points(std::vector<Point>& points,char terminator)
{
  int x;
  int y;
  std::cin.exceptions(std::cin.exceptions()| std::ios_base::badbit);
  while(std::cin >> x >> y)
    {
      points.push_back(Point(x,y));
    }
  if(std::cin.eof())
    {
      throw std::runtime_error("end of input reached, did not find terminating character: " + terminator);
    }
  
  std::cin.clear();
  char term;
  std::cin >> term;
  if(term != terminator)
    {
      std::cin.unget();
      std::cin.clear(std::ios_base::failbit);
    }
}

void print_points(const std::vector<Point>& p,std::ostream& os)
{
  for(unsigned int i  = 0; i < p.size();++i)
    {
      os << p[i].x << " " << p[i].y << '\n';
    }
}

void print_to_file(std::vector<Point>& points,std::string file_name)
{
  std::ofstream f_out(file_name.c_str());
  if(!f_out)
    {
      throw std::runtime_error("could not open file: " + file_name);
    }
  print_points(points,f_out);
}

bool operator==(const Point& l,const Point& r)
{
  return l.x == r.x && l.y == r.y;
}


bool equal_vector(const std::vector<Point>& p1,const std::vector<Point>& p2)
{
  if(p1.size() !=  p2.size())
    {
      return false;
    }
  return std::equal(p1.begin(),p1.end(),p2.begin());
}

int main()
{
  try
    {
      // take in points from co
      std::vector<Point> points;
      std::cout << "Enter the points x  and y then followed by a terminating character * \n";
      fill_points(points,'*');

      // print points to file
      std::cout << "Enter file name to put points into \n";
      std::string file_name;
      std::cin >> file_name;
      print_to_file(points,file_name);

      //read points from file and put into processed_points
      std::cout << "Enter file name to read cords from \n";
      std::cin >> file_name;
      std::vector<Point> processed_points;
      fill_points_from_file(processed_points,file_name);
      
      std::cout << "Points \n";
      print_points(points,std::cout);
        
      std::cout << "Processed_Points \n";
      print_points(processed_points,std::cout);

      std::cout << equal_vector(points,processed_points) << '\n';
      
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "run time error: " << e.what() << '\n';
    }

}
