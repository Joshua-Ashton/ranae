#include <vulkan/vulkan.h>

#include <vector>

int main(int argc, char** argv) {
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
  VkResult result = vkCreateInstance(&info, nullptr, &instance);

  uint32_t count = 0;
  result = vkEnumeratePhysicalDevices(instance, &count, nullptr);

  std::vector<VkPhysicalDevice> physicalDevices(count);
  result = vkEnumeratePhysicalDevices(instance, &count, physicalDevices.data());

  vkDestroyInstance(instance, nullptr);
}