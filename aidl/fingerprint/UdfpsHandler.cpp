#include "UdfpsHandler.h"
#include <fstream>
#include <string>
#include <android-base/logging.h>
#include <fingerprint.sysprop.h>

using namespace ::android::fingerprint::samsung;

namespace aidl {
namespace android {
namespace hardware {
namespace biometrics {
namespace fingerprint {

template <typename T>
static void UdfpsHandler::set(const std::string& path, const T& value) {
    std::ofstream file(path);
    if (!file) {
        LOG(ERROR) << "Failed to open file at path: " << path << ";";
        return;
    }
    file << value << std::endl;
    if (!file) {
        LOG(ERROR) << "Failed to write value: " << value << " to path: " << path;
    }
}

void UdfpsHandler::enableFodPress() {
    LOG(INFO) << "Enabling FOD press.";
    set(TSP_CMD, "fod_enable,1,1,0");
}

void UdfpsHandler::disableFodPress() {
    LOG(INFO) << "Disabling FOD press.";
    set(TSP_CMD, "fod_enable,0,0,0");
}

void UdfpsHandler::setFodRect() {
    std::string fod_rect = FingerprintHalProperties::rectangular_sensor_location().value_or("");
    if (!fod_rect.empty()) {
        LOG(INFO) << "Sending set_fod_rect, " << fod_rect << " command to Touch CMD ";
        set(TSP_CMD, "set_fod_rect," + fod_rect);
    }
    else
        LOG(INFO) << "FOD rectangle is not defined. Skip sending set_fod_rect command"; 
}

}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace android
}  // namespace aidl
