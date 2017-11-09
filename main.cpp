//
// main.cpp for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:22:29 2017 Kévin Nogué
// Last update Wed Jul 26 15:22:30 2017 baud
//

#include <iostream>
#include "IOperand.hpp"
#include "Parser.hh"
#include "Memory.hh"

int		main(int ac, char **av)
{
  std::string	fileName;
  Parser	*parser;
  Memory	*mem;

  if (ac > 1)
    fileName = std::string(av[1]);
  parser = new Parser(fileName);
  mem = new Memory;
  try
    {
      parser->getContentOfFile();
      parser->start(mem);
    }
  catch (Exception const &e)
    {
      if (e.getLine() != -1)
	{
	  std::cerr << "Line " << e.getLine() << " : ";
	}
      std::cerr << "error : " << e.what() << std::endl;
      exit(84);
    }
  return (0);
}
