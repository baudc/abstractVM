//
// IOperand.hpp for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:20:01 2017 Kévin Nogué
// Last update Mon Jul 24 17:31:33 2017 baud
//

#ifndef __IOPERAND_HPP_
#define __IOPERAND_HPP_

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "Exception.hpp"

typedef enum t_eOperandType
  {
    t_Int8 = 0,
    t_Int16,
    t_Int32,
    t_Float,
    t_Double,
    t_BigDecimal
  }		eOperandType;

class IOperand
{
public:
  virtual std::string toString() const = 0;

  virtual eOperandType getType() const = 0;

  virtual IOperand* operator+(const IOperand &rhs) const = 0;
  virtual IOperand* operator-(const IOperand &rhs) const = 0;
  virtual IOperand* operator*(const IOperand &rhs) const = 0;
  virtual IOperand* operator/(const IOperand &rhs) const = 0;
  virtual IOperand* operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {};
};

#endif /* __IOPERAND_HPP_ */
