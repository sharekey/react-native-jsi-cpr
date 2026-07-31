#pragma once

#include <JsiCprSpecJSI.h>

#include "JsiHttp.h"

#include <memory>

namespace facebook::react {

class JsiCprImpl : public NativeJsiCprCxxSpec<JsiCprImpl> {
 public:
  explicit JsiCprImpl(std::shared_ptr<CallInvoker> jsInvoker);

  bool install(jsi::Runtime& runtime);

 private:
  std::shared_ptr<CallInvoker> jsInvoker_;
  std::unique_ptr<jsiHttp::JsiHttp> http_;
};

} // namespace facebook::react
