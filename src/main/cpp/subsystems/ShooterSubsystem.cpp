// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"
using namespace ShooterConstants;

ShooterSubsystem::ShooterSubsystem() 
  : m_shooter{shooterPort, rev::CANSparkMax::MotorType::kBrushless} {
  m_shooter.RestoreFactoryDefaults();
  m_shooter.SetInverted(true);
}

void ShooterSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ShooterSubsystem::SetSpeed(double speed) {
  m_shooter.Set(speed);
}