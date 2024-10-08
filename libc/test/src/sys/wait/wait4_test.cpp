//===-- Unittests for wait4 -----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/sys/wait/wait4.h"
#include "test/UnitTest/ErrnoSetterMatcher.h"
#include "test/UnitTest/Test.h"

#include <sys/wait.h>

// The test here is a simpl test for WNOHANG functionality. For a more
// involved test, look at fork_test.

TEST(LlvmLibcwait4Test, NoHangTest) {
  using LIBC_NAMESPACE::testing::ErrnoSetterMatcher::Fails;
  int status;
  ASSERT_THAT(LIBC_NAMESPACE::wait4(-1, &status, WNOHANG, nullptr),
              Fails(ECHILD));
}
