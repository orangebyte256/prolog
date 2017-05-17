#ifndef FACT_H
#define FACT_H

#include <string>

class Fact{
public:
  Fact() : value() {}
  Fact(std::string value) : value(value) {}
  bool operator<(const Fact& fact) const{ return value < fact.value; }
  bool operator==(const Fact &fact) const{ return fact.value == value; }
  friend std::ostream& operator<<(std::ostream& out, const Fact& fact);
private:
  std::string value;
};

#endif
