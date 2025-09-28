#pragma once

#include "config.h"
#include "IPlug_include_in_plug_hdr.h"
#include "IControls.h"

// ---- Parameter IDs ----
enum EParams {
  kInTrim = 0,
  kGateThresh,
  kGateRelease,
  kPreHP,
  kPreLP,
  kTilt,
  kOversampling,       // 0=1x, 1=2x, 2=4x
  kAccuracyLatency,    // 0=Accuracy, 1=Latency

  // IR loader
  kIRSlot,             // 0=A, 1=B
  kIRLock,             // 0=Off, 1=On
  kIRMix,              // 0..100 %
  kIRPhaseInv,         // 0=Off, 1=On
  kIRHP,
  kIRLP,

  // Post-EQ
  kEqLowGain,          // dB
  kEqMidGain,          // dB
  kEqMidQ,             // Q
  kEqHighGain,         // dB

  // Output
  kOutLevel,           // dB

  // Parametric amp knobs — hidden unless model supports
  kAmpGain,
  kAmpBass,
  kAmpMid,
  kAmpTreble,
  kAmpPresence,
  kAmpMaster,

  kNumParams           // keep last
};

// Forward declare
class NeuralAmpModeler final : public IPlug {
public:
  NeuralAmpModeler(const InstanceInfo& info);

  void OnIdle() override;
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
  void OnReset() override;
};
