#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <list>
#include <set>

#include "fact.h"

typedef std::list<Fact> FactsBunch;

class Rule{
public:
  bool deduce(const std::set<Fact> &activeFacts) const;
  Rule(const std::list<FactsBunch> &body, const Fact &head) : body(body), head(head) {}
  const Fact &getHead() const{return head;}
private:
  std::list<FactsBunch> body;
  Fact head;
};

#endif
