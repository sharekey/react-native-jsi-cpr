#pragma once

#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include <ReactCommon/CallInvokerHolder.h>

#include "JsiHttp.h"

namespace reactnativejsicpr {

using namespace facebook;

class HttpHelper : public jni::HybridClass<HttpHelper> {
 public:
  static constexpr auto kJavaDescriptor = "Lcom/reactnativejsicpr/HttpHelper;";

  static jni::local_ref<jhybriddata> initHybrid(
      jni::alias_ref<jhybridobject> jThis,
      jlong jsContext,
      jni::alias_ref<react::CallInvokerHolder::javaobject> jsCallInvokerHolder);

  static void registerNatives();

  void installJSIBindings(jni::alias_ref<jni::JString> certPath);

 private:
  friend HybridBase;

  HttpHelper(
      jsi::Runtime* runtime,
      std::shared_ptr<react::CallInvoker> jsCallInvoker);

  std::unique_ptr<jsiHttp::JsiHttp> http_;
  jsi::Runtime* runtime_;
  std::shared_ptr<react::CallInvoker> jsCallInvoker_;
};

} // namespace reactnativejsicpr
