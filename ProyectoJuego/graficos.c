/*
 * Convertidor de imagen a hex R5G6B5 online: https://lvgl.io/tools/imageconverter
 * 1. Cargar imagen de 320x240px
 * 2. Color format: True color
 * 3. Output format: C array
 * 4. Extraer values del array LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
 * 5. Crear variable: const unsigned char imgName [] PROGMEM ={values};
 */
#include <avr/pgmspace.h> 

const unsigned char cowboysp [] PROGMEM ={
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x28, 0x00, 0xcb, 0x87, 0xdb, 0x03, 0xe3, 0x02, 0xe3, 0x02, 0xe3, 0x43, 0xda, 0xe0, 0xd3, 0x23, 0xc3, 0x48, 0x28, 0x00, 0x10, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0x18, 0x00, 0xcb, 0x47, 0xe2, 0xe3, 0xe2, 0xc2, 0xf2, 0xe3, 0xea, 0xc2, 0xea, 0xe2, 0xe2, 0xe1, 0xc3, 0x04, 0x20, 0x00, 0x08, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x21, 0x18, 0x00, 0xca, 0xe4, 0xf3, 0x03, 0xe2, 0xa3, 0xe2, 0xc4, 0xea, 0xc2, 0xea, 0xc2, 0xea, 0xe2, 0xcb, 0x05, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0xcb, 0x25, 0xe3, 0x22, 0xda, 0xe0, 0xe2, 0xe1, 0xea, 0xe3, 0xe2, 0xa3, 0xea, 0xe1, 0xcb, 0x44, 0x10, 0x00, 0x00, 0x01, 
  0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0x18, 0x00, 0x30, 0x00, 0xc3, 0x45, 0xca, 0xe2, 0xdb, 0x23, 0xdb, 0x23, 0xca, 0xc2, 0xd3, 0x02, 0xd3, 0x44, 0xc3, 0x28, 0x30, 0x00, 0x10, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x10, 0x20, 0x20, 0x00, 0xc3, 0x46, 0xdb, 0x24, 0xe3, 0x04, 0xda, 0xc2, 0xe3, 0x03, 0xda, 0xe2, 0xd3, 0x03, 0xcb, 0x66, 0x20, 0x00, 0x10, 0x00, 0x08, 0x00, 0x10, 0x01, 0x08, 0x00, 0x18, 0x00, 0xd3, 0x66, 0xda, 0xe3, 0xdb, 0x04, 0xdb, 0x05, 0xe3, 0x03, 0xe3, 0x03, 0xda, 0xc3, 0xd3, 0x67, 0x20, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x20, 0x00, 0xcb, 0x86, 0xd2, 0xe1, 0xdb, 0x01, 0xeb, 0x43, 0xe2, 0xe4, 0xe2, 0xe4, 0xdb, 0x03, 0xc3, 0x25, 0x20, 0x00, 0x10, 0x20, 
  0x00, 0x01, 0x08, 0x20, 0x10, 0x00, 0x93, 0x8a, 0xb3, 0x68, 0xbb, 0x25, 0xcb, 0x85, 0xc3, 0x64, 0xc3, 0x44, 0xcb, 0x65, 0xcb, 0x45, 0xcb, 0x46, 0xba, 0xe7, 0xab, 0x4a, 0x9b, 0xac, 0x08, 0x00, 0x00, 0x21, 0x00, 0x01, 0x00, 0x01, 0x08, 0x00, 0x93, 0x8a, 0xab, 0x87, 0xc3, 0x85, 0xc3, 0x44, 0xc3, 0x04, 0xd3, 0x66, 0xd3, 0x24, 0xcb, 0x24, 0xc3, 0x66, 0xab, 0x26, 0xab, 0x89, 0xa3, 0xac, 0x10, 0x00, 0x10, 0x00, 0x9b, 0xab, 0xab, 0x67, 0xc3, 0x85, 0xc3, 0x43, 0xc3, 0x24, 0xc3, 0x45, 0xd3, 0x65, 0xc2, 0xe4, 0xcb, 0x46, 0xcb, 0x68, 0xb3, 0x29, 0xab, 0xac, 0x10, 0x00, 0x08, 0x00, 0x9b, 0xed, 0x9b, 0x49, 0xbb, 0x45, 0xcb, 0x44, 0xcb, 0x23, 0xd3, 0x44, 0xcb, 0x04, 0xcb, 0x25, 0xc3, 0x25, 0xc3, 0xa8, 0xa3, 0x49, 0xa3, 0x6b, 
  0x00, 0x01, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0x30, 0x00, 0xfe, 0xd5, 0xfe, 0xb2, 0xfe, 0xb2, 0xfe, 0x92, 0xfe, 0xd4, 0xfe, 0x94, 0x38, 0x00, 0xfe, 0xb6, 0x30, 0x00, 0x18, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x01, 0x00, 0x02, 0x08, 0x00, 0x20, 0x00, 0x30, 0x00, 0xfe, 0x91, 0xfe, 0xb1, 0xfe, 0xb3, 0xfe, 0x93, 0xfe, 0x92, 0xfe, 0xb3, 0x30, 0x00, 0xff, 0x16, 0x28, 0x00, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0x20, 0x00, 0x28, 0x00, 0xfe, 0xf3, 0xfe, 0xd1, 0xfe, 0xf3, 0xfe, 0xd3, 0xfe, 0x92, 0xfe, 0xd4, 0x30, 0x00, 0xfe, 0x95, 0x30, 0x00, 0x20, 0x00, 0x08, 0x00, 0x08, 0x20, 0x18, 0x00, 0x30, 0x20, 0xfe, 0xd4, 0xfe, 0xb2, 0xfe, 0x71, 0xfe, 0x92, 0xfe, 0x52, 0xfe, 0xf5, 0x30, 0x00, 0xfe, 0xb5, 0x28, 0x00, 0x28, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x08, 0x41, 0x08, 0x00, 0x18, 0x00, 0xfe, 0xb7, 0xfe, 0xb4, 0xfe, 0xf4, 0xff, 0x15, 0xfe, 0xd4, 0xff, 0x16, 0x18, 0x00, 0xff, 0x18, 0x10, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x01, 0x08, 0x00, 0x08, 0x00, 0x10, 0x00, 0xfe, 0xf5, 0xff, 0x15, 0xff, 0x15, 0xfe, 0xd4, 0xff, 0x13, 0xfe, 0xf3, 0x18, 0x00, 0xf6, 0xb7, 0x18, 0x00, 0x10, 0x00, 0x08, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10, 0x00, 0xfe, 0xf6, 0xfe, 0xd4, 0xfe, 0xd3, 0xff, 0x34, 0xff, 0x13, 0xfe, 0xf4, 0x20, 0x00, 0xfe, 0xd7, 0x10, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x18, 0x00, 0xfe, 0xd5, 0xfe, 0xf5, 0xfe, 0xf5, 0xfe, 0xf5, 0xfe, 0xd4, 0xfe, 0xd4, 0x18, 0x00, 0xff, 0x18, 0x10, 0x00, 0x10, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0xfe, 0xd6, 0xff, 0x36, 0xfe, 0xd4, 0xfe, 0xf5, 0xff, 0x56, 0xf7, 0x16, 0xf7, 0x37, 0xe6, 0xf8, 0x00, 0x20, 0x00, 0x20, 0x00, 0x40, 0x00, 0x20, 0x08, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xfe, 0xf4, 0xfe, 0xd3, 0xff, 0x16, 0xfe, 0xf5, 0xff, 0x34, 0xff, 0x34, 0xff, 0x58, 0xf7, 0x19, 0x10, 0x00, 0x08, 0x00, 0x08, 0x21, 0x00, 0x00, 0x08, 0x00, 0x18, 0x00, 0xfe, 0xb6, 0xfe, 0xd4, 0xff, 0x55, 0xff, 0x14, 0xfe, 0xf3, 0xff, 0x35, 0xff, 0x37, 0xef, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0xfe, 0xd6, 0xfe, 0xd5, 0xfe, 0xd6, 0xf6, 0xf6, 0xff, 0x36, 0xfe, 0xf5, 0xee, 0xd6, 0xf7, 0x3a, 0x10, 0x20, 0x08, 0x00, 
  0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x18, 0x00, 0xb3, 0x66, 0xc3, 0x45, 0xfe, 0x92, 0xfe, 0xf4, 0xff, 0x14, 0xf7, 0x15, 0xfe, 0xf6, 0xff, 0x38, 0x00, 0x20, 0x00, 0x20, 0xc5, 0xf6, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x18, 0x00, 0x28, 0x00, 0x28, 0x00, 0xab, 0xc5, 0xbb, 0x83, 0xfe, 0xd1, 0xfe, 0xb4, 0xff, 0x16, 0xff, 0x34, 0xfe, 0xf4, 0xf7, 0x17, 0x08, 0x20, 0x10, 0x00, 0x08, 0x00, 0x00, 0x00, 0x10, 0x20, 0x28, 0x00, 0xbb, 0x89, 0xbb, 0x26, 0xfe, 0x93, 0xfe, 0xd4, 0xff, 0x14, 0xff, 0x34, 0xf6, 0xf4, 0xef, 0x17, 0x00, 0x20, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x20, 0x00, 0xbb, 0x68, 0xfe, 0x93, 0xfe, 0xf5, 0xff, 0x36, 0xfe, 0xf5, 0xff, 0x16, 0xff, 0x38, 0x10, 0x00, 0x08, 0x00, 0x08, 0x00, 
  0xc5, 0xf7, 0x08, 0x00, 0x18, 0x00, 0xab, 0x87, 0xcb, 0x62, 0xfd, 0x28, 0xc3, 0x62, 0xfe, 0xd1, 0xff, 0x12, 0xff, 0x13, 0xff, 0x15, 0x18, 0x00, 0x08, 0x00, 0xbe, 0x37, 0xbd, 0xd6, 0xc6, 0x17, 0x00, 0x20, 0x08, 0x00, 0x28, 0x00, 0xb3, 0x48, 0xb3, 0x64, 0xf5, 0x89, 0xfd, 0x47, 0xc3, 0x81, 0xfe, 0xf2, 0xfe, 0xd2, 0xfe, 0xd2, 0xff, 0x34, 0x18, 0x00, 0x18, 0x00, 0xff, 0x38, 0xfe, 0xd7, 0x18, 0x00, 0x20, 0x00, 0xbb, 0x47, 0xcb, 0x46, 0xc3, 0x26, 0xbb, 0x46, 0xfe, 0xd4, 0xfe, 0xf4, 0xfe, 0xd3, 0xff, 0x36, 0x10, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x08, 0x00, 0x18, 0x00, 0xab, 0x88, 0xc3, 0x25, 0xcb, 0x44, 0xfe, 0xd2, 0xfe, 0xf3, 0xff, 0x35, 0xfe, 0xf6, 0x10, 0x20, 0xc5, 0xb5, 0xc5, 0xf8, 0x08, 0x01, 
  0xc6, 0x16, 0x10, 0x00, 0xab, 0xa9, 0xbb, 0x64, 0xfd, 0x65, 0xfd, 0x43, 0xfe, 0xab, 0xc3, 0xa0, 0xb3, 0xa0, 0xb3, 0xa2, 0xb3, 0x86, 0x28, 0x00, 0xcd, 0xb5, 0xce, 0x18, 0xbd, 0xd7, 0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0xbb, 0x28, 0xcb, 0x05, 0xc3, 0x84, 0xfd, 0x69, 0xf5, 0x46, 0xfe, 0xeb, 0xc3, 0x80, 0xcb, 0xa0, 0xc3, 0x40, 0xbb, 0x43, 0x38, 0x00, 0x30, 0x00, 0xfe, 0x94, 0xfe, 0xb4, 0x30, 0x00, 0xb3, 0x67, 0xd3, 0x45, 0xcb, 0x04, 0xf5, 0x4e, 0xfe, 0xb5, 0xab, 0x68, 0xbb, 0x67, 0xcb, 0x25, 0xc3, 0x67, 0x18, 0x00, 0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x41, 0x08, 0x00, 0x18, 0x00, 0xb3, 0xc6, 0xd3, 0x42, 0xfc, 0xe7, 0xfd, 0x27, 0xf5, 0x68, 0xab, 0xc5, 0xd5, 0xf1, 0xc6, 0x15, 0xb5, 0xd7, 0xcd, 0xf9, 0x08, 0x01, 
  0x00, 0x00, 0x10, 0x00, 0xfe, 0xb6, 0xfe, 0xd1, 0xfd, 0x63, 0xfd, 0x81, 0xfd, 0xa4, 0xfd, 0x84, 0xfd, 0xc4, 0xfd, 0xa7, 0xab, 0x66, 0xfe, 0xb7, 0xff, 0x1b, 0xcd, 0xb7, 0x00, 0x00, 0x00, 0x20, 0x08, 0x40, 0xfe, 0xf9, 0xfe, 0x75, 0xc3, 0x26, 0x40, 0x00, 0xf5, 0x69, 0xf5, 0xa6, 0xf5, 0x84, 0xfd, 0x83, 0xfd, 0x43, 0xfd, 0x87, 0xcb, 0x83, 0xbb, 0x27, 0xbb, 0x49, 0xbb, 0x88, 0xb3, 0x67, 0x30, 0x00, 0xb3, 0x67, 0xc3, 0x04, 0xc3, 0x45, 0xed, 0xaf, 0xdd, 0xaf, 0xf5, 0xb0, 0xfd, 0x4e, 0xd3, 0x04, 0xc3, 0x05, 0xff, 0x18, 0xf7, 0x3a, 0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0xe5, 0x4a, 0xcb, 0x41, 0xe3, 0x80, 0xd3, 0x20, 0xcb, 0x80, 0xfe, 0xd0, 0xff, 0x15, 0xbe, 0x15, 0x00, 0x41, 0x00, 0x01, 0x08, 0x01, 
  0x00, 0x21, 0x08, 0x00, 0xfe, 0xd8, 0xfe, 0xf3, 0xf5, 0xe5, 0xf5, 0xa1, 0xff, 0x08, 0xf5, 0xa3, 0xed, 0x60, 0xf5, 0xc6, 0x20, 0x00, 0xff, 0x1a, 0xf6, 0xfa, 0x08, 0x00, 0x10, 0x01, 0x08, 0x00, 0x00, 0x00, 0xef, 0x39, 0xfe, 0xf8, 0xe5, 0xb1, 0x30, 0x00, 0xed, 0x69, 0xf5, 0xc6, 0xff, 0x29, 0xf5, 0xc2, 0xed, 0xa3, 0xed, 0xa7, 0x30, 0x00, 0xb3, 0x47, 0xb3, 0x6a, 0xab, 0xab, 0x20, 0x00, 0x10, 0x00, 0x18, 0x00, 0xab, 0x89, 0xfe, 0xf4, 0xff, 0x33, 0xde, 0x0e, 0xe5, 0xee, 0xf5, 0x8d, 0xc3, 0x43, 0xcb, 0xc6, 0xfe, 0xd5, 0xe6, 0xd8, 0x10, 0x41, 0x00, 0x01, 0x08, 0x21, 0x08, 0x00, 0x18, 0x00, 0xed, 0xac, 0xbb, 0x41, 0xd3, 0x60, 0xd3, 0x60, 0xcb, 0x80, 0xff, 0x32, 0xf7, 0x15, 0x00, 0x20, 0x00, 0x20, 0x00, 0x21, 0x00, 0x01, 
  0x00, 0x01, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0xdd, 0xa9, 0xee, 0x07, 0xe5, 0xe8, 0xe5, 0xe8, 0xed, 0xe7, 0xe5, 0xca, 0x18, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x10, 0x01, 0x08, 0x00, 0x00, 0x20, 0x00, 0x20, 0xcd, 0xf5, 0xcd, 0xb3, 0xe5, 0xf1, 0xdd, 0xad, 0xd5, 0x68, 0xe5, 0xc8, 0xed, 0xe7, 0xdd, 0xc7, 0xdd, 0xec, 0x20, 0x00, 0x30, 0x00, 0x28, 0x00, 0x18, 0x00, 0x10, 0x00, 0x08, 0x00, 0x08, 0x00, 0x10, 0x00, 0xf6, 0xd6, 0xff, 0x75, 0xcd, 0xad, 0xcd, 0x8e, 0xdd, 0x8f, 0xe5, 0x2d, 0x28, 0x00, 0x10, 0x00, 0x08, 0x20, 0x08, 0x21, 0x00, 0x01, 0x10, 0x00, 0x18, 0x00, 0x20, 0x00, 0xdd, 0x8d, 0xed, 0x8c, 0xfd, 0x8b, 0xfd, 0x49, 0xf5, 0x6b, 0xdd, 0x6d, 0x18, 0x00, 0x00, 0x20, 0x00, 0x40, 0x00, 0x21, 0x00, 0x01, 
  0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0x18, 0x00, 0x10, 0x20, 0x08, 0x20, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x18, 0x00, 0x10, 0x00, 0x08, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0xcd, 0xb5, 0xc6, 0x16, 0xc6, 0x15, 0x10, 0x40, 0x10, 0x00, 0x20, 0x00, 0x18, 0x00, 0x10, 0x00, 0x08, 0x00, 0x10, 0x00, 0x10, 0x00, 0x08, 0x00, 0x08, 0x41, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x10, 0x00, 0x08, 0x00, 0x10, 0x20, 0x00, 0x00, 0x10, 0x00, 0x28, 0x00, 0xa3, 0x8b, 0x9b, 0x8a, 0x20, 0x00, 0x18, 0x00, 0x18, 0x00, 0x20, 0x00, 0x18, 0x00, 0x20, 0x00, 0x18, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x20, 0x08, 0x00, 0xa3, 0x6a, 0x30, 0x00, 0x18, 0x00, 0x10, 0x00, 0x10, 0x40, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0x28, 0x00, 0xa3, 0x6a, 0x10, 0x20, 0x00, 0x20, 0x00, 0x40, 0x00, 0x20, 0x00, 0x41, 0x00, 0x00, 0x18, 0x00, 0x9b, 0xce, 0xb5, 0xd7, 0x00, 0x41, 0x00, 0x20, 0x08, 0x00, 0x18, 0x00, 0xa3, 0xcd, 0x18, 0x00, 0x18, 0x00, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x41, 0x00, 0x21, 0x00, 0x00, 0xa3, 0x6b, 0x30, 0x00, 0x18, 0x00, 0x10, 0x00, 0x08, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x10, 0x00, 0x28, 0x00, 0xab, 0x6a, 0x18, 0x00, 0x10, 0x00, 0x10, 0x20, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x28, 0x00, 0xab, 0x8c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x18, 0x00, 0xc3, 0x47, 0xd3, 0x24, 0xcb, 0x04, 0xbb, 0x88, 0x18, 0x00, 0x18, 0x00, 0xb3, 0x28, 0xd3, 0x47, 0xd2, 0xc5, 0xc3, 0x48, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x28, 0x00, 0xab, 0xac, 0x08, 0x00, 0x00, 0x00, 0x00, 0x20, 0x08, 0x00, 0x28, 0x00, 0xab, 0x29, 0xc3, 0x27, 0xbb, 0x48, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0x08, 0x00, 0x08, 0x00, 0x00, 0x21, 0x10, 0x00, 0xbb, 0x28, 0xcb, 0x07, 0xb3, 0x69, 0x20, 0x00, 0x08, 0x20, 0x00, 0x40, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x08, 0x00, 0x28, 0x00, 0xab, 0x8a, 0x18, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0xbb, 0xa9, 0xcb, 0x06, 0xbb, 0x07, 0x10, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 
};