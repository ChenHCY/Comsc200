#include "Floor.h"
#include "Rider.h"
#include "Panel.h"
#include "Building.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label):elevation(elevation), name(name), label(label)
{
  //add up and down buttons into the panel
  panel.addButton(UP);
  panel.addButton(DOWN);
  if (TOP < elevation) 
  {
    TOP = elevation;
  }
  if (elevation < BOTTOM) 
  {
   BOTTOM = elevation;
  }
}

ostream& operator<<(ostream& out, const Floor& floor)
{
    
    out.width(3);
    out << floor.label ;
    out.width(15);
    out << floor.name << " at " ;
    out.width(6);//continue
    out << floor.elevation << "   Up/Down: " << floor.upRiders.size() << "/" << floor.downRiders.size() << "   Button: " << floor.panel;
    return out;
}

void Floor::addRider(const Rider& r)
{
  if(r.goingUp)
  {
    upRiders.push(r);
    panel.press(UP);
  }
  if(r.goingDown)
  {
    downRiders.push(r);
    panel.press(DOWN);;
  }
}

Rider Floor::removeUpRider()
{
  if(upRiders.empty())
  {
    throw
    "No Riders Up!";
  }
  Rider ptr = upRiders.front();
  upRiders.pop();
  return ptr;
}

Rider Floor::removeDownRider()
{
  if(downRiders.empty())
  {
    throw
    "No Riders Down!";
  }
  Rider ptr = downRiders.front();
  downRiders.pop();
  return ptr;
}