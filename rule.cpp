#include "rule.h"

bool Rule::deduce(const std::set<Fact> &activeFacts) const{
  for(auto &factsBunch : body){
    bool find = true;
    for(auto &fact : factsBunch){
      if(activeFacts.find(fact) == activeFacts.end()){
        find = false;
        break;
      }
    }
    if(find) return true;
  }
  return false;
}

