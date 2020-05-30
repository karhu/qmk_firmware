#pragma once

// Configure how the hardware distinguishes between Left and Right half.
// We use the eeprom? so we can flash both halfs with the same firmware
// and connect using either USB.
////////////////////////////////////////////////////////////////////////////////////////////////////

//  #define MASTER_LEFT
//  #define MASTER_RIGHT
#define EE_HANDS

// Limit max RGB LED current to avoid tripping controller fuse.
////////////////////////////////////////////////////////////////////////////////////////////////////

#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define DISABLE_RGB_MATRIX_SOLID_COLOR                  // Static single hue, no speed support
#define DISABLE_RGB_MATRIX_ALPHAS_MODS                  // Static dual hue, speed is hue for secondary hue
// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN             // Static gradient top to bottom, speed controls how much gradient changes
// #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT          // Static gradient left to right, speed controls how much gradient changes
// #define DISABLE_RGB_MATRIX_BREATHING                    // Single hue brightness cycling animation
#define DISABLE_RGB_MATRIX_BAND_SAT                     // Single hue band fading saturation scrolling left to right
#define DISABLE_RGB_MATRIX_BAND_VAL                     // Single hue band fading brightness scrolling left to right
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT            // Single hue 3 blade spinning pinwheel fades saturation
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL            // Single hue 3 blade spinning pinwheel fades brightness
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT              // Single hue spinning spiral fades saturation
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL              // Single hue spinning spiral fades brightness
// #define DISABLE_RGB_MATRIX_CYCLE_ALL                    // Full keyboard solid hue cycling through full gradient
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT             // Full gradient scrolling left to right
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN                // Full gradient scrolling top to bottom
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN                 // Full gradient scrolling out to in
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL            // Full dual gradients scrolling out to in
// #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON       // Full gradient Chevron shapped scrolling left to right
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL               // Full gradient spinning pinwheel around center of keyboard
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL                 // Full gradient spinning spiral around center of keyboard
#define DISABLE_RGB_MATRIX_DUAL_BEACON                  // Full gradient spinning around center of keyboard
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON               // Full tighter gradient spinning around center of keyboard
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS            // Full dual gradients spinning two halfs of keyboard
// #define DISABLE_RGB_MATRIX_RAINDROPS                    // Randomly changes a single key's hue
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS          // Randomly changes a single key's hue and saturation
// #define DISABLE_RGB_MATRIX_TYPING_HEATMAP               // How hot is your WPM!
// #define DISABLE_RGB_MATRIX_DIGITAL_RAIN                 // That famous computer simulation
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE        // Pulses keys hit to hue & value then fades value out
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE               // Static single hue, pulses keys hit to shifted hue then fades to current hue
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE          // Hue & value pulse near a single key hit then fades value out
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE     // Hue & value pulse near multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS         // Hue & value pulse the same column and row of a single key hit then fades value out
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS    // Hue & value pulse the same column and row of multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS         // Hue & value pulse away on the same column and row of a single key hit then fades value out
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS    // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SPLASH                       // Full gradient & value pulse away from a single key hit then fades value out
// #define DISABLE_RGB_MATRIX_MULTISPLASH                  // Full gradient & value pulse away from multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_SPLASH                 // Hue & value pulse away from a single key hit then fades value out
// #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH            // Hue & value pulse away from multiple key hits then fades value out

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define RGB_MATRIX_STARTUP_HUE 0
#define RGB_MATRIX_STARTUP_SAT 255
#define RGB_MATRIX_STARTUP_SPD 127
#define RGB_MATRIX_STARTUP_VAL 150
