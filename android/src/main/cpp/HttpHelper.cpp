#include "HttpHelper.h"

namespace reactnativejsicpr {

HttpHelper::HttpHelper(
    jsi::Runtime* runtime,
    std::shared_ptr<react::CallInvoker> jsCallInvoker)
    : runtime_(runtime), jsCallInvoker_(std::move(jsCallInvoker)) {}

jni::local_ref<HttpHelper::jhybriddata> HttpHelper::initHybrid(
    jni::alias_ref<jhybridobject>,
    jlong jsContext,
    jni::alias_ref<react::CallInvokerHolder::javaobject> jsCallInvokerHolder) {
  auto runtime = reinterpret_cast<jsi::Runtime*>(jsContext);
  auto jsCallInvoker = jsCallInvokerHolder->cthis()->getCallInvoker();
  return makeCxxInstance(runtime, std::move(jsCallInvoker));
}

void HttpHelper::installJSIBindings(jni::alias_ref<jni::JString> certPath) {
  http_ = std::make_unique<jsiHttp::JsiHttp>(runtime_, jsCallInvoker_);
  http_->installJSIBindings(certPath->toStdString());
}

void HttpHelper::registerNatives() {
  registerHybrid({
      makeNativeMethod("initHybrid", HttpHelper::initHybrid),
      makeNativeMethod("installJSIBindings", HttpHelper::installJSIBindings),
  });
}

} // namespace reactnativejsicpr

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return facebook::jni::initialize(vm, [] {
    reactnativejsicpr::HttpHelper::registerNatives();
  });
}
