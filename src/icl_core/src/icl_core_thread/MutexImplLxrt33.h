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
 *
 * \brief   Contains icl_core::thread::MutexImplLxrt33
 *
 * \b icl_core::thread::MutexImplLxrt33
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_THREAD_MUTEX_IMPL_LXRT33_H_INCLUDED
#define ICL_CORE_THREAD_MUTEX_IMPL_LXRT33_H_INCLUDED

#include <rtai_posix.h>

#include "icl_core_thread/MutexImpl.h"

namespace icl_core {
namespace thread {

class MutexImplLxrt33 : public MutexImpl, protected virtual icl_core::Noncopyable
{
public:
  MutexImplLxrt33();
  virtual ~MutexImplLxrt33();

  virtual bool lock();
  virtual bool lock(const icl_core::TimeSpan& timeout);
  virtual bool lock(const icl_core::TimeStamp& timeout);
  virtual bool tryLock();
  virtual void unlock();

private:
  pthread_mutex_t *m_mutex;
};

}
}

#endif
