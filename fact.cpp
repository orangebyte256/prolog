#include "fact.h"

std::ostream& operator<<(std::ostream& out, const Fact& fact)
{
     return out << fact.value;
}
