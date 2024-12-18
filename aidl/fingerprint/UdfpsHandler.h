/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

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
    static constexpr const char* TSP_CMD = "/sys/class/sec/tsp/cmd";
    static constexpr const char* TSP_CMD_LIST = "/sys/class/sec/tsp/cmd_list";
};

} // namespace fingerprint
} // namespace biometrics
} // namespace hardware
} // namespace android
} // namespace aidl
