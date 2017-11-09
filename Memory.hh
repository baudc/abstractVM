//
// Stack.hh for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:19:32 2017 Kévin Nogué
// Last update Wed Jul 26 17:01:22 2017 baud
//

#ifndef _MEMORY_HH_
# define _MEMORY_HH_

#include <vector>
#include <exception>
#include <cstdlib>
#include "IOperand.hpp"
#include "Factory.hh"
#include "Exception.hpp"

typedef struct
{
  int		numero;
  IOperand	*value;
}		registre_t;

class		Memory
{
public:
  Memory();
  
  void		push(IOperand*);
  void		dump();
  void		pop();
  void		add();
  void		sub();
  void		mul();
  void		div();
  void		mod();
  void		clear();
  void		dup();
  void		swap();
  void		load(size_t);
  void		store(size_t);
  void		print();
  void		assert(IOperand*);
private:
  std::vector<std::string>	_file;
  std::vector<IOperand*>	_stack;	
  registre_t			*_registres[16];
};

#endif
