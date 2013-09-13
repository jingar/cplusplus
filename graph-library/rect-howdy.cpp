#include <Simple_window.h>
#include <Graph.h>

int main()
{
  using namespace Graph_lib;
  Simple_window win(Point(0,0),600,400,"Canvas");

  Rectangle rect(Point(200,200),100,30);
  win.attach(rect);

  Text t(Point(230,220),"Howdy!");
  win.attach(t);

  win.wait_for_button();
  
}
