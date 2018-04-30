#include "Marker.h"

Marker::Marker() {
  bits = 0;
}

void Marker::set_marker(tmark marker, tcolor col) {
  bits = (col.color == 0) ? marker.mark : (marker.mark << 6);
}

void Marker::clear_marker(tmark mark, tcolor col) {
  if (col.color == 0) {
    /* clear lower 6 bits */
    bits &= ~0x3F;
  } else {
    /* clear bits 6-12 */
    bits &= ~0xFC0;
  }
}

bool Marker::check_marker(tmark mark, tcolor col) {
  int mask = (col.color == 0) ? mark.mark : (mark.mark << 6);
  return ((mask & bits) == mask);
}

bool Marker::check_other_marker(tcolor col) {
  int mask = (col.color == 0) ? 0x3F : 0xFC0;
  return (mask & bits);
}
