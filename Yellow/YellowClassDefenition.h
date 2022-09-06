#pragma once

class Rectangle {
public:
  Rectangle(int width, int height);


  int GetArea() const;
  int GetPerimetr() const;

  int GetWidth() const;
  int GetHeight() const;

private:
  int width_, height_;
};