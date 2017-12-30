// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 01 Instance and Devices
// Recipe:  14 Selecting index of a queue family with desired capabilities

#include "01 Instance and Devices/13 Checking available queue families and their properties.h"
#include "01 Instance and Devices/14 Selecting index of a queue family with desired capabilities.h"

namespace VulkanCookbook {

  bool SelectIndexOfQueueFamilyWithDesiredCapabilities( VkPhysicalDevice   physical_device,
                                                        VkQueueFlags       desired_capabilities,
                                                        uint32_t         & queue_family_index ) {
    std::vector<VkQueueFamilyProperties> queue_families;
    if( !CheckAvailableQueueFamiliesAndTheirProperties( physical_device, queue_families ) ) {
      return false;
    }

    for( uint32_t index = 0; index < static_cast<uint32_t>(queue_families.size()); ++index ) {
      if( (queue_families[index].queueCount > 0) &&
          ((queue_families[index].queueFlags & desired_capabilities) == desired_capabilities) ) {
        queue_family_index = index;
        return true;
      }
    }
    return false;
  }

} // namespace VulkanCookbook
