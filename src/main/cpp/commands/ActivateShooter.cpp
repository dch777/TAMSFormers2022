// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ActivateShooter.h"

#include "Constants.h"
using namespace ShooterConstants;

ActivateShooter::ActivateShooter(ShooterSubsystem* shooter)
    : m_shooter(shooter) {
  AddRequirements(shooter);
}
void ActivateShooter::Initialize() {
  m_shooter->SetSpeed(shooterSpeed);
}

void ActivateShooter::End(bool interrupted) {
  m_shooter->SetSpeed(0);
}