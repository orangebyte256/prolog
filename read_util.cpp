#include "rule.h"
#include "read_util.h"

static Fact readFact(std::stringstream &input){
  std::string res;
  while(isalpha(input.peek()) || input.peek() == '_'){
    res += input.get();
  }
  return Fact(res);
}

static FactsBunch readFactsBunch(std::stringstream &input){
  FactsBunch factsBunch;
  factsBunch.push_back(readFact(input));
  while(input.peek() == ','){
    input.get();
    factsBunch.push_back(readFact(input));
  }
  return factsBunch;
}

static Rule readRule(std::stringstream &input){
  Body body;
  body.push_back(readFactsBunch(input));
  while(input.peek() == '|'){
    input.get();
    body.push_back(readFactsBunch(input));
  }
  Fact head;
  if(input.get() == '-' && input.get() == '>')
    head = readFact(input);
  return Rule(body, head);
}

static void getCleanString(std::istream &input, std::stringstream &inputss){
  std::string str;
  std::getline(input, str);
  str.erase(std::remove_if(str.begin(), str.end(), 
        ([](char val){return val == ' ' || val == '"';})), str.end());
  inputss.str(str);
}

std::tuple<FactsBunch, Rules> readFactsAndRules(std::istream &input){
  Rules rules;
  std::stringstream inputss;
  getCleanString(input, inputss);
  FactsBunch factsBunch = readFactsBunch(inputss);
  inputss.clear();
  getCleanString(input, inputss);
  rules.push_back(readRule(inputss));
  while(inputss.peek() == ','){
    inputss.get();
    rules.push_back(readRule(inputss));
  }
  return std::make_tuple(factsBunch, rules);
}


