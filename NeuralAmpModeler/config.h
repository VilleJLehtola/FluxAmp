#pragma once

// ----------------------
// Plugin identification
// ----------------------

#define PLUG_NAME "FluxAmp (dev)"             // Visible name in DAW menus
#define PLUG_MFR "Flux Audio"                 // Visible manufacturer string

#define PLUG_VERSION_HEX 0x00010000           // Version 1.0.0
#define PLUG_VERSION_STR "1.0.0"

// ⚠ Permanent IDs — do not change once published
#define PLUG_UNIQUE_ID 'FxAm'                 // 4-character unique ID
#define PLUG_MFR_ID 'FlxA'                    // 4-character manufacturer ID

// Metadata
#define PLUG_URL_STR "https://example.com/fluxamp"
#define PLUG_EMAIL_STR "support@example.com"
#define PLUG_COPYRIGHT_STR "© 2025 Flux Audio"

// Main plugin class name (leave unless you’re renaming class everywhere)
#define PLUG_CLASS_NAME NeuralAmpModeler

// ----------------------
// Bundle identifiers
// ----------------------

#define BUNDLE_NAME "FluxAmp"
#define BUNDLE_MFR "FluxAudio"                // No spaces
#define BUNDLE_DOMAIN "com"                   // Results in com.FluxAudio.FluxAmp

// Path to shared resources inside bundle
#define SHARED_RESOURCES_SUBPATH "FluxAmp"

// ----------------------
// Plugin features
// ----------------------

#ifdef APP_API
  #define PLUG_CHANNEL_IO "1-2"
#else
  #define PLUG_CHANNEL_IO "1-1 1-2 2-2"
#endif

#define PLUG_LATENCY 0
#define PLUG_TYPE 0                           // Effect
#define PLUG_DOES_MIDI_IN 0
#define PLUG_DOES_MIDI_OUT 0
#define PLUG_DOES_MPE 0
#define PLUG_DOES_STATE_CHUNKS 0
#define PLUG_HAS_UI 1

#define PLUG_WIDTH 600
#define PLUG_HEIGHT 400
#define PLUG_FPS 60
#define PLUG_SHARED_RESOURCES 0
#define PLUG_HOST_RESIZE 0
#define PLUG_MAX_WIDTH PLUG_WIDTH * 4
#define PLUG_MAX_HEIGHT PLUG_HEIGHT * 4

// ----------------------
// AU/AAX identifiers
// ----------------------

#define AUV2_ENTRY NeuralAmpModeler_Entry
#define AUV2_ENTRY_STR "NeuralAmpModeler_Entry"
#define AUV2_FACTORY NeuralAmpModeler_Factory
#define AUV2_VIEW_CLASS NeuralAmpModeler_View
#define AUV2_VIEW_CLASS_STR "NeuralAmpModeler_View"

#define AAX_TYPE_IDS 'FxA1'
#define AAX_TYPE_IDS_AUDIOSUITE 'FxA2'
#define AAX_PLUG_MFR_STR "FluxAudio"
#define AAX_PLUG_NAME_STR "FluxAmp\nIPEF"
#define AAX_PLUG_CATEGORY_STR "Effect"
#define AAX_DOES_AUDIOSUITE 1

// ----------------------
// VST3 identifiers
// ----------------------

#define VST3_SUBCATEGORY "Fx"

// ----------------------
// App standalone settings
// ----------------------

#define APP_NUM_CHANNELS 2
#define APP_N_VECTOR_WAIT 0
