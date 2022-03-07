// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.h"

#include "Constants.h"
using namespace IntakeConstants;

IntakeSubsystem::IntakeSubsystem() 
  : m_intake{intakePort, rev::CANSparkMax::MotorType::kBrushless} {
  m_intake.RestoreFactoryDefaults();
}

void IntakeSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void IntakeSubsystem::SetSpeed(double speed) {
  m_intake.Set(speed);
}