// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ActivateIntake.h"

#include "Constants.h"
using namespace IntakeConstants;

ActivateIntake::ActivateIntake(IntakeSubsystem* intake)
    : m_intake(intake) {
  AddRequirements(intake);
}

void ActivateIntake::Initialize() {
  m_intake->SetSpeed(intakeSpeed);
}

void ActivateIntake::End(bool interrupted) {
  m_intake->SetSpeed(0);
}