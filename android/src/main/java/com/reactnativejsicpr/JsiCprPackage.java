package com.reactnativejsicpr;

import com.facebook.react.BaseReactPackage;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.module.model.ReactModuleInfo;
import com.facebook.react.module.model.ReactModuleInfoProvider;

import java.util.HashMap;
import java.util.Map;

public class JsiCprPackage extends BaseReactPackage {
  @Override
  public NativeModule getModule(String name, ReactApplicationContext reactContext) {
    if (JsiCprModule.NAME.equals(name)) {
      return new JsiCprModule(reactContext);
    }
    return null;
  }

  @Override
  public ReactModuleInfoProvider getReactModuleInfoProvider() {
    return () -> {
      Map<String, ReactModuleInfo> moduleInfos = new HashMap<>();
      moduleInfos.put(
          JsiCprModule.NAME,
          new ReactModuleInfo(
              JsiCprModule.NAME,
              JsiCprModule.NAME,
              false,
              false,
              false,
              true));
      return moduleInfos;
    };
  }
}
