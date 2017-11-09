//
// Parser.hh for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:19:48 2017 Kévin Nogué
// Last update Wed Jul 26 14:15:24 2017 Kévin Nogué
//

#ifndef PARSER_HH
#define PARSER_HH

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <exception>
#include "Memory.hh"
#include "Factory.hh"

class				Parser
{
public:
  Parser(std::string const &);
  typedef void                  (Parser::*pf)(std::string);
  void				getContentOfFile();
  void				start(Memory *);
  static std::string		epur_string(std::string const&);
private:
  void				initList();
  int				callCmd(std::string const&);
  void				pPush(std::string);
  void				pPop(std::string);
  void				pDump(std::string);
  void				pClear(std::string);
  void				pDup(std::string);
  void				pSwap(std::string);
  void				pAssert(std::string);
  void				pAdd(std::string);
  void				pSub(std::string);
  void				pMul(std::string);
  void				pDiv(std::string);
  void				pMod(std::string);
  void				pLoad(std::string);
  void				pStore(std::string);
  void				pPrint(std::string);
  void				pExit(std::string);
  
  std::string const		_nameOfFile;
  std::vector<std::string>	_lines;
  Memory*			_memory;
  pf				_membersTab[16];
  std::string			_commandTab[16];
  
};

#endif
