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
 *
 * \brief   Contains icl_core::thread::MutexImplWin32
 *
 * \b icl_core::thread::MutexImplWin32
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_THREAD_MUTEX_IMPL_WIN32_H_INCLUDED
#define ICL_CORE_THREAD_MUTEX_IMPL_WIN32_H_INCLUDED

#include <Windows.h>

#include "icl_core_thread/MutexImpl.h"

namespace icl_core {
namespace thread {

class MutexImplWin32 : public MutexImpl, protected virtual icl_core::Noncopyable
{
public:
  MutexImplWin32();
  virtual ~MutexImplWin32();

  virtual bool lock();
  virtual bool lock(const TimeStamp& timeout);
  virtual bool lock(const TimeSpan& timeout);
  virtual bool tryLock();
  virtual void unlock();

private:
  HANDLE m_mutex;
};

}
}

#endif
