// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of FZIs ic_workspace.
//
// This program is free software licensed under the LGPL
// (GNU LESSER GENERAL PUBLIC LICENSE Version 3).
// You can find a copy of this license in LICENSE folder in the top
// directory of the source code.
//
// © Copyright 2016 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2011-06-07
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_CONFIG_T_CONFIG_PARAMETER_H_INCLUDED
#define ICL_CORE_CONFIG_T_CONFIG_PARAMETER_H_INCLUDED

#include <icl_core/Deprecate.h>

#include "icl_core_config/ConfigParameter.h"

namespace icl_core {
namespace config {

typedef ICL_CORE_VC_DEPRECATE ConfigParameter tConfigParameter ICL_CORE_GCC_DEPRECATE;
typedef ICL_CORE_VC_DEPRECATE ConfigParameterList tConfigParameterList ICL_CORE_GCC_DEPRECATE;

}
}

#endif
