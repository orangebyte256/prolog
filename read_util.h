#include <algorithm>
#include <list>
#include <sstream>
#include <tuple>

#include "rule.h"

typedef std::list<FactsBunch> Body;
typedef std::list<Rule> Rules;

std::tuple<FactsBunch, Rules> readFactsAndRules(std::istream &input);


