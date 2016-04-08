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
 * \author  Kay-Ulrich Scholl <scholl@fzi.de>
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2006-06-10
 *
 * \brief   Contains icl_core::thread::MutexImplPosix
 *
 * \b icl_core::thread::MutexImplPosix
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_THREAD_MUTEX_IMPL_POSIX_H_INCLUDED
#define ICL_CORE_THREAD_MUTEX_IMPL_POSIX_H_INCLUDED

#include "icl_core/TimeSpan.h"
#include "icl_core/TimeStamp.h"
#include "icl_core_thread/MutexImpl.h"

namespace icl_core {
namespace thread {

class MutexImplPosix : public MutexImpl, protected virtual icl_core::Noncopyable
{
public:
  MutexImplPosix();
  virtual ~MutexImplPosix();

  virtual bool lock();
  virtual bool lock(const ::icl_core::TimeStamp& timeout);
  virtual bool lock(const ::icl_core::TimeSpan& timeout);
  virtual bool tryLock();
  virtual void unlock();

private:
  pthread_mutex_t *m_mutex;
};

}
}

#endif
