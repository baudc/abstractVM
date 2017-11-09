//
// Stack.cpp for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:19:42 2017 Kévin Nogué
// Last update Wed Jul 26 17:10:12 2017 baud
//

#include "my.hpp"
#include "Memory.hh"

void		Memory::push(IOperand *number)
{
  _stack.insert(_stack.begin(), number);
}

Memory::Memory()
{
  for (int i = 0; i < 16; i++)
    {
      _registres[i] = new registre_t;
      _registres[i]->numero = i;
      _registres[i]->value = NULL;
    }
}

void		Memory::pop()
{
  if (_stack.size() < 1)
    throw Exception(POP_EMPTY_STACK);
  _stack.erase(_stack.begin());
}

static void	display(IOperand *iop)
{
  if (iop != NULL)
    std::cout << iop->toString() << std::endl;
}

void		Memory::dump()
{
  std::for_each(_stack.begin(), _stack.end(), display);
}

void		Memory::add()
{
  IOperand	*res;
  IOperand	*nb1;
  IOperand	*nb2;

  if (_stack.size() >= 2)
    {
      nb1 = _stack.front();
      pop();
      nb2 = _stack.front();
      pop();
      res = *nb2 + *nb1;
      push(res);
      delete nb1;
      delete nb2;
    }
  else
    throw Exception(MISS_VALUE_STACK);
}

void		Memory::mul()
{
  IOperand	*res;
  IOperand      *nb1;
  IOperand      *nb2;

  if (_stack.size() >= 2)
    {
      nb1 = _stack.front();
      pop();
      nb2 = _stack.front();
      pop();
      res = *nb2 * *nb1;
      push(res);
      delete nb1;
      delete nb2;
    }
  else
    throw Exception(MISS_VALUE_STACK);
}

void		Memory::div()
{
  IOperand	*res;
  IOperand      *nb1;
  IOperand      *nb2;

  if (_stack.size() >= 2)
    {
      nb1 = _stack.front();
      pop();
      nb2 = _stack.front();
      pop();
      if (my_atof(nb1->toString().c_str()) == 0)
	throw Exception(DIVISION_ZERO);
      else
	res = *nb2 / *nb1;
      push(res);
      delete nb1;
      delete nb2;
    }
  else
    throw Exception(MISS_VALUE_STACK);
}

void		Memory::mod()
{
  IOperand	*res;
  IOperand      *nb1;
  IOperand      *nb2;

  if (_stack.size() >= 2)
    {
      nb1 = _stack.front();
      pop();
      nb2 = _stack.front();
      pop();
      if (my_atof(nb1->toString().c_str()) == 0)
	throw Exception(MODULO_ZERO);
      else
	res = *nb2 % *nb1;
      push(res);
      delete nb1;
      delete nb2;
    }
  else
    throw Exception(MISS_VALUE_STACK);
}

void		Memory::sub()
{
  IOperand	*res;
  IOperand      *nb1;
  IOperand      *nb2;

  if (_stack.size() >= 2)
    {
      nb1 = _stack.front();
      pop();
      nb2 = _stack.front();
      pop();
      res = *nb2 - *nb1;
      push(res);
      delete nb1;
      delete nb2;
    }
  else
    throw Exception(MISS_VALUE_STACK);
}

void		Memory::clear()
{
  _stack.clear();
}

void		Memory::dup()
{
  IOperand	*dup;

  if (_stack.size() <= 0)
    throw Exception(DUP_EMPTY_STACK);
  else
    dup = Factory::createOperand(_stack.front()->getType(), _stack.front()->toString());
  push(dup);
}

void		Memory::swap()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (_stack.size() <= 1)
    throw Exception(MISS_VALUE_STACK);
  else
    {
      nb1 = _stack.front();
      pop();
      nb2 = _stack.front();
      pop();
      push(nb1);
      push(nb2);
    }
}

void		Memory::load(size_t v)
{
  registre_t	*registre;

  registre = 0;
  if (_registres[v]->value == NULL)
    throw Exception("No value on register");
  for (int i = 0; i < 16; i++)
    if (_registres[i]->numero == v)
      {
	registre = _registres[i];
	break;
      }
  if (registre && registre->value)
    {
      registre->value = 0;
      push(registre->value);
    }
  else
    throw Exception(UNKNOWN_REGISTER);
}

void	        Memory::store(size_t v)
{
  registre_t	*registre;

  registre = 0;
  if (v >= 16)
    throw Exception(UNKNOWN_REGISTER);
  if (_stack.size() < 1)
    throw Exception(MISS_VALUE_STACK);
  for (int i = 0; i < 16; i++)
    if (_registres[i]->numero == v)
      registre = _registres[i];
  registre->value = _stack.front();
  pop();
}

void		Memory::print()
{
  IOperand	*nb;

  if (_stack.size() < 1)
    throw Exception(MISS_VALUE_STACK);
  nb = _stack.front();
  if (nb->getType() == t_Int8)
    std::cout << (char)my_atoi(nb->toString().c_str()) << std::endl;
  else
    throw Exception(NOT_8_BIT);
}

void		Memory::assert(IOperand* op)
{
  IOperand	*nb;

  if (_stack.size() < 1)
    throw Exception(MISS_VALUE_STACK);
  nb = _stack.front();
  if (nb->toString() != op->toString() ||
      nb->getType() != op->getType())
    throw Exception(VAL_NOT_EQUAL);
}
