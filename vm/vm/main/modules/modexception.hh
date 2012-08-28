// Copyright © 2011, Université catholique de Louvain
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// *  Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// *  Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef __MODEXCEPTION_H
#define __MODEXCEPTION_H

#include "../mozartcore.hh"

#include <iostream>

#ifndef MOZART_GENERATOR

namespace mozart {

namespace builtins {

//////////////////////
// Exception module //
//////////////////////

class ModException: public Module {
public:
  ModException(): Module("Exception") {}

  class Raise: public Builtin<Raise> {
  public:
    Raise(): Builtin("raise") {}

    void operator()(VM vm, In value) {
      return raise(vm, value);
    }
  };

  class RaiseError: public Builtin<RaiseError> {
  public:
    RaiseError(): Builtin("raiseError") {}

    void operator()(VM vm, In value) {
      return raise(vm, buildRecord(
        vm, buildArity(vm, MOZART_STR("error"), 1, MOZART_STR("debug")),
        value, unit));
    }
  };

  class Fail: public Builtin<Fail> {
  public:
    Fail(): Builtin("fail") {}

    void operator()(VM vm) {
      return fail(vm);
    }
  };
};

}

}

#endif // MOZART_GENERATOR

#endif // __MODEXCEPTION_H
