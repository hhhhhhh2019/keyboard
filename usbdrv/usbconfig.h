#ifndef __usbconfig_h_included__
#define __usbconfig_h_included__


#define USB_CFG_IOPORTNAME      D
#define USB_CFG_DMINUS_BIT      1
#define USB_CFG_DPLUS_BIT       2

#define USB_CFG_CLOCK_KHZ       (F_CPU/1000)






#define USB_CFG_CHECK_CRC       0

#define  USB_CFG_VENDOR_ID       0xc0, 0x16
#define  USB_CFG_DEVICE_ID       0xdc, 0x05

#define USB_CFG_DEVICE_VERSION  0x00, 0x01

#define USB_CFG_VENDOR_NAME     'A', 'l', 'e', 'x'
#define USB_CFG_VENDOR_NAME_LEN 4

#define USB_CFG_DEVICE_NAME     'K', 'e', 'y', 'b', 'o', 'a', 'r', 'd'
#define USB_CFG_DEVICE_NAME_LEN 8

#define USB_CFG_DEVICE_CLASS        0
// 0xff
#define USB_CFG_DEVICE_SUBCLASS     0

#define USB_CFG_INTERFACE_CLASS     3 // hid
// 0
#define USB_CFG_INTERFACE_SUBCLASS  1 // boot
#define USB_CFG_INTERFACE_PROTOCOL  1 // keyboard


#define USB_CFG_HAVE_INTRIN_ENDPOINT    1
#define USB_CFG_INTR_POLL_INTERVAL      10


#define USB_CFG_MAX_BUS_POWER           50
#define USB_CFG_IS_SELF_POWERED         0

#define USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH 45
//63



// #define USB_INTR_CFG            PCMSK2
// #define USB_INTR_CFG_SET        (1 << USB_CFG_DPLUS_BIT)
// #define USB_INTR_CFG_CLR        0
// #define USB_INTR_ENABLE         PCICR
// #define USB_INTR_ENABLE_BIT     PCIE2
// #define USB_INTR_PENDING        PCIFR
// #define USB_INTR_PENDING_BIT    PCIF2


#endif
