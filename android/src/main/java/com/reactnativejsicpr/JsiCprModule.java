package com.reactnativejsicpr;

import android.util.Log;

import com.facebook.fbreact.specs.NativeJsiCprSpec;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = JsiCprModule.NAME)
public class JsiCprModule extends NativeJsiCprSpec {
  public static final String NAME = NativeJsiCprSpec.NAME;

  private HttpHelper httpHelper;

  public JsiCprModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  public boolean install() {
    try {
      System.loadLibrary("react-native-jsi-cpr");
      httpHelper = new HttpHelper();
      boolean installed = httpHelper.install(getReactApplicationContext());
      if (!installed) {
        Log.e(NAME, "JSI runtime or CallInvoker is unavailable");
      }
      return installed;
    } catch (Throwable error) {
      Log.e(NAME, "Failed to install JSI bindings", error);
      return false;
    }
  }
}
