#ifndef AIDL_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_UDFPSHANDLER_H
#define AIDL_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_UDFPSHANDLER_H

#include <string>
#include <android-base/logging.h>

namespace aidl {
namespace android {
namespace hardware {
namespace biometrics {
namespace fingerprint {

class UdfpsHandler {
public:
    void enableFodPress();

    void disableFodPress();

    void setFodRect();

private:
    // Template function to write a value to a file, with logging of success or failure.
    template <typename T>
    void set(const std::string& path, const T& value);

    // Touchscreen CMD path
    static constexpr const char* TSP_CMD = "/sys/class/sec/tsp/cmd";

    // Default error return value
    static constexpr float RETURN_ERROR_F = -1.0f;
};

}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace android
}  // namespace aidl

#endif  // AIDL_ANDROID_HARDWARE_BIOMETRICS_FINGERPRINT_UDFPSHANDLER_H
