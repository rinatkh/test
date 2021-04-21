#pragma once

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <stdlib.h>

#include "entities.hpp"
#include "rapid/rapidxml.hpp"
#include "rapid/rapidxml_utils.hpp"
#include "rapid/rapidxml_print.hpp"


void pars(const std::string &fileXml, Component *tree);

void CreateXml(const std::string &XMLFileName, Component *tree);


