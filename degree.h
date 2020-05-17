#pragma once
#ifndef DEGREE_H
#define DEGREE_H

#include <string>
using namespace std;

enum DegreeType { SECURITY, NETWORK, SOFTWARE };//the types of degrees

static const std::string degreeTypeStrings[] = { "Security", "Network", "Software" };

#endif
//degree.h