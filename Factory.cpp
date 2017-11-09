//
// Factory.cpp for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:20:07 2017 Kévin Nogué
// Last update Wed Jul 26 15:19:14 2017 baud
//

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Double.hpp"
#include "Float.hpp"
#include "BigDecimal.hpp"
#include "Exception.hpp"
#include "Factory.hh"

Factory::Factory(eOperandType type, const std::string &nb)
  : _type(type), _value(nb)
{
}

IOperand	*Factory::createInt8(const std::string &nb)
{
  return (new Int8(nb));
}

IOperand	*Factory::createInt16(const std::string &nb)
{
  return (new Int16(nb));
}

IOperand	*Factory::createInt32(const std::string &nb)
{
  return (new Int32(nb));
}

IOperand	*Factory::createFloat(const std::string &nb)
{
  return (new Float(nb));
}

IOperand	*Factory::createDouble(const std::string &nb)
{
  return (new Double(nb));
}

IOperand	*Factory::createBigDecimal(const std::string &nb)
{
  return (new BigDecimal(nb));
}

IOperand* Factory::createOperand(eOperandType type, const std::string& nb)
{
  Factory	*inst;

  inst = new Factory(type, nb);
  return(inst->makeOperand());
}

eOperandType                    Factory::getOperandTypeFromStr(std::string const& str)
{
  std::vector<std::string>      tab_types;
  int                           i;
  std::string			type;

  type = str;
  tab_types.push_back("int8");
  tab_types.push_back("int16");
  tab_types.push_back("int32");
  tab_types.push_back("float");
  tab_types.push_back("double");
  tab_types.push_back("bigdecimal");
  std::transform(type.begin(), type.end(), type.begin(), ::tolower);
  for (i = 0; i < tab_types.size(); i++)
    if (str.find(tab_types[i]) != std::string::npos)
      return ((eOperandType) i);
  throw Exception(SYNTAX_ERROR);
}

IOperand	*Factory::makeOperand()
{
  typedef IOperand *(Factory::*ptrf) (std::string const&);
  ptrf		members[6];

  members[0] = &Factory::createInt8;
  members[1] = &Factory::createInt16;
  members[2] = &Factory::createInt32;
  members[3] = &Factory::createFloat;
  members[4] = &Factory::createDouble;
  members[5] = &Factory::createBigDecimal;
  return ((this->*members[_type])(_value));
}
