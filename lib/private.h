
#ifndef PRIVATE_H_INCLUDED
#define PRIVATE_H_INCLUDED
#pragma once
#include<stdio.h>
#include "list.h"
#include "page.h"

void insertEdit(char** params, Page* popPage, List* popEditor);
void printPage(Page* popEditor);
List* deleteEdit(char ** params, List* popEditor, Page* popPage);
void insertLink(char** params, Page* popPage);
void isLink(char** params,Page* popPage);
void logg(char* logM);
void fprintPage(char ** params, Page* popPage);
#endif // PRIVATE_H_INCLUDED
