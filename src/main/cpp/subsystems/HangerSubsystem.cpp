// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/HangerSubsystem.h"

#include "Constants.h"
using namespace HangerConstants;

HangerSubsystem::HangerSubsystem()
  : m_right{rightPort, rev::CANSparkMax::MotorType::kBrushless},
    m_left{leftPort, rev::CANSparkMax::MotorType::kBrushless}{
  m_right.RestoreFactoryDefaults();
  m_left.RestoreFactoryDefaults();
  m_right.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_left.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_left.SetInverted(true);
}

void HangerSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void HangerSubsystem::SetSpeed(double speed) {
  m_left.Set(speed);
  m_right.Set(speed);
}