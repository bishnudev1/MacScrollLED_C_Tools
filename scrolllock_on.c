
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDManager.h>
#include <stdio.h>

void setScrollLock(IOHIDDeviceRef device, bool on) {
    uint8_t reportID = 0;
    uint8_t report[2];
    report[0] = on ? 0x04 : 0x00; // Bit 2 = Scroll Lock

    IOReturn tIOReturn = IOHIDDeviceSetReport(device, kIOHIDReportTypeOutput, reportID, report, sizeof(report));
    if (tIOReturn != kIOReturnSuccess) {
        printf("Failed to set Scroll Lock LED\n");
    } else {
        printf("Scroll Lock LED turned %s.\n", on ? "ON" : "OFF");
    }
}

int main(void) {
    IOHIDManagerRef manager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
    if (!manager) return -1;

    IOHIDManagerSetDeviceMatching(manager, NULL);
    IOHIDManagerOpen(manager, kIOHIDOptionsTypeNone);
    CFSetRef deviceSet = IOHIDManagerCopyDevices(manager);
    if (!deviceSet) return -1;

    CFIndex count = CFSetGetCount(deviceSet);
    IOHIDDeviceRef *devices = malloc(sizeof(IOHIDDeviceRef) * count);
    CFSetGetValues(deviceSet, (const void **)devices);

    for (CFIndex i = 0; i < count; i++) {
        setScrollLock(devices[i], true);  // Turn ON
    }

    free(devices);
    CFRelease(deviceSet);
    CFRelease(manager);
    return 0;
}
