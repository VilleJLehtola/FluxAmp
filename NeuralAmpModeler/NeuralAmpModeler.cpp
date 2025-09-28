#include "NeuralAmpModeler.h"
#include "IPlug_include_in_plug_src.h"

NeuralAmpModeler::NeuralAmpModeler(const InstanceInfo& info)
: IPlug(info, kNumParams, 0) // no presets yet
{
  // ---------- Core / Input ----------
  GetParam(kInTrim)->InitDouble("Input Trim", 0.0, -24.0, 24.0, 0.1, "dB");

  GetParam(kGateThresh)->InitDouble("Gate Threshold", -60.0, -80.0, 0.0, 0.1, "dB");
  GetParam(kGateRelease)->InitDouble("Gate Release", 150.0, 10.0, 2000.0, 1.0, "ms");

  GetParam(kPreHP)->InitDouble("Pre HP", 60.0, 20.0, 200.0, 1.0, "Hz");
  GetParam(kPreLP)->InitDouble("Pre LP", 12000.0, 6000.0, 20000.0, 10.0, "Hz");
  GetParam(kTilt)->InitDouble("Tilt EQ", 0.0, -6.0, 6.0, 0.1, "dB");

  GetParam(kOversampling)->InitEnum("Oversampling", 0, { "1x", "2x", "4x" });
  GetParam(kAccuracyLatency)->InitEnum("Quality Mode", 0, { "Accuracy", "Latency" });

  // ---------- IR Loader ----------
  GetParam(kIRSlot)->InitEnum("IR Slot", 0, { "A", "B" });
  GetParam(kIRLock)->InitEnum("IR Lock", 1, { "Off", "On" });
  GetParam(kIRMix)->InitDouble("IR Mix", 100.0, 0.0, 100.0, 1.0, "%");
  GetParam(kIRPhaseInv)->InitEnum("IR Phase", 0, { "Normal", "Invert" });
  GetParam(kIRHP)->InitDouble("IR HP", 80.0, 20.0, 200.0, 1.0, "Hz");
  GetParam(kIRLP)->InitDouble("IR LP", 12000.0, 6000.0, 20000.0, 10.0, "Hz");

  // ---------- Post EQ ----------
  GetParam(kEqLowGain)->InitDouble("Low Shelf", 0.0, -12.0, 12.0, 0.1, "dB");
  GetParam(kEqMidGain)->InitDouble("Mid Gain", 0.0, -12.0, 12.0, 0.1, "dB");
  GetParam(kEqMidQ)->InitDouble("Mid Q", 0.7, 0.3, 3.0, 0.01, "");
  GetParam(kEqHighGain)->InitDouble("High Shelf", 0.0, -12.0, 12.0, 0.1, "dB");

  // ---------- Output ----------
  GetParam(kOutLevel)->InitDouble("Output Level", 0.0, -24.0, 24.0, 0.1, "dB");

  // ---------- Parametric knobs (hidden by default) ----------
  GetParam(kAmpGain)->InitDouble("Gain", 0.6, 0.0, 1.0, 0.01, "");
  GetParam(kAmpBass)->InitDouble("Bass", 0.5, 0.0, 1.0, 0.01, "");
  GetParam(kAmpMid)->InitDouble("Mid", 0.5, 0.0, 1.0, 0.01, "");
  GetParam(kAmpTreble)->InitDouble("Treble", 0.5, 0.0, 1.0, 0.01, "");
  GetParam(kAmpPresence)->InitDouble("Presence", 0.5, 0.0, 1.0, 0.01, "");
  GetParam(kAmpMaster)->InitDouble("Master", 0.6, 0.0, 1.0, 0.01, "");

  // (Optional) Disable automation for parametric knobs until supported
  // for (int p = kAmpGain; p <= kAmpMaster; ++p) GetParam(p)->SetCanAutomate(false);
}

void NeuralAmpModeler::OnIdle()
{
  // future: GUI updates, meters, etc.
}

void NeuralAmpModeler::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{
  // TODO: DSP path will go here
  for (int s = 0; s < nFrames; ++s) {
    outputs[0][s] = inputs[0][s];
    if (NOutChans() > 1)
      outputs[1][s] = inputs[1][s];
  }
}

void NeuralAmpModeler::OnReset()
{
  // TODO: handle sample rate / block size changes
}
