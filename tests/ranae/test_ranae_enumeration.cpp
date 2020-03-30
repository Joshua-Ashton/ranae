#include "test_common.h"

#include <vulkan/vulkan.h>

#include <vector>

namespace ranae {
  Logger Logger::s_instance("enumeration.log");

  void runTest(int argc, char** argv) {
    VkApplicationInfo appInfo = { };
    appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext              = nullptr;
    appInfo.pApplicationName   = "Ranae Enumeration Test";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName        = "Ranae Test";
    appInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion         = VK_VERSION_1_1;

    VkInstanceCreateInfo info = { };
    info.sType            = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    info.pNext            = nullptr;
    info.flags            = 0;
    info.pApplicationInfo = &appInfo;

    VkInstance instance = {};
    check(vkCreateInstance(&info, nullptr, &instance));
    defer(vkDestroyInstance(instance, nullptr));

    uint32_t count = 0;
    check(vkEnumeratePhysicalDevices(instance, &count, nullptr));

    Logger::info(str::format("Found ", count, " physical devices..."));

    std::vector<VkPhysicalDevice> physicalDevices(count);
    check(vkEnumeratePhysicalDevices(instance, &count, physicalDevices.data()));

    for (size_t i = 0; i < physicalDevices.size(); i++) {
      VkPhysicalDevice physicalDevice = physicalDevices[i];

      VkPhysicalDeviceProperties properties;
      vkGetPhysicalDeviceProperties(physicalDevice, &properties);

      Logger::info(str::format(
        "Found physical device ", i, "\n",
        " - apiVersion:    ", properties.apiVersion,         "\n",
        " - driverVersion: ", properties.driverVersion,      "\n",
        " - vendorID:      ", std::hex, properties.vendorID, "\n",
        " - deviceID:      ", std::hex, properties.deviceID, "\n",
        " - deviceType:    ", properties.deviceType,         "\n",
        " - deviceName:    ", properties.deviceName,         "\n"));
    }
  }
}

int main(int argc, char** argv) {
  ranae::runTest(argc, argv);
  return 1;
}