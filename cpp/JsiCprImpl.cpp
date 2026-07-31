#include "JsiCprImpl.h"

#include <utility>

namespace facebook::react {

JsiCprImpl::JsiCprImpl(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeJsiCprCxxSpec(jsInvoker), jsInvoker_(std::move(jsInvoker)) {}

bool JsiCprImpl::install(jsi::Runtime& runtime) {
  if (runtime.global().hasProperty(runtime, "jsiHttp")) {
    return true;
  }

  http_ = std::make_unique<jsiHttp::JsiHttp>(&runtime, jsInvoker_);
  http_->installJSIBindings("");
  return runtime.global().hasProperty(runtime, "jsiHttp");
}

} // namespace facebook::react
