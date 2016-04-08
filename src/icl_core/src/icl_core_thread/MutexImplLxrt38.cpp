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
 * \date    2009-06-09
 * \author  Jan Oberländer <oberlaen@fzi.de>
 * \date    2009-11-09
 *
 */
//----------------------------------------------------------------------
#include "icl_core_thread/MutexImplLxrt38.h"

#include <icl_core/internal_raw_debug.h>
#include <icl_core/os_lxrt.h>

#include "icl_core_thread/Common.h"

#define STRICT_LXRT_CHECKS


namespace icl_core {
namespace thread {

MutexImplLxrt38::MutexImplLxrt38()
  : m_sem(1, BIN_SEM)
{
}

MutexImplLxrt38::~MutexImplLxrt38()
{
}

bool MutexImplLxrt38::lock()
{
  return m_sem.wait();
}

bool MutexImplLxrt38::lock(const icl_core::TimeSpan& timeout)
{
  return m_sem.wait(timeout);
}

bool MutexImplLxrt38::lock(const icl_core::TimeStamp& timeout)
{
  return m_sem.wait(timeout);
}

bool MutexImplLxrt38::tryLock()
{
  return m_sem.tryWait();
}

void MutexImplLxrt38::unlock()
{
  m_sem.post();
}

}
}
