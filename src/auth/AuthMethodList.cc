// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*- 
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2004-2009 Sage Weil <sage@newdream.net>
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software 
 * Foundation.  See file COPYING.
 * 
 */

#include "common/Mutex.h"
#include "common/config.h"
#include "common/debug.h"
#include "include/str_list.h"

#include "AuthMethodList.h"

const static int dout_subsys = ceph_subsys_auth;


AuthMethodList::AuthMethodList(CephContext *cct, string str)
{
  list<string> sup_list;
  get_str_list(str, sup_list);
  for (list<string>::iterator iter = sup_list.begin(); iter != sup_list.end(); ++iter) {
    if (iter->compare("cephx") == 0) {
      auth_supported.push_back(CEPH_AUTH_CEPHX);
    } else if (iter->compare("none") == 0) {
      auth_supported.push_back(CEPH_AUTH_NONE);
    } else {
      lderr(cct) << "WARNING: unknown auth protocol defined: " << *iter << dendl;
    }
  }
}

bool AuthMethodList::is_supported_auth(int auth_type)
{
  return std::find(auth_supported.begin(), auth_supported.end(), auth_type) != auth_supported.end();
}

int AuthMethodList::pick(const std::set<__u32>& supported)
{
  for (set<__u32>::const_reverse_iterator p = supported.rbegin(); p != supported.rend(); ++p)
    if (is_supported_auth(*p))
      return *p;
  return CEPH_AUTH_UNKNOWN;
}
