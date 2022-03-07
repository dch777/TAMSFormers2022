// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ActivateOuttake.h"

#include "Constants.h"
using namespace IntakeConstants;
using namespace IntestineConstants;

ActivateOuttake::ActivateOuttake(IntakeSubsystem* intake, IntestineSubsystem* intestines)
    : m_intake(intake), m_intestines(intestines) {
  AddRequirements({intake, intestines});
}

void ActivateOuttake::Initialize() {
  m_intake->SetSpeed(-intakeSpeed);
  m_intestines->SetLowerBeltSpeed(-intestineSpeeds[0]);
}

void ActivateOuttake::End(bool interrupted) {
  m_intake->SetSpeed(0);
  m_intestines->SetSpeed(0);
}