#include <tuple>

#include "read_util.h"

std::set<Fact> deduce(std::set<Fact> &activeFacts, Rules &rules){
  std::set<Fact> result;
  while(true){
    auto it = std::find_if(rules.begin(), rules.end(), ([&] (Rule &v) {return v.deduce(activeFacts); }));
    if(it == rules.end())
      break;
    activeFacts.insert(it->getHead());
    result.insert(it->getHead());
    rules.erase(it);
  }
  return result;
}

int main(){
  std::tuple<FactsBunch, std::list<Rule>> factsAndRules = readFactsAndRules(std::cin);
  std::set<Fact> activeFacts(std::get<0>(factsAndRules).begin(), 
      std::get<0>(factsAndRules).end());
  Rules rules = std::get<1>(factsAndRules);
  auto result = deduce(activeFacts, rules);
  std::cout << "Result: ";
  for(auto &it : result){
    std::cout << it << " ";
  }
  return 0;
}
