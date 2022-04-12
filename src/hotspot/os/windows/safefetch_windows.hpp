/*
 * Copyright (c) 2022 SAP SE. All rights reserved.
 * Copyright (c) 2022, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef OS_WINDOWS_SAFEFETCH_WINDOWS_HPP
#define OS_WINDOWS_SAFEFETCH_WINDOWS_HPP

#include "utilities/globalDefinitions.hpp"

// On windows, we use structured exception handling to implement SafeFetch

template <class T>
inline T SafeFetchXX(const T* adr, T errValue) {
  T v = 0;
  __try {
    v = *adr;
  }
  __except(EXCEPTION_EXECUTE_HANDLER) {
    v = errValue;
  }
  return v;
}

inline int SafeFetch32(const int* adr, int errValue) {
  return SafeFetchXX<int>(adr, errValue);
}

inline intptr_t SafeFetchN(const intptr_t* adr, intptr_t errValue) {
  return SafeFetchXX<intptr_t>(adr, errValue);
}

inline bool CanUseSafeFetch32() { return true; }
inline bool CanUseSafeFetchN()  { return true; }

#endif
