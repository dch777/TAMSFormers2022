// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntestineSubsystem.h"

#include "Constants.h"
using namespace IntestineConstants;

IntestineSubsystem::IntestineSubsystem()
  : m_belt1{intestinePorts[0]},
    m_belt2{intestinePorts[1]} {
  m_belt1.SetInverted(true);
}

void IntestineSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void IntestineSubsystem::SetSpeed(double speed) {
  m_belt1.Set(ControlMode::PercentOutput, speed);
  m_belt2.Set(ControlMode::PercentOutput, speed);
}

void IntestineSubsystem::SetLowerBeltSpeed(double speed) {
  m_belt1.Set(ControlMode::PercentOutput, speed);
}

void IntestineSubsystem::SetUpperBeltSpeed(double speed) {
  m_belt2.Set(ControlMode::PercentOutput, speed);
}