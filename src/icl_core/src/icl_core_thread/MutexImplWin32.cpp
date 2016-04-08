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
 * \date    2007-10-24
 */
//----------------------------------------------------------------------

#include "icl_core_thread/Common.h"
#include "icl_core_thread/MutexImplWin32.h"

namespace icl_core {
namespace thread {

MutexImplWin32::MutexImplWin32()
{
  m_mutex = ::CreateMutex(NULL, false, NULL);
}

MutexImplWin32::~MutexImplWin32()
{
  if (m_mutex != 0)
  {
    ::CloseHandle(m_mutex);
  }
}

bool MutexImplWin32::lock()
{
  return ::WaitForSingleObject(m_mutex, INFINITE) == WAIT_OBJECT_0;
}

bool MutexImplWin32::lock(const TimeStamp& timeout)
{
  return lock(impl::getRelativeTimeout(timeout));
}

bool MutexImplWin32::lock(const TimeSpan& timeout)
{
  return ::WaitForSingleObject(m_mutex, DWORD(timeout.toMSec())) == WAIT_OBJECT_0;
}

bool MutexImplWin32::tryLock()
{
  return ::WaitForSingleObject(m_mutex, 0) == WAIT_OBJECT_0;
}

void MutexImplWin32::unlock()
{
  ::ReleaseMutex(m_mutex);
}

}
}
