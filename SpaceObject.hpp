#include <SFML/Graphics.hpp>

namespace Computing4Final {

class SpaceObject : public sf::Drawable {
public:
  SpaceObject();
  
  void setXPos(double xpos);
  void setYPos(double ypos);
  void setXVel(double xvel);
  void setYVel(double yvel);
  void setMass(double mass);
  double getXPos();
  double getYPos();
  double getXVel();
  double getYVel();
  double getMass();
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  double xpos_;
  double ypos_;
  double xvel_;
  double yvel_;
  double mass_;
}

class Body : public SpaceObject {
public:
  Body();
  Body(sf::Texture texture);
friend std::istream& operator>> (std::istream &in, Body &body);
double step (double seconds);
private:
  sf::Texture texture_;
  double seconds_;
}

class Star : public SpaceObject {
public:
  Star();
  Star(double radius);
private:
  double radius_;
}

}
