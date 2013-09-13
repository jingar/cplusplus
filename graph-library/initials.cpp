#include <Simple_window.h>
#include <Graph.h>

int main()
{
  using namespace Graph_lib;
  Simple_window win(Point(0,0),600,400,"Canvas");

  Open_polyline inital_s;
  inital_s.add(Point(100,50));
  inital_s.add(Point(50,50));
  inital_s.add(Point(50,100));
  inital_s.add(Point(100,100));
  inital_s.add(Point(100,150));
  inital_s.add(Point(50,150));
  win.attach(inital_s);

  Open_polyline part_inital_a_left;
  part_inital_a_left.add(Point(150,50));
  part_inital_a_left.add(Point(130,150));
  win.attach(part_inital_a_left);

  Open_polyline part_inital_a_right;
  part_inital_a_right.add(Point(150,50));
  part_inital_a_right.add(Point(170,150));
  win.attach(part_inital_a_right);

  Open_polyline part_inital_a_middle;
  part_inital_a_middle.add(Point(135,115));
  part_inital_a_middle.add(Point(165,115));
  win.attach(part_inital_a_middle);


  win.wait_for_button();
  
}
