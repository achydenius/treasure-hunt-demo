char map[21][32] = {
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x13, 0x14, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x15, 0x00, 0x00 },
  { 0x15, 0x00, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00, 0x00, 0x00, 0x00, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00, 0x11, 0x12, 0x00 },
  { 0x15, 0x00, 0x08, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x08, 0x09, 0x09, 0x09, 0x09, 0x08, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x08, 0x00, 0x31, 0x32, 0x00 },
  { 0x00, 0x00, 0x08, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x0c, 0x09, 0x09, 0x09, 0x09, 0x0c, 0x2a, 0x2b, 0x2a, 0x05, 0x06, 0x2b, 0x2a, 0x2b, 0x08, 0x00, 0x51, 0x52, 0x00 },
  { 0x00, 0x00, 0x08, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x2c, 0x0a, 0x0b, 0x0a, 0x0b, 0x2c, 0x0a, 0x0b, 0x0a, 0x25, 0x26, 0x0b, 0x0a, 0x0b, 0x08, 0x00, 0x71, 0x72, 0x00 },
  { 0x00, 0x00, 0x08, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x08, 0x2a, 0x2b, 0x2a, 0x2b, 0x08, 0x2a, 0x2b, 0x2a, 0x45, 0x46, 0x2b, 0x2a, 0x2b, 0x08, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x08, 0x0a, 0x0b, 0x07, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x08, 0x00, 0x00, 0x13, 0x14 },
  { 0x00, 0x00, 0x08, 0x2a, 0x2b, 0x2a, 0x07, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x08, 0x09, 0x09, 0x09, 0x09, 0x08, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x08, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x08, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x08, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x15, 0x00, 0x00 },
  { 0x15, 0x00, 0x08, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x0d, 0x0e, 0x0f, 0x10, 0x08, 0x08, 0x08, 0x08, 0x00, 0x11, 0x12, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x15, 0x00 },
  { 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x2d, 0x2e, 0x2f, 0x30, 0x09, 0x09, 0x09, 0x09, 0x00, 0x31, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x4d, 0x4e, 0x4f, 0x50, 0x09, 0x09, 0x09, 0x09, 0x00, 0x51, 0x52, 0x00, 0x13, 0x14, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08 },
  { 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x19, 0x18, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 0x72, 0x15, 0x00, 0x00, 0x15, 0x00, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09 },
  { 0x00, 0x00, 0x00, 0x11, 0x12, 0x00, 0x38, 0x39, 0x38, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09 },
  { 0x00, 0x15, 0x00, 0x31, 0x32, 0x00, 0x18, 0x19, 0x18, 0x19, 0x18, 0x19, 0x18, 0x19, 0x18, 0x19, 0x18, 0x19, 0x18, 0x19, 0x18, 0x19, 0x0c, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a },
  { 0x00, 0x00, 0x00, 0x51, 0x52, 0x00, 0x38, 0x39, 0x38, 0x39, 0x38, 0x39, 0x38, 0x39, 0x38, 0x39, 0x38, 0x39, 0x38, 0x39, 0x38, 0x39, 0x2c, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a },
  { 0x00, 0x13, 0x14, 0x71, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a, 0x0b, 0x0a },
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a, 0x2b, 0x2a }
};