//
// Factory.hh for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:22:08 2017 Kévin Nogué
// Last update Wed Jul 26 15:19:30 2017 baud
//

#ifndef _FACTORY_H__
#define _FACTORY_H__

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "IOperand.hpp"

class			Factory
{
 public:
  Factory(eOperandType, const std::string &);

  IOperand		*makeOperand();
  static IOperand*	createOperand(eOperandType type,
				      const std::string& value);
  static eOperandType	getOperandTypeFromStr(std::string const& str);

 private:
  virtual IOperand*	createInt8(const std::string& value);
  virtual IOperand*	createInt16(const std::string& value);
  virtual IOperand*	createInt32(const std::string& value);
  virtual IOperand*	createFloat(const std::string& value);
  virtual IOperand*	createDouble(const std::string& value);
  virtual IOperand*	createBigDecimal(const std::string& value);

  eOperandType		_type;
  std::string		_value;
};

#endif /* _FACTORY_H__ */
