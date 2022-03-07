// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

#include "Constants.h"
using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
  : m_left1{leftPorts[0]},
    m_left2{leftPorts[1]},
    m_right1{rightPorts[0]},
    m_right2{rightPorts[1]} {
  m_left2.SetInverted(true);
  m_right.SetInverted(true);
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::TankDrive(double lStick, double rStick) {
  m_drive.TankDrive(m_maxOutput * lStick, m_maxOutput * rStick);
}

void DriveSubsystem::ArcadeDrive(double speed, double angle) {
  m_drive.TankDrive(m_maxOutput * speed, angle);
}

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_maxOutput = maxOutput;
}
