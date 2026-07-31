#import <Foundation/Foundation.h>
#import <ReactCommon/CxxTurboModuleUtils.h>

#import "JsiCprImpl.h"

@interface JsiCprOnLoad : NSObject
@end

@implementation JsiCprOnLoad

using namespace facebook::react;

+ (void)load
{
  registerCxxModuleToGlobalModuleMap(
      std::string(JsiCprImpl::kModuleName),
      [](std::shared_ptr<CallInvoker> jsInvoker) {
        return std::make_shared<JsiCprImpl>(std::move(jsInvoker));
      });
}

@end
