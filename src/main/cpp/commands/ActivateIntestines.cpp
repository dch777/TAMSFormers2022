// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ActivateIntestines.h"

#include "Constants.h"
using namespace IntestineConstants;

ActivateIntestines::ActivateIntestines(IntestineSubsystem* intestines)
    : m_intestines(intestines) {
  AddRequirements(intestines);
}

void ActivateIntestines::Initialize() {
  m_intestines->SetLowerBeltSpeed(intestineSpeeds[0]);
  m_intestines->SetUpperBeltSpeed(intestineSpeeds[1]);
}

void ActivateIntestines::End(bool interrupted) {
  m_intestines->SetSpeed(0);
}